package WeThinkCode.Swingy.View.GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import WeThinkCode.Swingy.Controller.Errors;
import WeThinkCode.Swingy.Controller.GameState;
import WeThinkCode.Swingy.Controller.Map.Map;
import WeThinkCode.Swingy.Controller.Map.MapFactory;
import WeThinkCode.Swingy.Controller.Nameverifier;
import WeThinkCode.Swingy.Model.Entities.Factories.HeroFactory;
import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import WeThinkCode.Swingy.Model.Util.DB;
import WeThinkCode.Swingy.Model.Util.getstuff;

class G_New_char extends Frame{
    private static G_New_char nchar = new G_New_char();
    public static void run(){
        final String classes[] = {"Shield Hero", "Sword Hero", "Bow Hero", "Spear Hero"};
        final JLabel choice = new JLabel("<HTML><U>Please create your character:</HTML></U>");
        final JButton back = new JButton("Back");
        final JButton cont = new JButton("Continue");
        final JPanel left = new JPanel();
        final JLabel name = new JLabel("Name: ");
        final JLabel hp = new JLabel("Health:  ");
        final JLabel atk = new JLabel("Attack:  ");
        final JLabel def = new JLabel("Defence: ");
        final JTextArea Heroname = new JTextArea(0, 0);

        Heroname.setInputVerifier(new Nameverifier());
        final JList<String> list;

        Font fanciness = new Font("Arial", Font.ITALIC, 20);
        choice.setBounds(30, 10, 300, 150);
        choice.setFont(fanciness);

        back.setBounds(10, 10, 65, 40);
        cont.setBounds(190, 220, 90, 30);

        left.setBackground(Color.WHITE);
        left.setBounds(30, 130, 100, 80);

        hp.setBounds(170, 100, 100, 80);
        atk.setBounds(170, 130, 100, 80);
        def.setBounds(170, 160, 100, 80);

        Font mini = new Font("Arial", 0, 10);
        Heroname.setFont(mini);
        name.setFont(mini);
        name.setBounds(30, 215, 100, 15);
        Heroname.setBounds(60, 215, 70, 15);
        Heroname.setRows(30);

        list = new JList<>(classes);

        MouseListener moose = new MouseAdapter() {
            JLabel hpr = new JLabel();
            JLabel atkr = new JLabel();
            JLabel defr = new JLabel();
            public void mouseClicked(MouseEvent e) {
                String result = getstuff.Herostuff(classes[list.getSelectedIndex()]);
                hpr.setText(result.split(",")[0]);
                hpr.setBounds(230, 100, 100, 80);
                atkr.setText(result.split(",")[1]);
                atkr.setBounds(230, 130, 100, 80);
                defr.setText(result.split(",")[2]);
                defr.setBounds(230, 160, 100, 80);
                frame.add(hpr);
                frame.add(atkr);
                frame.add(defr);
                frame.revalidate();
                frame.repaint();
            }
        };

        list.addMouseListener(moose);
        left.add(list);
        frame.add(name);
        frame.add(Heroname);
        frame.add(hp);
        frame.add(atk);
        frame.add(def);
        frame.add(back);
        frame.add(cont);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(choice);
        frame.add(left);
        frame.setSize(320, 300);
        frame.setResizable(false);
        frame.setLayout(null);
        frame.setVisible(true);

        back.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.getContentPane().removeAll();
                G_Main_menu.run();
            }
        });

        cont.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (!Heroname.getText().isEmpty() && list.getSelectedIndex() > -1){
                    String schmuck = Heroname.getText();
                    String job = list.getSelectedValue();
                    Hero hero = HeroFactory.newHero(schmuck, job);
                    DB.saveHero(hero, 1, 4, 4);
                    GameState.getInstance().setMyHero(hero);
                    frame.getContentPane().removeAll();
                    Map map = MapFactory.newMap(1);
                    GameState.getInstance().setMap(map);
                    G_Game_menu.run();
                }
                else {
                    Errors.echar();
                }
            }
        });
    }
}
