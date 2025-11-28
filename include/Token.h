#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    NUMBER,
    VARIABLE,
    OPERATOR,
    FUNCTION,
    LEFT_PAREN,
    RIGHT_PAREN, 
    LEFT_BRACKET,
    RIGHT_BRACKET,
    LEFT_BRACE,
    RIGHT_BRACE,
    ABS
};

struct Token {
    TokenType type;
    std::string value;
    double numericValue;
    
    Token(TokenType t, const std::string& v = "", double num = 0.0);
    std::string toString() const;
};

#endif
