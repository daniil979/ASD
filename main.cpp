#include <iostream>
#include <iomanip>
#include "include/Expression.h"

void printTokens(const std::vector<Token>& tokens) {
    std::cout << "Tokens: ";
    for (const auto& token : tokens) {
        std::cout << token.toString() << " ";
    }
    std::cout << std::endl;
}

void printRPN(const std::vector<Token>& tokens) {
    std::cout << "RPN: ";
    for (const auto& token : tokens) {
        if (token.type == TokenType::NUMBER) {
            std::cout << token.numericValue << " ";
        } else {
            std::cout << token.value << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Expression Parser Demo ===" << std::endl;
    
    try {
        // Пример 1: Простое выражение с переменной
        std::cout << "\n1. Simple expression with variable:" << std::endl;
        Expression expr1("2 + x * 3");
        expr1.setVariable('x', 5.0);
        expr1.parse();
        
        printTokens(expr1.getTokens());
        printRPN(expr1.getRPNTokens());
        std::cout << "Result: " << expr1.evaluate() << std::endl;
        
        // Пример 2: Тригонометрические функции
        std::cout << "\n2. Trigonometric functions:" << std::endl;
        Expression expr2("sin(3.14159/2) + cos(0)");
        expr2.parse();
        
        printTokens(expr2.getTokens());
        printRPN(expr2.getRPNTokens());
        std::cout << "Result: " << std::setprecision(10) << expr2.evaluate() << std::endl;
        
        // Пример 3: Сложное выражение со скобками
        std::cout << "\n3. Complex expression with parentheses:" << std::endl;
        Expression expr3("(2 + x) * (y - 1)");
        expr3.setVariable('x', 3.0);
        expr3.setVariable('y', 5.0);
        expr3.parse();
        
        printTokens(expr3.getTokens());
        printRPN(expr3.getRPNTokens());
        std::cout << "Result: " << expr3.evaluate() << std::endl;
        
        // Пример 4: Модуль и степень
        std::cout << "\n4. Absolute value and power:" << std::endl;
        Expression expr4("||-5|| + 2^3");
        expr4.parse();
        
        printTokens(expr4.getTokens());
        printRPN(expr4.getRPNTokens());
        std::cout << "Result: " << expr4.evaluate() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
