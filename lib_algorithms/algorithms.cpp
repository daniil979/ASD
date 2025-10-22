#include "algorithms.h"
#include "../stack.h"
#include <unordered_map>

bool check_brackets(std::string expression) {
    Stack<char> brackets; 
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
