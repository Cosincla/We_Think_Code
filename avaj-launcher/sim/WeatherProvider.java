package sim;

import aircraft.Coordinates;

import java.util.Random;

public class WeatherProvider {
    private static WeatherProvider weatherProvider = new WeatherProvider();
    private static String[] weather = { "SNOW", "RAIN", "FOG", "SUN"};

    private WeatherProvider(){}
    public static WeatherProvider getWeatherProvider() { return weatherProvider; }
    public static String getCurrentWeather(Coordinates coordinates) {
        Random random = new Random();
        int r = random.nextInt(4);
        return weather[r];
    }
}
