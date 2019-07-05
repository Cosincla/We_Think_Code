#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>

class FragTrap {
private:
    int hp;
    static const int maxhp = 100;
    int mp;
    static const int maxmp = 100;
    int lvl;
    std::string name;
    static const int melee = 30;
    static const int ranged = 20;
    static const int armor = 5;
public:
    FragTrap();
    FragTrap(std::string id);
    FragTrap &operator=(const FragTrap &first);
    ~FragTrap();
    int gethp() const;
    int getmaxhp() const;
    int getmp() const;
    int getmaxmp() const;
    int getlvl() const;
    std::string getname() const;
    int getmelee() const;
    int getranged() const;
    int getarmor() const;
    void getstats() const;
    void rangedAttack(std::string const &target);
    void meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void vaulthunter_dot_exe(std::string const & target);
};

#endif