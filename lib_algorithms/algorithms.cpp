#include "algorithms.h"
#include "../stack.h"

bool check_brackets(std::string expression) {
    Stack<char> brackets;
    
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
           
            
            if (brackets.empty()) {
                
                return false;
            }
            
            char top = brackets.top();
            
           
            if (c == ')' && top != '(') {
                return false;
            }
            if (c == ']' && top != '[') {
                return false;
            }
            if (c == '}' && top != '{') {
                return false;
            }
            brackets.pop();
        }
    }
    return brackets.empty();
}
