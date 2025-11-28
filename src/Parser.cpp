#include "../include/Parser.h"
#include <cctype>
#include <stack>

Parser::Parser(const std::string& expr) : expression(expr) {}

void Parser::tokenize() {
    tokens.clear();
    std::string currentToken;
    
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (isspace(c)) continue;
        
        if (isalpha(c)) {
            currentToken = c;
            while (i + 1 < expression.length() && isalpha(expression[i + 1])) {
                currentToken += expression[++i];
            }
            
            if (isFunction(currentToken)) {
                tokens.push_back(Token(TokenType::FUNCTION, currentToken));
            } else if (currentToken.length() == 1) {
                tokens.push_back(Token(TokenType::VARIABLE, currentToken));
            } else {
                throw std::runtime_error("error: in parser unknown function '" + currentToken + "'");
            }
        }
        else if (isdigit(c) || c == '.') {
            currentToken = c;
            bool hasDot = (c == '.');
            
            while (i + 1 < expression.length() && 
                   (isdigit(expression[i + 1]) || expression[i + 1] == '.')) {
                if (expression[i + 1] == '.') {
                    if (hasDot) throw std::runtime_error("error: in parser multiple dots in number");
                    hasDot = true;
                }
                currentToken += expression[++i];
            }
            
            tokens.push_back(Token(TokenType::NUMBER, currentToken, std::stod(currentToken)));
        }
        else {
            switch (c) {
                case '(': tokens.push_back(Token(TokenType::LEFT_PAREN, "(")); break;
                case ')': tokens.push_back(Token(TokenType::RIGHT_PAREN, ")")); break;
                case '[': tokens.push_back(Token(TokenType::LEFT_BRACKET, "[")); break;
                case ']': tokens.push_back(Token(TokenType::RIGHT_BRACKET, "]")); break;
                case '{': tokens.push_back(Token(TokenType::LEFT_BRACE, "{")); break;
                case '}': tokens.push_back(Token(TokenType::RIGHT_BRACE, "}")); break;
                case '+': case '-': case '*': case '/': case '^':
                    tokens.push_back(Token(TokenType::OPERATOR, std::string(1, c)));
                    break;
                case '|':
                    if (i + 1 < expression.length() && expression[i + 1] == '|') {
                        tokens.push_back(Token(TokenType::ABS, "||"));
                        i++;
                    } else {
                        throw std::runtime_error("error: in parser single '|' without matching '|'");
                    }
                    break;
                default:
                    throw std::runtime_error("error: in parser unknown character '" + std::string(1, c) + "'");
            }
        }
    }
}

bool Parser::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Parser::isFunction(const std::string& str) const {
    return str == "sin" || str == "cos" || str == "tan";
}

int Parser::getPrecedence(const std::string& op) const {
    if (op == "||") return 4;
    if (op == "^") return 3;
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

bool Parser::isLeftAssociative(const std::string& op) const {
    return op != "^";
}

std::vector<Token> Parser::parseToTokens() {
    tokenize();
    return tokens;
}

std::vector<Token> Parser::convertToRPN(const std::vector<Token>& inputTokens) {
    std::vector<Token> output;
    std::stack<Token> opStack;
    
    for (const auto& token : inputTokens) {
        switch (token.type) {
            case TokenType::NUMBER:
            case TokenType::VARIABLE:
                output.push_back(token);
                break;
                
            case TokenType::FUNCTION:
            case TokenType::LEFT_PAREN:
            case TokenType::LEFT_BRACKET:
            case TokenType::LEFT_BRACE:
                opStack.push(token);
                break;
                
            case TokenType::OPERATOR:
            case TokenType::ABS:
                while (!opStack.empty() &&
                       (opStack.top().type == TokenType::OPERATOR || 
                        opStack.top().type == TokenType::FUNCTION ||
                        opStack.top().type == TokenType::ABS) &&
                       ((getPrecedence(opStack.top().value) > getPrecedence(token.value)) ||
                        (getPrecedence(opStack.top().value) == getPrecedence(token.value) && 
                         isLeftAssociative(token.value)))) {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(token);
                break;
                
            case TokenType::RIGHT_PAREN:
                while (!opStack.empty() && opStack.top().type != TokenType::LEFT_PAREN) {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                if (opStack.empty()) throw std::runtime_error("error: in parser mismatched parentheses");
                opStack.pop();
                break;
                
            case TokenType::RIGHT_BRACKET:
                while (!opStack.empty() && opStack.top().type != TokenType::LEFT_BRACKET) {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                if (opStack.empty()) throw std::runtime_error("error: in parser mismatched brackets");
                opStack.pop();
                break;
                
            case TokenType::RIGHT_BRACE:
                while (!opStack.empty() && opStack.top().type != TokenType::LEFT_BRACE) {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                if (opStack.empty()) throw std::runtime_error("error: in parser mismatched braces");
                opStack.pop();
                break;
        }
    }
    
    while (!opStack.empty()) {
        if (opStack.top().type == TokenType::LEFT_PAREN ||
            opStack.top().type == TokenType::LEFT_BRACKET ||
            opStack.top().type == TokenType::LEFT_BRACE) {
            throw std::runtime_error("error: in parser mismatched brackets/parentheses");
        }
        output.push_back(opStack.top());
        opStack.pop();
    }
    
    return output;
}
