package sim;

import aircraft.Coordinates;

public class WeatherTower extends Tower{
    public String getWeather(Coordinates coordinates){
        return WeatherProvider.getCurrentWeather(coordinates);
    }
    void changeWeather(){
        this.conditionsChanged();
    }
}
