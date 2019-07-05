#ifndef ENTITY_HPP
# define ENTITY_HPP
# include "main.hpp"

class Entity{
protected:
    int y_cor;
    int x_cor;
    int speed;
    const char * shape;
public:
    Entity();
    ~Entity();

    void sety(int i);
    void setx(int i);
    void setspeed(int i);
    void setshape(const char * ship);
    int gety();
    int getx();
    int getspeed();
    const char * getshape();
};

#endif