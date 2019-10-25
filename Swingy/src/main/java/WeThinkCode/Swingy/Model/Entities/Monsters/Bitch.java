package WeThinkCode.Swingy.Model.Entities.Monsters;

import WeThinkCode.Swingy.Model.Entities.Organism;

public class Bitch extends Monster implements Organism {
    public Bitch(int x, int y){
        super();
        name = "Bitch";
        xpos = x;
        ypos = y;
        HP = mHP = 6;
        mHPup = 3;
        ATK = 3;
        ATKup = 3;
        DEF = 3;
        DEFup = 3;
        value = 300;
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
