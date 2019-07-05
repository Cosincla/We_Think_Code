#include "Pony.hpp"

void Pony_on_stack(std::string name, std::string colour){
    std::cout << "Stack function is called" << std::endl;
    Pony pony(name, colour);
    std::cout << "Stack function is finished" << std::endl;
}

void Pony_on_heap(std::string name, std::string colour){
    std::cout << "Heap function is called" << std::endl;
    Pony *pony = new Pony(name, colour);
    std::cout << "Heap function is finished" << std::endl;
    delete pony;
}