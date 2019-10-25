package WeThinkCode.Swingy.Model.Entities.Factories;
import WeThinkCode.Swingy.Model.Entities.Heroes.*;
import WeThinkCode.Swingy.Model.Entities.Organism;
import WeThinkCode.Swingy.Model.Util.Equipment;
import WeThinkCode.Swingy.Model.Util.Stats;

abstract public class HeroFactory {
    static public Hero newHero(String name, String heroclass) {
        switch (heroclass) {
            case "ShieldHero": {
                return new ShieldHero(name);
            }
            case "Shield Hero": {
                return new ShieldHero(name);
            }
            case "SwordHero": {
                return new SwordHero(name);
            }
            case "Sword Hero": {
                return new SwordHero(name);
            }
            case "BowHero": {
                return new BowHero(name);
            }
            case "Bow Hero": {
                return new BowHero(name);
            }
            case "SpearHero": {
                return new SpearHero(name);
            }
            case "Spear Hero": {
                return new SpearHero(name);
            }
        }
        return null;
    }
    static public Hero newHero(Stats stats, Equipment equipment) {
        Hero schmuck;
        switch(stats.getJob()) {
            case "shield": {
                schmuck = new ShieldHero(stats.getName());
                break;
            }
            case "sword": {
                schmuck = new SwordHero(stats.getName());
                break;
            }
            case "bow": {
                schmuck = new BowHero(stats.getName());
                break;
            }
            case "spear": {
                schmuck = new SpearHero(stats.getName());
                break;
            }
            default:
                return null;
        }
        ((Organism) schmuck).levelup(stats.getLvl() - 1);
        schmuck.setHP(Integer.parseInt(stats.getHealth()));
        schmuck.setLVL(stats.getLvl());
        schmuck.setLevelup(schmuck.getLVL() * 1000 + ((schmuck.getLVL() - 1) * (schmuck.getLVL() - 1)) * 450);
        schmuck.setExp(stats.getExp());
        schmuck.setXpos(stats.getX());
        schmuck.setYpos(stats.getY());
        schmuck.setWeapongrade(equipment.getWeapon());
        schmuck.setArmorgrade(equipment.getArmor());
        schmuck.setHelmgrade(equipment.getHelmet());
        schmuck.setAvalue(equipment.getAvalue());
        schmuck.setWvalue(equipment.getWvalue());
        schmuck.setHvalue(equipment.getHvalue());
        return schmuck;
    }
}
