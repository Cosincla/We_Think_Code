package sim;

import aircraft.Flyable;

import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

abstract public class Tower{
    private List<Flyable> flyables = new CopyOnWriteArrayList<>();
    public void register(Flyable flyable){
        if (flyables.contains(flyable)){
            return;
        }
        flyables.add(flyable);
    }
    public void unregister(Flyable flyable){
        if (flyables.contains(flyable)) {
            flyables.remove(flyable);
        }
    }
    protected void conditionsChanged(){
        for (Flyable flyable : flyables) {
            flyable.updateConditions();
        }
    }
}