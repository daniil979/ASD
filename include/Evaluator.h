#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Token.h"
#include "MathFunctions.h"
#include <vector>
#include <map>
#include <stack>

class Evaluator {
private:
    std::map<char, double> variables;
    
    double applyOperator(const std::string& op, double a, double b);
    double applyFunction(const std::string& func, double x);
    
public:
    void setVariable(char name, double value);
    double evaluateRPN(const std::vector<Token>& rpnTokens);
};

#endif
