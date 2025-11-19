#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>  // для size_t
#include <stdexcept>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    size_t list_size;

public:
    LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}
    
    ~LinkedList() {
        while (!empty()) {
            pop_front();
        }
    }
    
    void push_back(const T& value) {
        Node* new_node = new Node(value);
        if (empty()) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        list_size++;
    }
    
    void push_front(const T& value) {
        Node* new_node = new Node(value);
        if (empty()) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        list_size++;
    }
    
    void pop_front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        list_size--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    
    bool empty() const {
        return head == nullptr;
    }
    
    size_t size() const {
        return list_size;
    }
    
    T& front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }
    
    T& back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }
    
    // Итератор
    class Iterator {
    private:
        Node* current;
    public:
        Iterator() : current(nullptr) {}
        Iterator(Node* pos) : current(pos) {}
        Iterator(const Iterator& other) : current(other.current) {}
        
        T& operator*() { return current->data; }
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
    };
    
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

#endif
