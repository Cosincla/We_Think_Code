package WeThinkCode.Swingy.View.GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class G_Main_menu extends Frame{
    private static G_Main_menu menu = new G_Main_menu();
    public static void run(){
        final JButton button1 = new JButton("New Game");
        final JButton button2 = new JButton("Load Game");
        final JLabel label1 = new JLabel("<HTML><U>Swingy</U></HTML>");
        Font fanciness = new Font("Arial", Font.ITALIC + Font.BOLD, 20);

        label1.setBounds(115, 10, 150, 150);
        label1.setFont(fanciness);
        label1.setVisible(true);

        button1.setBounds(50, 120, 200, 50);
        button2.setBounds(50, 171, 200, 50);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(label1);
        frame.add(button1);
        frame.add(button2);
        frame.setSize(300, 270);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setResizable(false);

        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                G_New_char.run();
            }
        });
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                G_Load_char.run();
             }
        });
    }
}
