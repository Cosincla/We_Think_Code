#ifndef PONY_HPP
# define PONY_HPP
# include <string>
# include <iostream>

class Pony {
public:
    std::string name, colour;

    Pony(std::string id, std::string colour){
        name = id;
        std::cout << "Pony " << name << " is born" << std::endl;
    }

    ~Pony(){
        std::cout << "Pony " << name << " died"<< std::endl;
    }
};

void Pony_on_heap(std::string name, std::string colour);
void Pony_on_stack(std::string name, std::string colour);

#endif