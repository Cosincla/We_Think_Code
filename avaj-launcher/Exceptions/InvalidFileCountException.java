package Exceptions;

public class InvalidFileCountException extends Exception {
    public InvalidFileCountException(String string){ super(string); }
    public String getMessage() { return super.getMessage(); }
}
