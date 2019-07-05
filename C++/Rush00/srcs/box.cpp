#include "../includes/main.hpp"

Box::Box(){
    setiter(0);
    setjter(0);
    settime(0);
    initscr();
    noecho();
    curs_set(0);
}
Box::~Box(){
    endwin();
}

ship Box::setplayership(){
    std::cout << "3"<< std::endl;
    ship me = ship(">");
    return me;
}
void Box::loop(){
    WINDOW * win = newwin(15, 50, 0, 0);
    ship me = setplayership();  
    refresh();
    cbreak();
    while (1){
        int y = me.gety();
        int x = me.getx();
        wclear(win);
        box(win, 0, 0);
        mvwprintw(win, 1, 2, "SCORE: %d", me.getscore());
        mvwprintw(win, 1, 40, "HP: %d", me.getlives());
        mvwprintw(win, y, x, "%s", me.getshape());
        int i = collisions(me);
        updatebullets(win);
        updatemies(win);
        me.setscore(me.getscore() + i);
        wtimeout(win, 100);
        int c = wgetch(win);
        usleep(5000);
        mvwprintw(win, 2, 40, "%i", iter);
        if (me.getlives() <= 0){
            break;
        }
        if (c == 'q'){
            break;
        }
        if (c == 'i'){
            me.moveup();
        }
        if (c == 'k'){
            me.movedown();
        }
        if (c == 'j'){
            me.moveleft();
        }
        if (c == 'l'){
            me.moveright();
        }
        if (c == 'x'){
            bullets[(getiter())] = me.shoot(1);
            iteriter();
        }
        timeiter();
        flushinp();
    }
}

void Box::updatemies(WINDOW *win){
    int j = 0;
    if (time == 20){
        settime(0);
        jteriter();
    }
    while (j < getjter()){
        if (enemies[j].getx() == 0){
            enemies[j].setx(48);
            enemies[j].sety(2 + rand() % 10);
            enemies[j].setshape("<");
        }
        if (enemies[j].getx() == 3){
            enemies[j].setshape("");
        }
        if (enemies[j].getx() > 2){
            enemies[j].setx(enemies[j].getx() - 1);
        }
        mvwprintw(win, enemies[j].gety(), enemies[j].getx(), "%s", enemies[j].getshape());
        jtercheck();
        j++;
    }
}

void Box::updatebullets(WINDOW *win){
    int j = 0;
    itercheck();
    while (j < getiter()){
        if (bullets[j].getx() == 48 || bullets[j].getx() == 1){
            bullets[j].setshape(" ");
        }
        else{
            if ((bullets[j].getfriendly() == 1)){
                bullets[j].setx(bullets[j].getx() + 1);
            }
            else {
                bullets[j].setx(bullets[j].getx() - 1);
            }
        }
        mvwprintw(win, bullets[j].gety(), bullets[j].getx(), "%s", bullets[j].getshape());
        j++;
    }
}

void Box::setiter(int i){
    iter = i;
}
void Box::setjter(int i){
    jter = i;
}
void Box::settime(int i){
    time = i;
}
void Box::itercheck(){
    if (getiter() == 998){
        setiter(0);
    }
}
void Box::jtercheck(){
    if (getjter() == 998){
        setjter(0);
    }
}
void Box::iteriter(){
    iter++;
}
void Box::timeiter(){
    time++;
}
void Box::jteriter(){
    jter++;
}
int Box::getiter(){
    return iter;
}
int Box::getjter(){
    return jter;
}
int Box::gettime(){
    return time;
}

int Box::collisions(ship &me){
    int i = 0;
    int col = 0;
    while (i < getiter()){
        int j = 0;
        while (j < getjter()){
            if ((enemies[j].getx() == me.getx()) && (enemies[j].gety() == me.gety())){
                me.setlives((me.getlives() - 1));
                enemies[j].setx(48);
                enemies[j].sety(2 + rand() % 12);
            }
            if (enemies[j].getx() == 1){
                enemies[j].setx(48);
                enemies[j].sety(2 + rand() % 12);
                enemies[j].setshape("<");
            }
            if ((bullets[i].getx() == enemies[j].getx()) && (bullets[i].gety() == enemies[j].gety()) && bullets[i].getfriendly() == 1){
                bullets[i].setfriendly(0);
                bullets[i].setshape("");
                bullets[i].setx(49);
                enemies[j].setx(48);
                enemies[j].sety(2 + rand() % 12);
                col++;
            }
            if ((bullets[i].getx() == enemies[j].getx() - 1) && (bullets[i].gety() == enemies[j].gety()) && bullets[i].getfriendly() == 1){
                bullets[i].setfriendly(0);
                bullets[i].setshape("");
                enemies[j].setshape("");
                enemies[j].setx(48);
                enemies[j].sety(2 + rand() % 12);
                enemies[j].setshape("<");
                col++;
            }
            j++;
        }
        i++;
    }
    return col;
}