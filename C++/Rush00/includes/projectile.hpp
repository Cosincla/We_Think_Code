#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP
# include "main.hpp"

class projectile : public Entity{
private:
    int friendly;
    int speed;
    int iter;
public:
    projectile();
    projectile(int i);
    ~projectile();

    void setfriendly(int i);
    int getfriendly();
    int collision();
};
#endif