package WeThinkCode.Swingy.Model.Util;

import lombok.Getter;
import lombok.Setter;

public class Stats {
    @Getter @Setter private String name;
    @Getter @Setter private String health;
    @Getter @Setter private String job;
    @Getter @Setter private int lvl;
    @Getter @Setter private int exp;
    @Getter @Setter private int map_lvl;
    @Getter @Setter private int x;
    @Getter @Setter private int y;

    public Stats(String name, String health, String job, int lvl, int exp, int map_lvl, String pos){
        this.name = name;
        this.health = health;
        this.job = job;
        this.lvl = lvl;
        this.exp = exp;
        this.map_lvl = map_lvl;
        this.x = Integer.parseInt(pos.split("/")[0]);
        this.y = Integer.parseInt(pos.split("/")[1]);
    }
}
