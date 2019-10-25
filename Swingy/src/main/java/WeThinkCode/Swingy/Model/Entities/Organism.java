package WeThinkCode.Swingy.Model.Entities;

public interface Organism {
    public void takeDamage(int offence);
    public void heal(int health);
    public void levelup(int level);
}
