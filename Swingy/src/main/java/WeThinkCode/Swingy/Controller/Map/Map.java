package WeThinkCode.Swingy.Controller.Map;

import WeThinkCode.Swingy.Model.Entities.Factories.MonsterFactory;
import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import WeThinkCode.Swingy.Model.Entities.Monsters.Monster;
import WeThinkCode.Swingy.Model.Entities.Organism;
import WeThinkCode.Swingy.Model.Util.Randomiser;
import lombok.Getter;
import lombok.Setter;
import javax.validation.constraints.NotNull;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CopyOnWriteArrayList;

public class Map {
    @Getter @Setter @NotNull private int x;
    @Getter @Setter @NotNull private int y;
    @Getter @Setter @NotNull private int px;
    @Getter @Setter @NotNull private int py;
    @Getter @Setter @NotNull private int map_lvl;
    @Getter @Setter @NotNull private List<Monster> monsters = new CopyOnWriteArrayList<>();

    public Map(int level){
        setMap_lvl(level);
        x = y = ((level - 1) * 5 + 10 - (level % 2));
        px = py = (x / 2);
    }
    public void checkhero(Hero hero){
        if (hero.getExp() >= hero.getLevelup()){
            System.out.println("You leveled up!");
            hero.setLVL(hero.getLVL() + 1);
            ((Organism) hero).levelup(1);
            hero.setExp(hero.getExp() - hero.getLevelup());
            hero.setLevelup(hero.getLVL() * 1000 + ((hero.getLVL() - 1) * (hero.getLVL() - 1)) * 450);
            hero.setHP(hero.getMHP() + hero.getHvalue());
        }
    }
    public void start(Hero hero){
        if (hero.getXpos() == 0 || hero.getYpos() == 0 || hero.getXpos() == ((hero.getLVL() - 2) * 5 + 10 - ((hero.getLVL() - 1) % 2))
                || hero.getYpos() == ((hero.getLVL() - 2) * 5 + 10 - ((hero.getLVL() - 1) % 2))){
            hero.setXpos(((hero.getLVL() - 1) * 5 + 10 - (hero.getLVL() % 2)) / 2);
            hero.setYpos(((hero.getLVL() - 1) * 5 + 10 - (hero.getLVL() % 2)) / 2);
        }
        px = hero.getXpos();
        py = hero.getYpos();
    }
    public void spawnMonsters(){
        int rand = Randomiser.Ranger(10, 1);
        int randx = Randomiser.Ranger(x, 1);
        int randy = Randomiser.Ranger(y, 1);
        if (monsters.isEmpty()) {
            if (randx == px && randy == py) {
                return;
            } else {
                monsters.add(MonsterFactory.newMonster(randx, randy, rand));
                return;
            }
        }
        else for (Monster monster : monsters) {
            if ((randx == monster.getXpos() && randy == monster.getYpos()) || (randx == px && randy == py)) {
                return;
            }
        }
        monsters.add(MonsterFactory.newMonster(randx, randy, rand));
        return;
    }
    public void clearMonsters() {
        for (Monster monster : monsters){
            monsters.remove(monster);
        }
    }
    public void lvlMonsters(int lvl){
        for (Monster monster : monsters) {
            ((Organism) monster).levelup(lvl);
        }
    }
    private int fight(Hero hero, Monster monster, int f){
        switch(f){
            case 1 :{
                int age = 0;
                int mhpcur;
                int hhpcur;
                while (true){
                    mhpcur = monster.getHP();
                    hhpcur = hero.getHP();
                    age++;
                    if (age == 100){
                        System.out.println("You continued fighting till the end of your days");
                        return 2;
                    }
                    if (hero.getHP() <= 0){
                        return 2;
                    }
                    ((Organism) monster).takeDamage((hero.getATK() + hero.getWvalue()));
                    System.out.println("You attacked the " + monster.getName() + " for " + (mhpcur - monster.getHP()) + " damage");
                    if (monster.getHP() <= 0){
                        System.out.println("You have killed the " + monster.getName());
                        System.out.println("You gained " + monster.getValue() + " experience points");
                        monsters.remove(monster);
                        hero.setExp(hero.getExp() + monster.getValue());
                        int r = Randomiser.Ranger(2, 1);
                        switch(r){
                            case 1:{
                                System.out.println("You didnt find anything of worth");
                                return 1;
                            }
                            case 2:{
                                int e = Randomiser.Ranger(3, 1);
                                int g = Randomiser.Ranger(10, 0);
                                String grade;
                                if (g > 8){
                                    grade = "Rare";
                                }
                                else if (g > 5){
                                    grade = "Uncommon";
                                }
                                else{
                                    grade = "Common";
                                }
                                switch (e){
                                    case 1:{
                                        Scanner scanner = new Scanner(System.in);
                                        int value = Randomiser.Random(grade);
                                        System.out.println("You have found a " + grade + " helm");
                                        System.out.println("Current equipment value: " + hero.getHvalue());
                                        System.out.println("New Equipment value: " + value);
                                        System.out.println("Would you like to equip this helm? (y/n)");
                                        String choice = scanner.nextLine();
                                        switch (choice){
                                            case "y":{
                                                hero.setHelmgrade(grade);
                                                hero.setHvalue(value);
                                                if (hero.getHP() > hero.getMHP()+ hero.getHvalue())
                                                    hero.setHP(hero.getMHP()+ hero.getHvalue());
                                                return 1;
                                            }
                                            case "n":{
                                                return 1;
                                            }
                                            default:{
                                                System.out.println("Invalid input");
                                            }
                                        }
                                    }
                                    case 2:{
                                        Scanner scanner = new Scanner(System.in);
                                        int value = Randomiser.Random(grade);
                                        System.out.println("You have found a " + grade + " armor set");
                                        System.out.println("Current equipment value: " + hero.getHvalue());
                                        System.out.println("New Equipment value: " + value);
                                        System.out.println("Would you like to equip this armor set? (y/n)");
                                        String choice = scanner.nextLine();
                                        switch (choice){
                                            case "y":{
                                                hero.setArmorgrade(grade);
                                                hero.setAvalue(value);
                                                return 1;
                                            }
                                            case "n":{
                                                return 1;
                                            }
                                            default:{
                                                System.out.println("Invalid input");
                                            }
                                        }
                                    }
                                    case 3:{
                                        Scanner scanner = new Scanner(System.in);
                                        int value = Randomiser.Random(grade);
                                        System.out.println("You have found a " + grade + " weapon");
                                        System.out.println("Current equipment value: " + hero.getHvalue());
                                        System.out.println("New Equipment value: " + value);
                                        System.out.println("Would you like to equip this weapon? (y/n)");
                                        String choice = scanner.nextLine();
                                        switch (choice){
                                            case "y":{
                                                hero.setWeapongrade(grade);
                                                hero.setWvalue(value);
                                                return 1;
                                            }
                                            case "n":{
                                                return 1;
                                            }
                                            default:{
                                                System.out.println("Invalid input");
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        monsters.remove(monster);
                    }
                    ((Organism) hero).takeDamage(monster.getATK());
                    System.out.println("The " + monster.getName() + " attacked you for " + (hhpcur - hero.getHP()) + " damage");
                }
            }
            case 2:{
                int age = 0;
                int mhpcur;
                int hhpcur;
                while (true){
                    mhpcur = monster.getHP();
                    hhpcur = hero.getHP();
                    age++;
                    if (age == 100){
                        System.out.println("You continued fighting till the end of your days");
                        return 2;
                    }
                    if (hero.getHP() <= 0){
                        return 2;
                    }
                    if (monster.getHP() <= 0){
                        System.out.println("You have killed the " + monster.getName());
                        System.out.println("You gained " + monster.getValue() + " experience points");
                        monsters.remove(monster);
                        hero.setExp(hero.getExp() + monster.getValue());
                        int r = Randomiser.Ranger(2, 1);
                        switch(r){
                            case 1:{
                                System.out.println("You didnt find anything of worth");
                                return 1;
                            }
                            case 2:{
                                int e = Randomiser.Ranger(3, 1);
                                int g = Randomiser.Ranger(10, 0);
                                String grade;
                                if (g > 8){
                                    grade = "Rare";
                                }
                                else if (g > 5){
                                    grade = "Uncommon";
                                }
                                else{
                                    grade = "Common";
                                }
                                switch (e){
                                    case 1:{
                                        Scanner scanner = new Scanner(System.in);
                                        int value = Randomiser.Random(grade);
                                        System.out.println("You have found a " + grade + " helm");
                                        System.out.println("Current equipment value: " + hero.getHvalue());
                                        System.out.println("New Equipment value: " + value);
                                        System.out.println("Would you like to equip this helm? (y/n)");
                                        String choice = scanner.nextLine();
                                        switch (choice){
                                            case "y":{
                                                hero.setHelmgrade(grade);
                                                hero.setHvalue(value);
                                                if (hero.getHP() > hero.getMHP()+ hero.getHvalue())
                                                    hero.setHP(hero.getMHP()+ hero.getHvalue());
                                                return 1;
                                            }
                                            case "n":{
                                                return 1;
                                            }
                                            default:{
                                                System.out.println("Invalid input");
                                            }
                                        }
                                    }
                                    case 2:{
                                        Scanner scanner = new Scanner(System.in);
                                        int value = Randomiser.Random(grade);
                                        System.out.println("You have found a " + grade + " armor set");
                                        System.out.println("Current equipment value: " + hero.getHvalue());
                                        System.out.println("New Equipment value: " + value);
                                        System.out.println("Would you like to equip this armor set? (y/n)");
                                        String choice = scanner.nextLine();
                                        switch (choice){
                                            case "y":{
                                                hero.setArmorgrade(grade);
                                                hero.setAvalue(value);
                                                return 1;
                                            }
                                            case "n":{
                                                return 1;
                                            }
                                            default:{
                                                System.out.println("Invalid input");
                                            }
                                        }
                                    }
                                    case 3:{
                                        Scanner scanner = new Scanner(System.in);
                                        int value = Randomiser.Random(grade);
                                        System.out.println("You have found a " + grade + " weapon");
                                        System.out.println("Current equipment value: " + hero.getHvalue());
                                        System.out.println("New Equipment value: " + value);
                                        System.out.println("Would you like to equip this weapon? (y/n)");
                                        String choice = scanner.nextLine();
                                        switch (choice){
                                            case "y":{
                                                hero.setWeapongrade(grade);
                                                hero.setWvalue(value);
                                                return 1;
                                            }
                                            case "n":{
                                                return 1;
                                            }
                                            default:{
                                                System.out.println("Invalid input");
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        monsters.remove(monster);
                    }
                    ((Organism) hero).takeDamage(monster.getATK());
                    System.out.println("The " + monster.getName() + " attacked you for " + (hhpcur - hero.getHP()) + " damage");
                    ((Organism) monster).takeDamage((hero.getATK() + hero.getWvalue()));
                    System.out.println("You attacked the " + monster.getName() + " for " + (mhpcur - monster.getHP()) + " damage");
                }
            }
        }
        return 0;
    }

    public int checkposition(Hero hero){
        if (px == x || py == y || px == 0 || py == 0){
            return 5;
        }
        for (Monster monster: monsters) {
            if (monster.getXpos() == px && monster.getYpos() == py){
                loop: while(true) {
                    System.out.println("You have encountered a " + monster.getName() + ", will you Fight(F) or will you flee(N)?");
                    Scanner scanner = new Scanner(System.in);
                    String i = scanner.nextLine();
                    switch (i) {
                        case "F": {
                            return fight(hero, monster, 1);
                        }
                        case "N": {
                            int r = Randomiser.Ranger(2, 1);
                            if (r == 2) {
                                return 4;
                            } else {
                                System.out.println("You failed to escape");
                                return fight(hero, monster, 2);
                            }
                        }
                        default: {
                            System.out.println("Invalid input");
                        }
                    }
                }
            }
        }
        return 0;
    }
    public void moveup(Hero hero){
        py -= 1;
        hero.setYpos(py);
    }
    public void movedown(Hero hero){
        py += 1;
        hero.setYpos(py);
    }
    public void moveleft(Hero hero){
        px -= 1;
        hero.setXpos(px);
    }
    public void moveright(Hero hero){
        px += 1;
        hero.setXpos(px);
    }
}
