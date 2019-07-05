package aircraft;
import sim.Typewriter;
import sim.WeatherTower;

public class JetPlane extends Aircraft implements Flyable {
    private WeatherTower weatherTower;
    String report = "JetPlane#" + this.name + "(" + this.id + ")";

    JetPlane(String name, Coordinates coordinates){
        super(name, coordinates);
    }
    public void updateConditions() {
        if (this.coordinates.getHeight() > 0) {
            String weather = this.weatherTower.getWeather(coordinates);
            switch (weather) {
                case "SNOW": {
                    new Typewriter(report + ": Freezing my tits off.");
                    this.coordinates.setHeight(this.coordinates.getHeight() - 7);
                    break;
                }
                case "RAIN": {
                    new Typewriter(report + ": God bless the rains down in Africa.");
                    this.coordinates.setLatitude(this.coordinates.getLatitude() + 5);
                    if (this.coordinates.getLatitude() > 90){
                        this.coordinates.setLatitude(this.coordinates.getLatitude() - 180);
                    }
                    break;
                }
                case "FOG": {
                    new Typewriter(report + ": Making a detour through Silent Hill.");
                    this.coordinates.setLatitude(this.coordinates.getLatitude() + 1);
                    if (this.coordinates.getLatitude() > 90){
                        this.coordinates.setLatitude(this.coordinates.getLatitude() - 180);
                    }
                    break;
                }
                case "SUN": {
                    new Typewriter(report + ": Praise the Sun.");
                    this.coordinates.setLatitude(this.coordinates.getLatitude() + 10);
                    if (this.coordinates.getLatitude() > 90){
                        this.coordinates.setLatitude(this.coordinates.getLatitude() - 180);
                    }
                    this.coordinates.setHeight(this.coordinates.getHeight() + 2);
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
        new Typewriter("Tower says: " + report + " registered to weather tower.");
        weatherTower.register(this);
    }
}
