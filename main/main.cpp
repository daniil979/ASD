#include <iostream>
#include "lib_linked_list/linked_list.h"
#include "lib_algorithms/algorithms.h"

int main() {
    // Демо связного списка
    LinkedList<int> list;
    list.addFront(1);
    list.addBack(2);
    list.addBack(3);
    
    std::cout << "Список: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Демо алгоритмов
    std::cout << "Проверка скобок: " << checkBrackets("()[]") << std::endl;
    
    return 0;
}
