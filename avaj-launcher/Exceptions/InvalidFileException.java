package Exceptions;

public class InvalidFileException extends Exception{
    public InvalidFileException(String string){ super(string); }
    public String getMessage() { return super.getMessage(); }
}
