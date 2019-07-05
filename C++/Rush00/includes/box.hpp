#ifndef BOX_HPP
# define BOX_HPP
# include "main.hpp"

class Box{
private:
    projectile bullets[1000];
    ship enemies[1000];
    int iter;
    int jter;
    int time;
public:
    Box();
    ~Box();

    void makebox();
    void loop();
    void updatebullets(WINDOW *win);
    void updatemies(WINDOW *win);
    void setiter(int i);
    void setjter(int i);
    void settime(int i);
    void timeiter();
    void iteriter();
    void jteriter();
    void itercheck();
    void jtercheck();
    int collisions(ship &me);
    int getiter();
    int getjter();
    int gettime();
    ship setplayership();
};

#endif