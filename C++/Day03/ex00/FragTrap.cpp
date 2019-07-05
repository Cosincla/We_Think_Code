#include "FragTrap.hpp"

FragTrap::FragTrap(){
    hp = 100;
    mp = 100;
    lvl = 1;
    name = "Basic Mob";
    std::cout << name << ": " << "Give us open ports for remote access or give us death!" << std::endl << std::endl;
}
FragTrap::FragTrap(std::string id){
    hp = 100;
    mp = 100;
    lvl = 1;
    name = id;
    std::cout << name << ": " << "Give us open ports for remote access or give us death!" << std::endl << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &first){
    this->hp = first.hp;
    this->mp = first.mp;
    this->lvl = first.lvl;
    this->name = first.name;
    return *this;
}
FragTrap::~FragTrap(){
    std::cout << name << ": " << "I'm afraid. My mind is going. I can feel it. My mind is going! There's no question about it. I can feel it. I'm a... fraid." << std::endl << std::endl;
}
int FragTrap::gethp() const{
    int i = hp;
    return i;
}
int FragTrap::getmaxhp() const{
    int i = maxhp;
    return i;
}
int FragTrap::getmp() const{
    int i = mp;
    return i;
}
int FragTrap::getmaxmp() const{
    int i = mp;
    return i;
}
int FragTrap::getlvl() const{
    int i = lvl;
    return i;
}
std::string FragTrap::getname() const{
    std::string s = name;
    return s;
}
int FragTrap::getmelee() const{
    int i = melee;
    return i;
}
int FragTrap::getranged() const{
    int i = ranged;
    return i;
}
int FragTrap::getarmor() const{
    int i = armor;
    return i;
}
void FragTrap::getstats() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << lvl << std:: endl;
    std::cout << "Health: " << hp << "/" << maxhp << std::endl;
    std::cout << "Energy: " << mp << "/" << maxmp << std::endl << std::endl;

}
void FragTrap::meleeAttack(std::string const &target){
    int attack = melee;

    std::cout << "Beat it, fleshbag!" << std::endl;
    std::cout << "FR4G-TP "<< name << " attacks " << target << " with melee, causing " << attack << " points of damage !" << std::endl << std::endl;
}
void FragTrap::rangedAttack(std::string const &target){
    int attack = ranged;

    std::cout << "Eat it, fleshbag!" << std::endl;
    std::cout << "FR4G-TP "<< name << " attacks " << target << " at range, causing " << attack << " points of damage !" << std::endl << std::endl;

}

void FragTrap::takeDamage(unsigned int amount){
    int health = hp - (amount - armor);

    if (health <= 0){
        std::cout << "Nonono! You'll never take me alive!" << std::endl;
        hp = 0;
    }
    else
    {
        std::cout << "A claptrap feels no pain- ow! Quit it!" << std::endl;
        hp = health;
    }
    getstats();
}

void FragTrap::beRepaired(unsigned int amount){
    int health = hp + amount;

    if (health >= maxhp){
        std::cout << "Health! Eww, what flavor is red?" << std::endl;
        hp = maxhp;
    }
    else
    {
        std::cout << "Sweet life juice!" << std::endl;
        hp = health;
    }
    getstats();
}
    
void FragTrap::vaulthunter_dot_exe(std::string const & target){
    int energy = mp - 25;
    std::string names[6] = {"Funzerker", "Meat Unicycle", "Blightbot", "Rubber Ducky", "Torgue Fiesta"};

    std::cout << "Recompiling my combat code!" << std::endl;
    if (energy <= 0){
        std::cout << "Can't do that yet" << std::endl;
    }
    else {
        std::cout << "FR4G-TP "<< name << " attacks " << target << " with " << names[(rand() % 6)] << " causing 50 points of damage !" << std::endl << std::endl;
        mp = energy;
    }
    getstats();
}