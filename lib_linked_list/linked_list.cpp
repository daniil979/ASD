//#include "linked_list.h"
//#include <stdexcept>
//
//template<typename T>
//LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}
//
//template<typename T>
//LinkedList<T>::~LinkedList() {
//    while (!empty()) {
//        pop_front();
//    }
//}
//
//template<typename T>
//void LinkedList<T>::push_back(const T& value) {
//    Node* new_node = new Node(value);
//    if (empty()) {
//        head = tail = new_node;
//    } else {
//        tail->next = new_node;
//        tail = new_node;
//    }
//    list_size++;
//}
//
//template<typename T>
//void LinkedList<T>::push_front(const T& value) {
//    Node* new_node = new Node(value);
//    if (empty()) {
//        head = tail = new_node;
//    } else {
//        new_node->next = head;
//        head = new_node;
//    }
//    list_size++;
//}
//
//template<typename T>
//void LinkedList<T>::pop_front() {
//    if (empty()) {
//        throw std::out_of_range("List is empty");
//    }
//    Node* temp = head;
//    head = head->next;
//    delete temp;
//    list_size--;
//    if (head == nullptr) {
//        tail = nullptr;
//    }
//}
//
//template<typename T>
//bool LinkedList<T>::empty() const {
//    return head == nullptr;
//}
//
//template<typename T>
//size_t LinkedList<T>::size() const {
//    return list_size;
//}
//
//template<typename T>
//T& LinkedList<T>::front() {
//    if (empty()) {
//        throw std::out_of_range("List is empty");
//    }
//    return head->data;
//}
//
//template<typename T>
//T& LinkedList<T>::back() {
//    if (empty()) {
//        throw std::out_of_range("List is empty");
//    }
//    return tail->data;
//}
