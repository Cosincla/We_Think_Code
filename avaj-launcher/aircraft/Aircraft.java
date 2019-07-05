package aircraft;

abstract class Aircraft {
    protected long id;
    protected String name;
    protected Coordinates coordinates;
    private static long idCounter = 0;

    protected Aircraft(String name, Coordinates coordinates) {
        nextId();
        this.name = name;
        this.coordinates = coordinates;
    }

    private long nextId() {
        this.id = ++idCounter;
        return idCounter;
    }
}
