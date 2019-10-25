package WeThinkCode.Swingy.Model.Entities.Heroes;

import WeThinkCode.Swingy.Model.Entities.Organism;
import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.NotNull;

public class ShieldHero extends Hero implements Organism {
    @Getter @Setter @NotNull private String equip = "Shield";

    public ShieldHero(String name){
        super(name);
        job = "shield";
        HP = mHP = 15;
        mHPup = 2;
        ATK = 2;
        ATKup = 1;
        DEF = 6;
        DEFup = 2;
        xpos = 4;
        ypos = 4;
    }
    public void takeDamage(int offence){
        if (offence > (getDEF() + getAvalue()))
            setHP(getHP() - (offence - (getDEF() + getAvalue())));
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
        setLVL(getLVL() + level);
        setExp(0);
        setLevelup(Math.round((getLVL() * 1000 + Math.pow((getLVL() - 1), 2) * 450)));
    }
}