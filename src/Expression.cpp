#include "../include/Expression.h"

Expression::Expression(const std::string& expr) 
    : expression(expr), parser(expr) {}

void Expression::parse() {
    auto tokens = parser.parseToTokens();
    rpnTokens = parser.convertToRPN(tokens);
}

double Expression::evaluate() {
    return evaluator.evaluateRPN(rpnTokens);
}

void Expression::setVariable(char name, double value) {
    evaluator.setVariable(name, value);
}

std::string Expression::getExpression() const {
    return expression;
}

std::vector<Token> Expression::getRPNTokens() const {
    return rpnTokens;
}

std::vector<Token> Expression::getTokens() const {
    return parser.parseToTokens();
}
