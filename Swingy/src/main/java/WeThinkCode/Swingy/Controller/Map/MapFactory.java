package WeThinkCode.Swingy.Controller.Map;

abstract public class MapFactory {
    static public Map newMap(int level){
        return new Map(level);
    }
}
