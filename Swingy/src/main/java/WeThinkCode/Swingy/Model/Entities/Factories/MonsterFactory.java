package WeThinkCode.Swingy.Model.Entities.Factories;

import WeThinkCode.Swingy.Model.Entities.Monsters.Bitch;
import WeThinkCode.Swingy.Model.Entities.Monsters.Dragon;
import WeThinkCode.Swingy.Model.Entities.Monsters.Monster;
import WeThinkCode.Swingy.Model.Entities.Monsters.Skeleton;


abstract public class MonsterFactory {
    public static Monster newMonster(int x, int y, int rand) {
        if (rand >= 0 && rand <= 6){ return new Bitch(x, y); }
        else if (rand >= 7 && rand <= 9){ return new Skeleton(x, y); }
        else { return new Dragon(x, y); }
    }
}
