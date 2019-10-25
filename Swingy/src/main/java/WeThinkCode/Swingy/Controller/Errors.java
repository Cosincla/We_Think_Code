package WeThinkCode.Swingy.Controller;

import WeThinkCode.Swingy.View.GUI.Frame;

import javax.swing.*;

public class Errors extends Frame {
    private static Errors er = new Errors();
    public static void ename(){
        JOptionPane.showMessageDialog(frame, "Please use between 1 - 10 characters");
    }
    public static void echar(){
        JOptionPane.showMessageDialog(frame, "Please choose a class and a name");
    }
    public static void elchar(){
        JOptionPane.showMessageDialog(frame, "Please choose a character");
    }
}
