package WeThinkCode.Swingy.Controller;

import WeThinkCode.Swingy.Model.Util.DB;
import WeThinkCode.Swingy.View.GUI.G_Main_menu;
import WeThinkCode.Swingy.View.Terminal.T_Main_menu;
import java.util.Scanner;

public class Launcher {
    public static void main (String args[]) {
        int choice;

        GameState inst = GameState.getInstance();
        try {
            DB.setup();
            loop: while(true) {
                System.out.println("Would you like to use the Terminal(T) or the GUI(G)?");
                Scanner scanner = new Scanner(System.in);
                String input = scanner.nextLine();
                switch (input) {
                    case "G": {
                        System.out.println("GUI view selected");
                        choice = 1;
                        break loop;
                    }
                    case "T": {
                        System.out.println("Terminal view selected");
                        choice = 2;
                        break loop;
                    }
                    default: {
                        System.out.println("Invalid response");
                    }
                }
            }
            switch (choice) {
                case 2 :{
                    T_Main_menu.run();
                    break;
                }
                case 1 :{
                    G_Main_menu.run();
                    break;
                }
            }
        }
        catch (Exception e){
            System.out.println(e);
        }
    }
}
