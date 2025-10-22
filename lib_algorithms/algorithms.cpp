#include "algorithms.h"
#include "../stack.h"  // используем ваш Stack
#include <unordered_map>

bool check_brackets(std::string expression) {
    Stack<char> brackets;  // используем ваш Stack вместо std::stack
    std::unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty() || brackets.top() != pairs[c]) {
                return false;
            }
            brackets.pop();
        }
    }
    
    return brackets.empty();
}
