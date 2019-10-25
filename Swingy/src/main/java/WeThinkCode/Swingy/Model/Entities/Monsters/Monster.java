package WeThinkCode.Swingy.Model.Entities.Monsters;
import WeThinkCode.Swingy.Model.Entities.Entity;
import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.NotNull;

public class Monster extends Entity {
    @Getter @Setter @NotNull protected int value;
    @Getter @Setter @NotNull protected String name;

    Monster() {
        super();
    }
}
