#include "../includes/main.hpp"

Entity::Entity(){
    speed = 1;
    x_cor = 1;
    y_cor = 7;
}
Entity::~Entity(){
}

void Entity::setshape(const char * ship){
    shape = ship;
}
void Entity::sety(int i){
    y_cor = i;
}
void Entity::setx(int i){
    x_cor = i;
}
void Entity::setspeed(int i){
    speed = i;
}
int Entity::gety(){
    return y_cor;
}
int Entity::getx(){
    return x_cor;
}
int Entity::getspeed(){
    return speed;
}
const char * Entity::getshape(){
    return shape;
}