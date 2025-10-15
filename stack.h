#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }
    
    T pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T value = elements.back();
        elements.pop_back();
        return value;
    }
    
    T top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return elements.back();
    }
    
    bool empty() const {
        return elements.empty();
    }
    
    size_t size() const {
        return elements.size();
    }
};

#endif
