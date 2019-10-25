package WeThinkCode.Swingy.Model.Util;

import java.util.Random;

public class Randomiser {
    Randomiser rand = new Randomiser();
    public static int Random(String grade){
        int max;
        int min;
        switch (grade){
            case "Common":{
                max = 4;
                min = 1;
                break;
            }
            case "Uncommon":{
                max = 7;
                min = 3;
                break;
            }
            case "Rare":{
                max = 10;
                min = 6;
                break;
            }
            default: {
                max = 0;
                min = 0;
            }
        }
        Random random = new Random();
        int r = random.nextInt((max - min) + 1) + min;
        return r;
    }
    public static int Ranger(int max, int min){
        Random random = new Random();
        int r = random.nextInt((max - min) + 1) + min;
        return r;
    }
}
