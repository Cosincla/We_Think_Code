package WeThinkCode.Swingy.View.Terminal;

import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class T_Main_menu {
    private static T_Main_menu main = new T_Main_menu();
    public static void run() {
        Scanner scanner = new Scanner(System.in);
        int choice;
        try {
            loop:
            while (true) {
                System.out.println("Welcome to Swingy, please choose an option:");
                System.out.println("(1) New Game");
                System.out.println("(2) Load Game");
                String response = scanner.nextLine();
                switch (response) {
                    case "1": {
                        choice = 1;
                        break loop;
                    }
                    case "2": {
                        choice = 2;
                        break loop;
                    }
                    default: {
                        System.out.println("Invalid Response");
                    }
                }
            }
            switch (choice) {
                case 1: {
                    T_New_char.run();
                    break;
                }
                case 2: {
                    T_Load_char.run();
                    break;
                }
                default: {
                    System.out.println("Invalid input");
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
