package Exceptions;

public class InvalidAircraftTypeException extends Exception{
    public InvalidAircraftTypeException(String string){ super(string); }
    public String getMessage() { return super.getMessage(); }
}
