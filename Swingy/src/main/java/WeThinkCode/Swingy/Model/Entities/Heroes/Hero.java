package WeThinkCode.Swingy.Model.Entities.Heroes;
import WeThinkCode.Swingy.Model.Entities.Entity;
import WeThinkCode.Swingy.Model.Util.Randomiser;
import lombok.Getter;
import lombok.Setter;
import javax.validation.constraints.NotNull;

public class Hero extends Entity {
    @Getter @Setter @NotNull protected String name;
    @Getter @Setter @NotNull protected String job;
    @Getter @Setter @NotNull protected String Helmgrade = "common";
    @Getter @Setter @NotNull protected int Hvalue;
    @Getter @Setter @NotNull protected String Armorgrade = "common";
    @Getter @Setter @NotNull protected int Avalue;
    @Getter @Setter @NotNull protected String Weapongrade = "common";
    @Getter @Setter @NotNull protected int Wvalue;
    @Getter @Setter @NotNull protected long exp = 0;
    @Getter @Setter @NotNull protected long levelup = getLVL() * 1000 + ((getLVL() - 1) * (getLVL() - 1)) * 450;

    Hero(String name) {
        super();
        this.name = name;
        Avalue = Randomiser.Random("Common");
        Hvalue = Randomiser.Random("Common");
        Wvalue = Randomiser.Random("Common");
    }
}
