#include "../includes/main.hpp"

ship::ship(){
    setx(48);
    sety(2 + rand() % 12);
    setspeed(1);
    setshape("<");
}
ship::ship(const char *shape){
    setx(1);
    sety(7);
    setspeed(1);
    setshape(shape);
    setscore(0);
    setlives(1000);
}

ship::~ship(){
}
void ship::setlives(int l){
    lives = l;
}
void ship::setscore(int s){
    score = s;
}
int ship::getlives(){
    return lives;
}
int ship::getscore(){
    return score;
}
void ship::moveup(){
    if ((y_cor - speed) > 2){
        sety(y_cor - speed);
    }
    else{
        sety(2);
    }
}
void ship::movedown(){
    if (y_cor + speed < 13){
        sety(y_cor + speed);
    }
    else{
        sety(13);
    }
}
void ship::moveleft(){
    if (x_cor - speed >= 1){
        setx(x_cor - speed);
    }
    else{
        setx(1);
    }
}
void ship::moveright(){
    if (x_cor + speed <= 10){
        setx(x_cor + speed);
    }
    else{
        setx(10);
    }
}
void ship::minuslives(){
    lives = 1 + lives;
}
projectile ship::shoot(int i){
    projectile bullet;
    bullet.sety(gety());
    bullet.setx(getx() + 1);
    bullet.setshape("-");
    bullet.setfriendly(i);
    return bullet;
}