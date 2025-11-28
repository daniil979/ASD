#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include <vector>
#include <string>
#include <stdexcept>

class Parser {
private:
    std::string expression;
    std::vector<Token> tokens;
    
    void tokenize();
    bool isOperator(char c) const;
    bool isFunction(const std::string& str) const;
    int getPrecedence(const std::string& op) const;
    bool isLeftAssociative(const std::string& op) const;
    
public:
    Parser(const std::string& expr);
    std::vector<Token> parseToTokens();
    std::vector<Token> convertToRPN(const std::vector<Token>& inputTokens);
};

#endif
