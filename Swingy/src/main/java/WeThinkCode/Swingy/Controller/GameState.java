package WeThinkCode.Swingy.Controller;

import WeThinkCode.Swingy.Controller.Map.Map;
import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import lombok.Getter;
import lombok.Setter;

import javax.swing.*;

public class GameState {

    // static variable single_instance of type Singleton
    private static GameState single_instance = null;

    @Setter @Getter private Hero myHero;
    @Setter @Getter private Map map;
    @Setter @Getter private JTextArea textArea;
    @Setter @Getter private JLabel lvl;
    @Setter @Getter private JLabel coo;
    @Setter @Getter private JLabel hp;
    @Setter @Getter private JLabel exp;
    @Setter @Getter private JLabel atk;
    @Setter @Getter private JLabel def;

    // private constructor restricted to this class itself
    private GameState() { }

    // static method to create instance of Singleton class
    public static GameState getInstance()
    {
        if (single_instance == null)
            single_instance = new GameState();

        return single_instance;
    }
}
