#ifndef SHIP_HPP
# define SHIP_HPP
# include "main.hpp"

class ship : public Entity{
private:
    int lives;
    int score;
public:
    ship();
    ship(const char *shape);
    ~ship();

    void setlives(int l);
    void setscore(int s);
    int getlives();
    void minuslives();
    int getscore();
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
    projectile shoot(int i);
};

#endif