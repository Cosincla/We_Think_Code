#include "FragTrap.hpp"

int main(){
    FragTrap a = FragTrap("SAM");
    a.getstats();
    a.meleeAttack("Psycho");
    a.rangedAttack("Raider");
    a.takeDamage(73);
    a.beRepaired(16);
    a.beRepaired(1000);
    a.vaulthunter_dot_exe("Badass Psycho Midget");
    a.takeDamage(1000);
}