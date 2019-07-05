#include "../includes/main.hpp"

projectile::projectile(){
    friendly = 0;
    setspeed(2);
}
projectile::projectile(int i){
    friendly = i;
    setspeed(2);
}

projectile::~projectile(){}

void projectile::setfriendly(int i){
    friendly = i;
}
int projectile::getfriendly(){
    return friendly;
}
//int projectile::collision(){}