#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include <string>
# include <iostream>
# include "Zombie.hpp"

class ZombieEvent {
public:
    void setZombieType(Zombie *zombie, std::string type);
    Zombie *newZombie(std::string name);
};

#endif