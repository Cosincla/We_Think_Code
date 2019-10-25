package WeThinkCode.Swingy.Model.Util;

import WeThinkCode.Swingy.Model.Entities.Factories.HeroFactory;
import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import java.sql.*;
import java.util.concurrent.TimeUnit;

public class DB {
    private static DB db = new DB();
    private static String url = "jdbc:sqlite:swingy.db";

    public static void setupHero() {
        try {
            Connection connection = DriverManager.getConnection(url);
            String HTB = "CREATE TABLE IF NOT EXISTS heroes (\n"
                    + "name text PRIMARY KEY NOT NULL,\n"
                    + "health int NOT NULL,\n"
                    + "class text NOT NULL,\n"
                    + "level int NOT NULL,\n"
                    + "exp long NOT NULL,\n"
                    + "map_lvl int NOT NULL,\n"
                    + "xy text NOT NULL\n"
                    + ");";
            PreparedStatement pstate1 = connection.prepareStatement(HTB);
            pstate1.execute();
            pstate1.close();
            connection.close();
            TimeUnit.SECONDS.sleep(1);
        }
        catch (Exception e){
            System.out.println(e);
        }
    }
    public static void setupEquip() {
        try {
            Connection connection = DriverManager.getConnection(url);
            String ETB =  "CREATE TABLE IF NOT EXISTS equipment (\n"
                    + "hero text PRIMARY KEY NOT NULL,\n"
                    + "weapon text NOT NULL,\n"
                    + "wvalue int NOT NULL,\n"
                    + "armor text NOT NULL,\n"
                    + "avalue int NOT NULL,\n"
                    + "helmet text NOT NULL,\n"
                    + "hvalue int NOT NULL\n"
                    + ");";
            PreparedStatement pstate2 = connection.prepareStatement(ETB);
            pstate2.execute();
            pstate2.close();
            connection.close();
            TimeUnit.SECONDS.sleep(1);
        }
        catch (Exception e){
            System.out.println(e);
        }

    }
    public static void setup(){
        try {
            setupHero();
            setupEquip();
        }
        catch (Exception e){
            System.out.println(e);
        }
    }
    private static void UpdateHero(Hero hero, int maplvl, String pos){
        try{
            Connection connection = DriverManager.getConnection(url);
            String chsave = "REPLACE INTO heroes(`name`, `class`, `health`, `level`, `exp`, `map_lvl`, `xy`) "
                    + "VALUES (?, ?, ?, ?, ?, ?, ?);";
            PreparedStatement pstate = connection.prepareStatement(chsave);
            pstate.setString(1, hero.getName());
            pstate.setString(2, hero.getJob());
            pstate.setInt(3, hero.getHP());
            pstate.setInt(4, hero.getLVL());
            pstate.setLong(5, hero.getExp());
            pstate.setInt(6, maplvl);
            pstate.setString(7, pos);
            pstate.executeUpdate();
            pstate.close();
            connection.close();
            System.out.println("Character saved.");

        }
        catch (Exception e){
            System.out.println(e);
            e.printStackTrace();
        }
    }
    private static void UpdateEquip(Hero hero, int maplvl, String pos){
        try{
            Connection connection = DriverManager.getConnection(url);
            String eqsave = "REPLACE INTO equipment(`hero`, `weapon`, `wvalue`, `armor`, `avalue`, `helmet`, `hvalue`) "
                    + "VALUES (?, ?, ?, ?, ?, ?, ?)";
            PreparedStatement estate = connection.prepareStatement(eqsave);
            estate.setString(1, hero.getName());
            estate.setString(2, hero.getWeapongrade());
            estate.setInt(3, hero.getWvalue());
            estate.setString(4, hero.getArmorgrade());
            estate.setInt(5, hero.getAvalue());
            estate.setString(6, hero.getHelmgrade());
            estate.setInt(7, hero.getHvalue());
            estate.executeUpdate();
            estate.close();
            connection.close();
            TimeUnit.SECONDS.sleep(1);
            System.out.println("Equipment saved.");
        }
        catch (Exception e){
            System.out.println(e);
            e.printStackTrace();
        }
    }
    public static void saveHero(Hero hero, int maplvl, int px, int py) {
        try {
            String pos = px + "/" + py;
            UpdateHero(hero, maplvl, pos);
            TimeUnit.SECONDS.sleep(1);
            UpdateEquip(hero, maplvl, pos);
            TimeUnit.SECONDS.sleep(1);
            System.out.println(hero.getName() + " saved");
        } catch (Exception e) {
            System.out.println(e);
            e.printStackTrace();
        }
    }
    private static Stats getHero(String name){
        Stats info = null;
        try {
            Connection connection = DriverManager.getConnection(url);
            String LoadC = "SELECT * FROM heroes WHERE name LIKE ?;";
            PreparedStatement pstate1 = connection.prepareStatement(LoadC);
            pstate1.setString(1, name);
            ResultSet stats = pstate1.executeQuery();
            info = new Stats(stats.getString(1), stats.getString(2), stats.getString(3), stats.getInt(4), stats.getInt(5), stats.getInt(6), stats.getString(7));
            stats.close();
            pstate1.close();
            connection.close();
            TimeUnit.SECONDS.sleep(1);
        }
        catch (Exception e){
            System.out.println(e);
        }
        return info;
    }
    private static Equipment getEquip(String name){
        Equipment stuff = null;
        try{
            Connection connection = DriverManager.getConnection(url);
            String LoadE = "SELECT * FROM equipment WHERE hero LIKE ?;";
            PreparedStatement pstate2 = connection.prepareStatement(LoadE);
            pstate2.setString(1, name);
            ResultSet crap = pstate2.executeQuery();
            stuff = new Equipment(crap.getString(2), crap.getInt(3), crap.getString(4), crap.getInt(5), crap.getString(6), crap.getInt(7));
            crap.close();
            pstate2.close();
            connection.close();
            TimeUnit.SECONDS.sleep(1);
        }
        catch (Exception e){
            System.out.println(e);
        }
        return stuff;
    }
    public static Hero loadHero(String name){
        Hero schmuck;
        Stats info;
        Equipment stuff;
        try {
            info = getHero(name);
            stuff = getEquip(name);
            schmuck = HeroFactory.newHero(info, stuff);
            System.out.println(schmuck.getName() + " loaded");
            TimeUnit.SECONDS.sleep(1);
            return schmuck;
        }
        catch (Exception e){
            System.out.println(e);
            e.printStackTrace();
            System.exit(1);
        }
        return null;
    }
}
