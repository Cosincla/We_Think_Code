package sim;

import Exceptions.*;
import aircraft.*;

import java.io.*;
import java.util.ArrayList;
import java.util.List;


public class Simulator {
    private static WeatherTower weatherTower;
    private static List<Flyable> flyables = new ArrayList<>();

    public static void main(String[] arg) throws IOException {
        try {
            if (!arg[0].contains(".txt"))
                throw new InvalidFileException("Incorrect file type.");
            if (arg.length > 1)
                throw new InvalidFileCountException("Too many input files.");
            BufferedReader reader = new BufferedReader(new FileReader(arg[0]));
            String line = reader.readLine();
            if (line != null) {
                weatherTower = new WeatherTower();
                int simulations = Integer.parseInt(line);
                if (simulations <= Integer.MIN_VALUE || simulations <= 0 || simulations >= Integer.MAX_VALUE)
                    throw new InvalidLoopException("Invalid loop count");
                while ((line = reader.readLine()) != null) {
                    if (line.split(" ").length != 5)
                        throw new InvalidLineArgumentsException("Incorrect arguments to build an Aircraft");
                    if (!line.split(" ")[0].equals("Baloon") && !line.split(" ")[0].equals("Helicopter") && !line.split(" ")[0].equals("JetPlane"))
                        throw new InvalidAircraftTypeException("Invalid Aircraft type");
                    Flyable flyable = AircraftFactory.newAircraft(line.split(" ")[0], line.split(" ")[1], Integer.parseInt(line.split(" ")[2]), Integer.parseInt(line.split(" ")[3]), Integer.parseInt(line.split(" ")[4]));
                    flyables.add(flyable);
                }
                for (Flyable flyable : flyables) {
                    flyable.registerTower(weatherTower);
                }
                for (int i = 0; i < simulations; i++) {
                    weatherTower.changeWeather();
                }
            }
        }
        catch (FileNotFoundException e){
            System.out.println("File not found: " + arg[0]);
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Please specify scenario file.");
        }
        catch (IOException e){
            System.out.println("Error reading file: " + arg[0]);
        }
        catch (InvalidFileException e){
            System.out.println("Incorrect file type: " + arg[0]);
        }
        catch (InvalidLoopException e){
            System.out.println("Invalid number of executions: " + arg[0]);
        }
        catch (NumberFormatException e){
            System.out.println("Please use an integer");
        }
        catch (InvalidFileCountException e){
            System.out.println("Invalid number of input files, please only use one .txt file");
        }
        catch (InvalidLineArgumentsException e){
            System.out.println("Incorrect arguments to build an Aircraft");
        }
        catch (InvalidAircraftTypeException e){
            System.out.println("We don't have access to this kind of technology yet...");
        }
    }
}
