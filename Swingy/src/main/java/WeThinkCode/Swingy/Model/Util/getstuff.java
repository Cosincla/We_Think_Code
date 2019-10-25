package WeThinkCode.Swingy.Model.Util;

public class getstuff {
    private static getstuff stuff = new getstuff();

    public static String Herostuff(String name){
        switch (name){
            case "Shield Hero" :{
                return "10,1,3";
            }
            case "Sword Hero" :{
                return "7,2,3";
            }
            case "Bow Hero" :{
                return "8,3,2";
            }
            case "Spear Hero" :{
                return "9,2,3";
            }
            default: {
                return name;
            }
        }
    }
}
