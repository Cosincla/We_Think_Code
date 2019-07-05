#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(Zombie *zombie, std::string type){
    zombie->type = type;
}

Zombie *ZombieEvent::newZombie(std::string name){
    Zombie *zombie = new Zombie();
    setZombieType(zombie, name);
    zombie->name = "Nostradamus";
    zombie->announce();
    return zombie;
}

void randomChump(){
    std::string names[6][8] = { "chump00", "chump01", "chump02", "chump03", "chump04" };
    std::string types[6][7] = { "type00", "type01", "type02", "type03", "type04" };
    int i = rand() % 7;
    int j = rand() % 7;
    Zombie chump;
    chump.name = *names[i];
    chump.type = *types[j];
    chump.announce();
} 