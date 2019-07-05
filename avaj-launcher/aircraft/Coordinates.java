package aircraft;

public class Coordinates {
    private int longitude;
    private int latitude;
    private int height;

    Coordinates(int longitude, int latitude, int height){
        if (longitude > 180)
            this.longitude = longitude - 360;
        else if (longitude < -180)
            this.longitude = longitude + 360;
        else
            this.latitude = latitude;
        if (longitude > 90)
            this.latitude = latitude - 180;
        else if (longitude < -90)
            this.latitude = latitude + 180;
        else
            this.latitude = latitude;
        if (height < 0)
            this.height = 0;
        else if (height > 100)
            this.height = 100;
        else
            this.height = height;
    }
    public void setLongitude(int i){ this.longitude = i; }
    public int getLongitude() {
        return longitude;
    }
    public void setLatitude(int i){
        this.latitude = i;
    }
    public int getLatitude() {
        return latitude;
    }
    public void setHeight(int i){
        this.height = i;
    }
    public int getHeight() {
        return height;
    }
}
