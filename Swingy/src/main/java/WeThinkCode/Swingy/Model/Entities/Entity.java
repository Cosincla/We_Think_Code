package WeThinkCode.Swingy.Model.Entities;

import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.NotNull;

public abstract class Entity {
    @Getter @Setter @NotNull protected int HP;
    @Getter @Setter @NotNull protected int mHP;
    @Getter @Setter @NotNull protected int mHPup;
    @Getter @Setter @NotNull protected int DEF;
    @Getter @Setter @NotNull protected int DEFup;
    @Getter @Setter @NotNull protected int ATK;
    @Getter @Setter @NotNull protected int ATKup;
    @Getter @Setter @NotNull protected int LVL = 1;
    @Getter @Setter @NotNull protected int xpos;
    @Getter @Setter @NotNull protected int ypos;

    public Entity(){}
}
