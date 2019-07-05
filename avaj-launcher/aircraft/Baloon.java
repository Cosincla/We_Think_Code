package aircraft;
import sim.Typewriter;
import sim.WeatherTower;

public class Baloon extends Aircraft implements Flyable {
    private WeatherTower weatherTower;
    String report = "Baloon#" + this.name + "(" + this.id + ")";

    Baloon(String name, Coordinates coordinates){
        super(name, coordinates);
    }
    public void updateConditions() {
        if (this.coordinates.getHeight() > 0) {
            String weather = this.weatherTower.getWeather(coordinates);
            switch (weather) {
                case "SNOW": {
                    new Typewriter(report + ": Freezing my tits off.");
                    this.coordinates.setHeight(this.coordinates.getHeight() - 15);
                    break;
                }
                case "RAIN": {
                    new Typewriter(report + ": God bless the rains down in Africa.");
                    this.coordinates.setHeight(this.coordinates.getHeight() - 5);
                    break;
                }
                case "FOG": {
                    new Typewriter(report + ": Making a detour through Silent Hill.");
                    this.coordinates.setHeight(this.coordinates.getHeight() - 3);
                    break;
                }
                case "SUN": {
                    new Typewriter(report + ": Praise the Sun.");
                    this.coordinates.setLongitude(this.coordinates.getLongitude() + 2);
                    if (this.coordinates.getLongitude() > 180)
                        this.coordinates.setLongitude(this.coordinates.getLongitude() - 360);
                    this.coordinates.setHeight(this.coordinates.getHeight() + 4);
                    if (this.coordinates.getHeight() > 100)
                        this.coordinates.setHeight(100);
                    break;
                }
            }
        }
        if (this.coordinates.getHeight() <= 0){
            new Typewriter(report + "landing.");
            new Typewriter("Tower says: " + report + " unregistered from weather tower.");
            weatherTower.unregister(this);
            }
    }
    public void registerTower(WeatherTower weatherTower){
        this.weatherTower = weatherTower;
        weatherTower.register(this);
        new Typewriter("Tower says: " + report + " registered to weather tower.");
    }
}
