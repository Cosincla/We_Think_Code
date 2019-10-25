package WeThinkCode.Swingy.Model.Util;

import lombok.Getter;
import lombok.Setter;

public class Equipment {
    @Getter @Setter private String weapon;
    @Getter @Setter private String armor;
    @Getter @Setter private String helmet;
    @Getter @Setter private int wvalue;
    @Getter @Setter private int avalue;
    @Getter @Setter private int hvalue;
    public Equipment(String weapon, int wvalue, String armor, int avalue, String helmet, int hvalue){
        this.weapon = weapon;
        this.wvalue = wvalue;
        this.armor = armor;
        this.avalue = avalue;
        this.helmet = helmet;
        this.hvalue = hvalue;
    }
}
