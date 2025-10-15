#ifndef QUEUE_H
#define QUEUE_H

#include <list>
#include <stdexcept>

template<typename T>
class Queue {
private:
    std::list<T> elements;
    
public:
    void enqueue(const T& value);
    T dequeue();
    T front() const;
    
    bool empty() const;
    
    size_t size() const;
    void clear();
    };
template<typename T>
void Queue<T>::enqueue(const T& value) {
    elements.push_back(value);
}

template<typename T>
T Queue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    T value = elements.front();
    elements.pop_front();
    return value;
}
template<typename T>
T Queue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return elements.front();
}

template<typename T>
bool Queue<T>::empty() const {
    return elements.empty();
}

template<typename T>
size_t Queue<T>::size() const {
    return elements.size();
}

template<typename T>
void Queue<T>::clear() {
    elements.clear();
}

#endif
