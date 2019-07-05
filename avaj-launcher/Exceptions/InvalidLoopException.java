package Exceptions;

public class InvalidLoopException extends Exception {
    public InvalidLoopException(String string){ super(string); }
    public String getMessage() { return super.getMessage(); }
}
