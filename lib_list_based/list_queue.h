#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "../lib_linked_list/linked_list.h"
#include <stdexcept>

template<typename T>
class ListQueue {
private:
    LinkedList<T> list;

public:
    // Добавить элемент в конец очереди
    void enqueue(const T& value) {
        list.push_back(value);
    }
    
    // Удалить и вернуть первый элемент
    T dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        T value = list.front();
        list.pop_front();
        return value;
    }
    
    // Посмотреть первый элемент без удаления
    T front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return list.front();
    }
    
    // Проверить пуста ли очередь
    bool empty() const {
        return list.empty();
    }
    
    // Размер очереди
    size_t size() const {
        return list.size();
    }
    
    // Очистить очередь
    void clear() {
        while (!empty()) {
            dequeue();
        }
    }
};

#endif
