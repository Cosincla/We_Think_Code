package Exceptions;

public class InvalidLineArgumentsException extends Exception{
    public InvalidLineArgumentsException(String string){ super(string); }
    public String getMessage() { return super.getMessage(); }
}
