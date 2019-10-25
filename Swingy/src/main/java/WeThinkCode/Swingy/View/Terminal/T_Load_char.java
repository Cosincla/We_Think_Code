package WeThinkCode.Swingy.View.Terminal;

import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import WeThinkCode.Swingy.Model.Util.DB;
import javax.validation.constraints.NotNull;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class T_Load_char {
    public static boolean isNum(String num){
        try {
            Integer.parseInt(num);
            return true;
        }
        catch (Exception e){
            return false;
        }
    }
    public static void run(){
        Scanner scanner = new Scanner(System.in);
        List<String> choices = new ArrayList<>();
        try {
            String url = "jdbc:sqlite:swingy.db";
            Connection connection = DriverManager.getConnection(url);
            String name = "SELECT count(*) FROM heroes";
            Statement pstate = connection.createStatement();
            ResultSet res = pstate.executeQuery(name);
            int limit = res.getInt(1);
            res.close();
            pstate.close();
            @NotNull String choice = "";
            if (limit > 0){
                loop: while (true){
                    int i = 1;
                    String names = "SELECT `name` FROM heroes";
                    ResultSet rest = pstate.executeQuery(names);
                    System.out.println("Please choose a character:");
                    while (rest.next()){
                        System.out.println("(" + i + ") " + rest.getString(1));
                        choices.add(rest.getString(1));
                        i++;
                    }
                    String input = scanner.nextLine();
                    if (isNum(input)){
                        @NotNull int num = Integer.parseInt(input);
                        if (num >= 1 && num <= limit){
                            choice = choices.get(num - 1);
                            break loop;
                        }
                        else{
                            System.out.println("Invalid number");
                        }
                    }
                    else {
                        System.out.println("Invalid input");
                    }
                }
            }
            else {
                System.out.println("There are no characters to load.");
                connection.close();
                T_Main_menu.run();
            }
            String map = "SELECT map_lvl FROM heroes WHERE name LIKE '" + choice + "' ORDER BY name COLLATE NOCASE ASC";
            Statement ptate = connection.createStatement();
            ResultSet rest = ptate.executeQuery(map);
            int r = rest.getInt(1);
            rest.close();
            ptate.close();
            connection.close();
            Hero schmuck = DB.loadHero(choice);
            T_Game_menu.run(schmuck, r);
        }
        catch (Exception e){
            System.out.println(e);
            e.printStackTrace();
        }
    }
}
