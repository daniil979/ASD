#include <iostream>
#include "../stack.h"

int main() {
    std::cout << "Тестирование стека:" << std::endl;
    
    Stack<int> intStack;
    
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    std::cout << "Размер стека: " << intStack.size() << std::endl;
    std::cout << "Верхний элемент: " << intStack.top() << std::endl;
    
    while (!intStack.empty()) {
        std::cout << "Извлекаем: " << intStack.pop() << std::endl;
    }
    
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    
    std::cout << "\nСтек строк:" << std::endl;
    while (!stringStack.empty()) {
        std::cout << stringStack.pop() << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
