package WeThinkCode.Swingy.Controller;

import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import WeThinkCode.Swingy.Model.Entities.Monsters.Monster;
import WeThinkCode.Swingy.Model.Entities.Organism;
import WeThinkCode.Swingy.Model.Util.Randomiser;
import WeThinkCode.Swingy.View.GUI.G_Game_menu;
import javax.swing.*;
import java.util.List;

public class GUI_event_handler extends G_Game_menu {
    private static GUI_event_handler gui = new GUI_event_handler();

    private static void new_level() {
        GameState.getInstance().getMap().setX((GameState.getInstance().getMyHero().getLVL() - 1) * 5 + 10 - (GameState.getInstance().getMyHero().getLVL() % 2));
        GameState.getInstance().getMap().setY(GameState.getInstance().getMap().getX());
        GameState.getInstance().getMap().setPx(GameState.getInstance().getMap().getX() / 2);
        GameState.getInstance().getMap().setPy(GameState.getInstance().getMap().getY() / 2);
        GameState.getInstance().getMyHero().setXpos(GameState.getInstance().getMap().getPx());
        GameState.getInstance().getMyHero().setYpos(GameState.getInstance().getMap().getPy());
        GameState.getInstance().getTextArea().append("You have cleared the level.\n");
        GameState.getInstance().getMap().clearMonsters();
        while (GameState.getInstance().getMap().getMonsters().size() < ((GameState.getInstance().getMap().getX() * GameState.getInstance().getMap().getY())) * 0.3) {
            GameState.getInstance().getMap().spawnMonsters();
        }
        GameState.getInstance().getMap().lvlMonsters(GameState.getInstance().getMyHero().getLVL() - 1);
        GameState.getInstance().getMyHero().setHP(GameState.getInstance().getMyHero().getMHP() + GameState.getInstance().getMyHero().getHvalue());
        GameState.getInstance().getHp().setText(GameState.getInstance().getMyHero().getHP() + "/" + (GameState.getInstance().getMyHero().getMHP() + GameState.getInstance().getMyHero().getHvalue()));
        frame.repaint();
        frame.revalidate();
    }

    public static void levelup(){
        if (GameState.getInstance().getMyHero().getExp() >= GameState.getInstance().getMyHero().getLevelup()){
            GameState.getInstance().getTextArea().append("You leveled up!\n");
            GameState.getInstance().getMyHero().setLVL(GameState.getInstance().getMyHero().getLVL() + 1);
            ((Organism) GameState.getInstance().getMyHero()).levelup(1);
            GameState.getInstance().getMyHero().setExp(GameState.getInstance().getMyHero().getExp() - GameState.getInstance().getMyHero().getLevelup());
            GameState.getInstance().getMyHero().setLevelup(GameState.getInstance().getMyHero().getLVL() * 1000 + ((GameState.getInstance().getMyHero().getLVL() - 1) * (GameState.getInstance().getMyHero().getLVL() - 1)) * 450);
            GameState.getInstance().getMyHero().setHP(GameState.getInstance().getMyHero().getMHP() + GameState.getInstance().getMyHero().getHvalue());
            GameState.getInstance().getLvl().setText(String.valueOf(GameState.getInstance().getMyHero().getLVL()));
            GameState.getInstance().getExp().setText(GameState.getInstance().getMyHero().getExp() + "/" + GameState.getInstance().getMyHero().getLevelup());
        }
    }

    private static void p_fight(List<Monster> monsters, Monster monster, Hero hero) {
        int age = 0;
        int mhpcur;
        int hhpcur;
        while (true) {
            mhpcur = monster.getHP();
            hhpcur = hero.getHP();
            age++;
            if (age == 100) {
                JOptionPane.showMessageDialog(frame, "You continued fighting till the end of your days\n");
                System.exit(0);
            }
            if (GameState.getInstance().getMyHero().getHP() <= 0) {
                JOptionPane.showMessageDialog(frame, "YOU DIED.");
                System.exit(0);
            }
            ((Organism) monster).takeDamage((hero.getATK() + hero.getWvalue()));
            GameState.getInstance().getTextArea().append("You attacked the " + monster.getName() + " for " + (mhpcur - monster.getHP()) + " damage.\n");
            if (monster.getHP() <= 0) {
                GameState.getInstance().getTextArea().append("You have killed the " + monster.getName() + ".\n");
                GameState.getInstance().getTextArea().append("You gained " + monster.getValue() + " experience points.\n");
                hero.setExp(hero.getExp() + monster.getValue());
                GameState.getInstance().getExp().setText(GameState.getInstance().getMyHero().getExp() + "/" + GameState.getInstance().getMyHero().getLevelup());
                frame.repaint();
                frame.revalidate();
                monsters.remove(monster);
                int r = Randomiser.Ranger(2, 1);
                switch (r) {
                    case 1: {
                        GameState.getInstance().getTextArea().append("You didnt find anything of worth.\n");
                        return;
                    }
                    case 2: {
                        int e = Randomiser.Ranger(3, 1);
                        int g = Randomiser.Ranger(10, 0);
                        String grade;
                        if (g > 8) {
                            grade = "Rare";
                        } else if (g > 5) {
                            grade = "Uncommon";
                        } else {
                            grade = "Common";
                        }
                        switch (e) {
                            case 1: {
                                int value = Randomiser.Random(grade);
                                int orange = JOptionPane.showConfirmDialog(frame,
                                        "You have found a " + grade + " Helm.\nCurrent equipment value: " + hero.getHvalue() + ".\nNew equipment value: " + value + ".\nWould you like to equip this Helm?\n", null, JOptionPane.YES_NO_OPTION);
                                switch (orange) {
                                    case JOptionPane.YES_OPTION: {
                                        hero.setHelmgrade(grade);
                                        hero.setHvalue(value);
                                        if (hero.getHP() > hero.getMHP()+ hero.getHvalue())
                                            hero.setHP(hero.getMHP()+ hero.getHvalue());
                                        GameState.getInstance().getHp().setText(GameState.getInstance().getMyHero().getHP() + "/" + (GameState.getInstance().getMyHero().getMHP() + GameState.getInstance().getMyHero().getHvalue()));
                                        frame.repaint();
                                        frame.revalidate();
                                        return;
                                    }
                                    case JOptionPane.NO_OPTION: {
                                        return;
                                    }
                                }
                            }
                            case 2: {
                                int value = Randomiser.Random(grade);
                                int orange = JOptionPane.showConfirmDialog(frame,
                                        "You have found a " + grade + " Armor set.\nCurrent equipment value: " + hero.getAvalue() + ".\nNew equipment value: " + value + ".\nWould you like to equip this Armor set?\n", null, JOptionPane.YES_NO_OPTION);
                                switch (orange) {
                                    case JOptionPane.YES_OPTION: {
                                        hero.setArmorgrade(grade);
                                        hero.setAvalue(value);
                                        GameState.getInstance().getDef().setText(String.valueOf(GameState.getInstance().getMyHero().getDEF() + GameState.getInstance().getMyHero().getAvalue()));
                                        frame.repaint();
                                        frame.revalidate();
                                        return;
                                    }
                                    case JOptionPane.NO_OPTION: {
                                        return;
                                    }
                                }
                            }
                            case 3: {
                                int value = Randomiser.Random(grade);
                                int orange = JOptionPane.showConfirmDialog(frame,
                                        "You have found a " + grade + " Weapon.\nCurrent equipment value: " + hero.getWvalue() + ".\nNew equipment value: " + value + ".\nWould you like to equip this Weapon?\n", null, JOptionPane.YES_NO_OPTION);
                                switch (orange) {
                                    case JOptionPane.YES_OPTION: {
                                        hero.setWeapongrade(grade);
                                        hero.setWvalue(value);
                                        GameState.getInstance().getAtk().setText(String.valueOf(GameState.getInstance().getMyHero().getATK() + GameState.getInstance().getMyHero().getWvalue()));
                                        return;
                                    }
                                    case JOptionPane.NO_OPTION: {
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ((Organism) hero).takeDamage(monster.getATK());
            GameState.getInstance().getTextArea().append("The " + monster.getName() + " attacked you for " + (hhpcur - hero.getHP()) + " damage.\n");
            GameState.getInstance().getHp().setText(GameState.getInstance().getMyHero().getHP() + "/" + (GameState.getInstance().getMyHero().getMHP() + GameState.getInstance().getMyHero().getHvalue()));
        }
    }
    private static void m_fight(List<Monster> monsters, Monster monster, Hero hero){
        int age = 0;
        int mhpcur;
        int hhpcur;
        while (true) {
            mhpcur = monster.getHP();
            hhpcur = hero.getHP();
            age++;
            if (age == 100) {
                JOptionPane.showMessageDialog(frame, "You continued fighting till the end of your days\n");
                System.exit(0);
            }
            ((Organism) hero).takeDamage(monster.getATK());
            GameState.getInstance().getTextArea().append("The " + monster.getName() + " attacked you for " + (hhpcur - hero.getHP()) + " damage.\n");
            GameState.getInstance().getHp().setText(GameState.getInstance().getMyHero().getHP() + "/" + (GameState.getInstance().getMyHero().getMHP() + GameState.getInstance().getMyHero().getHvalue()));
            if (GameState.getInstance().getMyHero().getHP() <= 0) {
                JOptionPane.showMessageDialog(frame, "YOU DIED.");
                System.exit(0);
            }
            ((Organism) monster).takeDamage((hero.getATK() + hero.getWvalue()));
            GameState.getInstance().getTextArea().append("You attacked the " + monster.getName() + " for " + (mhpcur - monster.getHP()) + " damage.\n");
            if (monster.getHP() <= 0) {
                GameState.getInstance().getTextArea().append("You have killed the " + monster.getName() + ".\n");
                GameState.getInstance().getTextArea().append("You gained " + monster.getValue() + " experience points.\n");
                hero.setExp(hero.getExp() + monster.getValue());
                GameState.getInstance().getExp().setText(GameState.getInstance().getMyHero().getExp() + "/" + GameState.getInstance().getMyHero().getLevelup());
                frame.repaint();
                frame.revalidate();
                monsters.remove(monster);
                int r = Randomiser.Ranger(2, 1);
                switch (r) {
                    case 1: {
                        GameState.getInstance().getTextArea().append("You didnt find anything of worth.\n");
                        return;
                    }
                    case 2: {
                        int e = Randomiser.Ranger(3, 1);
                        int g = Randomiser.Ranger(10, 0);
                        String grade;
                        if (g > 8) {
                            grade = "Rare";
                        } else if (g > 5) {
                            grade = "Uncommon";
                        } else {
                            grade = "Common";
                        }
                        switch (e) {
                            case 1: {
                                int value = Randomiser.Random(grade);
                                int orange = JOptionPane.showConfirmDialog(frame,
                                        "You have found a " + grade + " Helm.\nCurrent equipment value: " + hero.getHvalue() + ".\nNew equipment value: " + value + ".\nWould you like to equip this Helm?\n", null, JOptionPane.YES_NO_OPTION);
                                switch (orange) {
                                    case JOptionPane.YES_OPTION: {
                                        hero.setHP(hero.getHP() - hero.getHvalue() + value);
                                        hero.setHelmgrade(grade);
                                        hero.setHvalue(value);
                                        GameState.getInstance().getHp().setText(GameState.getInstance().getMyHero().getHP() + "/" + (GameState.getInstance().getMyHero().getMHP() + GameState.getInstance().getMyHero().getHvalue()));
                                        frame.repaint();
                                        frame.revalidate();
                                        return;
                                    }
                                    case JOptionPane.NO_OPTION: {
                                        return;
                                    }
                                }
                            }
                            case 2: {
                                int value = Randomiser.Random(grade);
                                int orange = JOptionPane.showConfirmDialog(frame,
                                        "You have found a " + grade + " Armor set.\nCurrent equipment value: " + hero.getAvalue() + ".\nNew equipment value: " + value + ".\nWould you like to equip this Armor set?\n", null, JOptionPane.YES_NO_OPTION);
                                switch (orange) {
                                    case JOptionPane.YES_OPTION: {
                                        hero.setArmorgrade(grade);
                                        hero.setAvalue(value);
                                        GameState.getInstance().getDef().setText(String.valueOf(GameState.getInstance().getMyHero().getDEF() + GameState.getInstance().getMyHero().getAvalue()));
                                        frame.repaint();
                                        frame.revalidate();
                                        return;
                                    }
                                    case JOptionPane.NO_OPTION: {
                                        return;
                                    }
                                }
                            }
                            case 3: {
                                int value = Randomiser.Random(grade);
                                int orange = JOptionPane.showConfirmDialog(frame,
                                        "You have found a " + grade + " Weapon.\nCurrent equipment value: " + hero.getWvalue() + ".\nNew equipment value: " + value + ".\nWould you like to equip this Weapon?\n", null, JOptionPane.YES_NO_OPTION);
                                switch (orange) {
                                    case JOptionPane.YES_OPTION: {
                                        hero.setWeapongrade(grade);
                                        hero.setWvalue(value);
                                        GameState.getInstance().getAtk().setText(String.valueOf(GameState.getInstance().getMyHero().getATK() + GameState.getInstance().getMyHero().getWvalue()));
                                        return;
                                    }
                                    case JOptionPane.NO_OPTION: {
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    public static void event_status(){
        if (GameState.getInstance().getMap().getPx() == 0 || GameState.getInstance().getMap().getPx() == GameState.getInstance().getMap().getX()
        || GameState.getInstance().getMap().getPy() == 0 || GameState.getInstance().getMap().getPy() == GameState.getInstance().getMap().getY()){
            new_level();
        }
        else{
            int x = GameState.getInstance().getMyHero().getXpos();
            int y = GameState.getInstance().getMyHero().getYpos();
            List<Monster> mons = GameState.getInstance().getMap().getMonsters();
            for (Monster monster: mons) {
                if (monster.getXpos() == x && monster.getYpos() == y){
                    GameState.getInstance().getTextArea().append("You have encountered a " + monster.getName() + ".\n");
                    int result = JOptionPane.showConfirmDialog(frame, "Will you fight the " + monster.getName() + "?\n", null, JOptionPane.YES_NO_OPTION);
                    if (result == JOptionPane.YES_OPTION){
                        GameState.getInstance().getTextArea().append("You fight the " + monster.getName() + ".\n");
                        p_fight(mons, monster, GameState.getInstance().getMyHero());
                    }
                    else {
                        int r = Randomiser.Ranger(2, 1);
                        if (r == 2)
                            GameState.getInstance().getTextArea().append("You flee from the " + monster.getName() + ".\n");
                        else{
                            JOptionPane.showMessageDialog(frame, "YOU FAILED TO FLEE!\n");
                            m_fight(mons, monster, GameState.getInstance().getMyHero());
                        }
                    }
                }
            }
        }
    }
}
