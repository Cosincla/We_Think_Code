package WeThinkCode.Swingy.View.Terminal;

import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import WeThinkCode.Swingy.Controller.Map.*;
import WeThinkCode.Swingy.Model.Util.DB;

import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class T_Game_menu {
    public static void run(Hero hero, int map_lvl){
        try{
            Scanner scanner = new Scanner(System.in);
            Map map = MapFactory.newMap(map_lvl);
            map.start(hero);
            while (map.getMonsters().size() < ((map.getX() * map.getY())) * 0.3) {
                map.spawnMonsters();
            }
            map.lvlMonsters(map_lvl);
            loop: while (true){
                int i = map.checkposition(hero);
                map.checkhero(hero);
                switch (i){
                    case 1:{
                        System.out.println("You have survived");
                        break;
                    }
                    case 2:{
                        System.out.println("YOU DIED");
                        System.exit(0);
                    }
                    case 4:{
                        System.out.println("You fled from the monster");
                        break;
                    }
                    case 5:{
                        System.out.println("You have cleared the level");
                        map.clearMonsters();
                        hero.setHP(hero.getMHP() + hero.getHvalue());
                        run(hero, hero.getLVL());
                        break;
                    }
                }
                System.out.println("Quit[q] North[w] East[d] South[s] West[a] Character[c] Save[e]");
                System.out.println("x coordinate: " + map.getPx() + " y coordinate: " + map.getPy());
                String input = scanner.nextLine();
                switch (input){
                    case "q": {
                        System.exit(0);
                    }
                    case "w": {
                        map.moveup(hero);
                        break ;
                    }
                    case "d": {
                        map.moveright(hero);
                        break ;
                    }
                    case "s": {
                        map.movedown(hero);
                        break ;
                    }
                    case "a": {
                        map.moveleft(hero);
                        break ;
                    }
                    case "c": {
                        System.out.println("Hero: " + hero.getName());
                        System.out.println("Class: " + hero.getJob());
                        System.out.println("Level: " + hero.getLVL());
                        System.out.println("Experience: " + hero.getExp() + "/" + hero.getLevelup());
                        System.out.println("Health: " + hero.getHP() + "/" + (hero.getMHP() + hero.getHvalue()));
                        System.out.println("Attack: " + hero.getATK() + "(" + hero.getWvalue() + ")");
                        System.out.println("Defence: " + hero.getDEF() + "(" + hero.getAvalue() + ")\n");
                        break;
                    }
                    case "e": {
                        DB.saveHero(hero, map.getMap_lvl(), hero.getXpos(), hero.getYpos());
                        TimeUnit.SECONDS.sleep(1);
                        System.out.println("Save Successful");
                    }
                    default: {
                        System.out.println("Invalid input");
                    }
                }
            }
        }
        catch(Exception e){
            System.out.println(e);
            e.printStackTrace();
        }
    }
}
