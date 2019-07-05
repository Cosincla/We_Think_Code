package sim;

import java.io.*;

public class Typewriter {
    private File text = new File("simulation.txt");
    public Typewriter(String string){
        try {
            FileWriter fw = new FileWriter(text, true);
            fw.write(string + "\n");
            fw.close();
        }
        catch (FileNotFoundException e){
            System.out.println("Order a new one.");
        }
        catch (IOException e){
            System.out.println("Order a new one.");
        }
    }
}
