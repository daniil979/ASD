#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Token.h"
#include "Parser.h"
#include "Evaluator.h"
#include <string>
#include <vector>

class Expression {
private:
    std::string expression;
    Parser parser;
    Evaluator evaluator;
    std::vector<Token> rpnTokens;
    
public:
    Expression(const std::string& expr);
    void parse();
    double evaluate();
    void setVariable(char name, double value);
    
    std::string getExpression() const;
    std::vector<Token> getRPNTokens() const;
    std::vector<Token> getTokens() const;
};

#endif
