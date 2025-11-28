#include "../include/Token.h"
#include <sstream>

Token::Token(TokenType t, const std::string& v, double num) 
    : type(t), value(v), numericValue(num) {}

std::string Token::toString() const {
    std::stringstream ss;
    ss << "Token{";
    switch(type) {
        case TokenType::NUMBER: ss << "NUMBER"; break;
        case TokenType::VARIABLE: ss << "VARIABLE"; break;
        case TokenType::OPERATOR: ss << "OPERATOR"; break;
        case TokenType::FUNCTION: ss << "FUNCTION"; break;
        case TokenType::LEFT_PAREN: ss << "LEFT_PAREN"; break;
        case TokenType::RIGHT_PAREN: ss << "RIGHT_PAREN"; break;
        case TokenType::LEFT_BRACKET: ss << "LEFT_BRACKET"; break;
        case TokenType::RIGHT_BRACKET: ss << "RIGHT_BRACKET"; break;
        case TokenType::LEFT_BRACE: ss << "LEFT_BRACE"; break;
        case TokenType::RIGHT_BRACE: ss << "RIGHT_BRACE"; break;
        case TokenType::ABS: ss << "ABS"; break;
    }
    ss << ", value='" << value << "', num=" << numericValue << "}";
    return ss.str();
}
