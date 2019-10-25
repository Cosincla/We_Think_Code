package WeThinkCode.Swingy.Model.Entities.Monsters;

import WeThinkCode.Swingy.Model.Entities.Organism;

public class Skeleton extends Monster implements Organism {
    public Skeleton(int x, int y){
        super();
        name = "Skeleton";
        xpos = x;
        ypos = y;
        HP = mHP = 7;
        mHPup = 2;
        ATK = 5;
        ATKup = 2;
        DEF = 5;
        DEFup = 2;
        value = 500;
    }

    public void takeDamage(int offence){
        if (offence > (getDEF()))
            setHP(getHP() - (offence - (getDEF())));
        else
            setHP(getHP() - 1);
        if (getHP() < 0){
            setHP(0);
        }
    }
    public void heal(int health){
        if (getHP() + health > getMHP()){
            setHP(getMHP());
        }
    }
    public void levelup(int level){
        int i = 0;
        while (i < level) {
            setMHP(getMHP() + getMHPup());
            setHP(getMHP());
            setATK(getATK() + getATKup());
            setDEF(getDEF() + getDEFup());
            i++;
        }
    }
}
