package WeThinkCode.Swingy.Model.Entities.Monsters;

import WeThinkCode.Swingy.Model.Entities.Organism;

public class Dragon extends Monster implements Organism {
    public Dragon(int x, int y){
        super();
        name = "Dragon";
        xpos = x;
        ypos = y;
        HP = mHP = 20;
        mHPup = 3;
        ATK = 13;
        ATKup = 3;
        DEF = 13;
        DEFup = 3;
        value = 700;
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
