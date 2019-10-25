package WeThinkCode.Swingy.View.GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import WeThinkCode.Swingy.Controller.Errors;
import WeThinkCode.Swingy.Controller.GameState;
import WeThinkCode.Swingy.Controller.Map.Map;
import WeThinkCode.Swingy.Controller.Map.MapFactory;
import WeThinkCode.Swingy.Model.Entities.Heroes.Hero;
import WeThinkCode.Swingy.Model.Util.DB;

class G_Load_char extends Frame{
    private static G_New_char nchar = new G_New_char();
    public static void run() {
        final String classes[] = {"Shield Hero", "Sword Hero", "Bow Hero", "Spear Hero"};
        final JLabel choice = new JLabel("<HTML><U>Please choose your character:</HTML></U>");
        final JButton back = new JButton("Back");
        final JButton cont = new JButton("Continue");
        final JPanel left = new JPanel();
        final JScrollPane sleft = new JScrollPane(left);
        sleft.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        sleft.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        final JLabel job = new JLabel("Weapon:");
        final JLabel lvl = new JLabel("Level: ");
        final JLabel map = new JLabel("Area:  ");
        final JList<String> list;

        try {
            String url = "jdbc:sqlite:swingy.db";
            Connection connection = DriverManager.getConnection(url);
            String name = "SELECT count(*) FROM heroes";
            Statement pstate = connection.createStatement();
            ResultSet res = pstate.executeQuery(name);
            int limit = res.getInt(1);
            res.close();
            pstate.close();
            if (limit < 0) {
                JOptionPane.showMessageDialog(frame, "No characters to load");
                frame.getContentPane().removeAll();
                G_Main_menu.run();
            } else {
                String names = "SELECT `name`, `class`, `level`, `map_lvl` FROM heroes ORDER BY name COLLATE NOCASE ASC";
                ResultSet rest = pstate.executeQuery(names);
                DefaultListModel model = new DefaultListModel();
                final List<String> crap = new ArrayList<>();
                while (rest.next()) {
                    model.addElement(rest.getString(1));
                    crap.add(rest.getString(2) + "," + rest.getString(3) + "," + rest.getString(4));
                }
                rest.close();
                list = new JList<>(model);
                Font fanciness = new Font("Arial", Font.ITALIC, 20);
                choice.setBounds(30, 10, 300, 150);
                choice.setFont(fanciness);
                back.setBounds(10, 10, 65, 40);
                cont.setBounds(190, 220, 90, 30);
                sleft.setBackground(Color.WHITE);
                sleft.setBounds(30, 130, 100, 80);
                job.setBounds(170, 100, 100, 80);
                lvl.setBounds(170, 130, 100, 80);
                map.setBounds(170, 160, 100, 80);
                connection.close();

                MouseListener moose = new MouseAdapter() {
                    JLabel jobr = new JLabel();
                    JLabel lvlr = new JLabel();
                    JLabel mapr = new JLabel();

                    public void mouseClicked(MouseEvent e) {
                        String result = crap.get(list.getSelectedIndex());
                        jobr.setText(result.split(",")[0]);
                        jobr.setBounds(230, 100, 100, 80);
                        lvlr.setText(result.split(",")[1]);
                        lvlr.setBounds(230, 130, 100, 80);
                        mapr.setText(result.split(",")[2]);
                        mapr.setBounds(230, 160, 100, 80);
                        frame.add(jobr);
                        frame.add(lvlr);
                        frame.add(mapr);
                        frame.revalidate();
                        frame.repaint();
                    }
                };

                list.addMouseListener(moose);
                left.add(list);
                frame.add(job);
                frame.add(lvl);
                frame.add(map);
                frame.add(back);
                frame.add(cont);
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.add(choice);
                frame.add(sleft);
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
                        if (list.getSelectedIndex() > -1) {
                            String result = crap.get(list.getSelectedIndex());
                            Hero jackass = DB.loadHero(list.getSelectedValue());
                            frame.getContentPane().removeAll();
                            GameState.getInstance().setMyHero(jackass);
                            Map map = MapFactory.newMap(Integer.parseInt(result.split(",")[2]));
                            GameState.getInstance().setMap(map);
                            G_Game_menu.run();
                        } else {
                            Errors.elchar();
                        }
                    }
                });
            }

        }
        catch (Exception e) {
            System.out.println(e);
        }
    }
}
