#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
public:
    std::string name, type;

    Zombie(){
        std::cout << "Zombie spawned";
    }
    ~Zombie(){
        std::cout << name << " was shot for being a twat" << std::endl << std::endl;
    }
    void announce();
};

void randomChump();

#endif