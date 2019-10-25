package WeThinkCode.Swingy.View.Terminal;

import WeThinkCode.Swingy.Model.Entities.Factories.HeroFactory;
import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import WeThinkCode.Swingy.Model.Util.DB;

import javax.validation.constraints.NotNull;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class T_New_char {
    public static boolean isNum(String num){
        try {
            Integer.parseInt(num);
            return true;
        }
        catch (Exception e){
            return false;
        }
    }
    private static T_New_char nc = new T_New_char();
    public static void run(){
        @NotNull String name;
        Scanner scanner = new Scanner(System.in);
        loop : while (true){
            System.out.println("Please enter Name:");
            name = scanner.nextLine();
            if (name.length() >= 1 && name.length() <= 10){
                break loop;
            }
            else {
                System.out.println("Please use a name between 1 - 10 characters.");
            }
        }
        System.out.flush();
        String type;
        loop : while(true){
            System.out.println("Please choose a class:");
            System.out.println("(1) Shield Hero");
            System.out.println("(2) Sword Hero");
            System.out.println("(3) Bow Hero");
            System.out.println("(4) Spear Hero");
            @NotNull String in = scanner.nextLine();
            if (isNum(in)) {
                switch (in) {
                    case "1": {
                        type = "ShieldHero";
                        break loop;
                    }
                    case "2": {
                        type = "SwordHero";
                        break loop;
                    }
                    case "3": {
                        type = "BowHero";
                        break loop;
                    }
                    case "4": {
                        type = "SpearHero";
                        break loop;
                    }
                    default: {
                        System.out.println("Invalid option");
                    }
                }
            }
            else
                System.out.println("Invalid option");
        }
        Hero hero = HeroFactory.newHero(name, type);
        DB.saveHero(hero, 1, 4, 4);
        T_Game_menu.run(hero, 1);
    }
}
