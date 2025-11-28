#include "../include/Evaluator.h"
#include <cmath>
#include <stdexcept>

void Evaluator::setVariable(char name, double value) {
    variables[name] = value;
}

double Evaluator::applyOperator(const std::string& op, double a, double b) {
    switch (op[0]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("error: in parser division by zero");
            return a / b;
        case '^': return pow(a, b);
        default: throw std::runtime_error("error: in parser unknown operator");
    }
}

double Evaluator::applyFunction(const std::string& func, double x) {
    if (func == "sin") return MathFunctions::sinTaylor(x);
    if (func == "cos") return MathFunctions::cosTaylor(x);
    if (func == "tan") return MathFunctions::tanTaylor(x);
    throw std::runtime_error("error: in parser unknown function");
}

double Evaluator::evaluateRPN(const std::vector<Token>& rpnTokens) {
    std::stack<double> stack;
    
    for (const auto& token : rpnTokens) {
        switch (token.type) {
            case TokenType::NUMBER:
                stack.push(token.numericValue);
                break;
                
            case TokenType::VARIABLE:
                if (variables.find(token.value[0]) == variables.end()) {
                    throw std::runtime_error("error: in parser undefined variable '" + token.value + "'");
                }
                stack.push(variables[token.value[0]]);
                break;
                
            case TokenType::OPERATOR:
                if (stack.size() < 2) {
                    throw std::runtime_error("error: in parser insufficient operands");
                }
                {
                    double b = stack.top(); stack.pop();
                    double a = stack.top(); stack.pop();
                    stack.push(applyOperator(token.value, a, b));
                }
                break;
                
            case TokenType::FUNCTION:
                if (stack.empty()) {
                    throw std::runtime_error("error: in parser insufficient operand for function");
                }
                {
                    double x = stack.top(); stack.pop();
                    stack.push(applyFunction(token.value, x));
                }
                break;
                
            case TokenType::ABS:
                if (stack.empty()) {
                    throw std::runtime_error("error: in parser insufficient operand for abs");
                }
                {
                    double x = stack.top(); stack.pop();
                    stack.push(fabs(x));
                }
                break;
                
            default:
                throw std::runtime_error("error: in parser unknown token type");
        }
    }
    
    if (stack.size() != 1) {
        throw std::runtime_error("error: in parser invalid expression");
    }
    
    return stack.top();
}
