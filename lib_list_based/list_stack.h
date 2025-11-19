#ifndef LIST_STACK_H
#define LIST_STACK_H

#include "../lib_linked_list/linked_list.h"
#include <stdexcept>

template<typename T>
class ListStack {
private:
    LinkedList<T> list;

public:
    void push(const T& value) {
        list.push_back(value);
    }
    T pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T value = list.back();
        list.pop_back();
        return value;
    }
    T top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return list.front();
    }

    bool empty() const {
        return list.empty();
    }
    
    size_t size() const {
        return list.size();
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }
};

#endif
