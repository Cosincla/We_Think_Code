package WeThinkCode.Swingy.View.GUI;

import WeThinkCode.Swingy.Controller.GUI_event_handler;
import WeThinkCode.Swingy.Controller.GameState;
import WeThinkCode.Swingy.Model.Util.DB;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class G_Game_menu extends Frame{
    private static G_Game_menu game = new G_Game_menu();
    public static void run(){
        final JLabel choice = new JLabel("<HTML><U>" + GameState.getInstance().getMyHero().getName() + "</HTML></U>");
        JTextArea right = new JTextArea();
        right.setEditable(false);
        right.setLineWrap(true);
        right.setWrapStyleWord(true);
        GameState.getInstance().setTextArea(right);
        final JScrollPane sright = new JScrollPane(right);

        final JLabel level = new JLabel("<HTML><U>Level:</U></HTML>");
        JLabel lvl = new JLabel();
        GameState.getInstance().setLvl(lvl);
        GameState.getInstance().getLvl().setText(String.valueOf(GameState.getInstance().getMyHero().getLVL()));

        final JLabel coord = new JLabel("<HTML><U>Location:</U></HTML>");
        JLabel coo = new JLabel();
        GameState.getInstance().setCoo(coo);
        GameState.getInstance().getCoo().setText("(" + GameState.getInstance().getMyHero().getXpos() + "/" + GameState.getInstance().getMyHero().getYpos() + ")");

        final JLabel health = new JLabel("<HTML><U>Health:</U></HTML>");
        JLabel hp = new JLabel();
        GameState.getInstance().setHp(hp);
        GameState.getInstance().getHp().setText(GameState.getInstance().getMyHero().getHP() + "/" + (GameState.getInstance().getMyHero().getMHP() + GameState.getInstance().getMyHero().getHvalue()));

        final JLabel EXP = new JLabel("<HTML><U>Exp:</U></HTML>");
        JLabel exp = new JLabel();
        GameState.getInstance().setExp(exp);
        GameState.getInstance().getExp().setText(GameState.getInstance().getMyHero().getExp() + "/" + GameState.getInstance().getMyHero().getLevelup());

        final JLabel Attack = new JLabel("<HTML><U>Attack:</U></HTML>");
        JLabel atk = new JLabel();
        GameState.getInstance().setAtk(atk);
        GameState.getInstance().getAtk().setText(String.valueOf(GameState.getInstance().getMyHero().getATK() + GameState.getInstance().getMyHero().getWvalue()));

        final JLabel Defence = new JLabel("<HTML><U>Defence:</U></HTML>");
        JLabel def = new JLabel();
        GameState.getInstance().setDef(def);
        GameState.getInstance().getDef().setText(String.valueOf(GameState.getInstance().getMyHero().getDEF() + GameState.getInstance().getMyHero().getAvalue()));

        final JButton save = new JButton("Save");
        save.setBounds(55, 400, 80,40);
        final JButton N = new JButton("North");
        N.setBounds(60, 290, 70, 30);
        final JButton S = new JButton("South");
        S.setBounds(60, 350, 70, 30);
        final JButton F = new JButton("East");
        F.setBounds(100, 320, 70, 30);
        final JButton W = new JButton("West");
        W.setBounds(20, 320, 70, 30);

        health.setBounds(30, 70, 100, 80);
        level.setBounds(30, 100, 100, 80);
        EXP.setBounds(30, 130, 100, 80);
        coord.setBounds(30, 160, 100, 80);
        Attack.setBounds(30, 190, 100, 80);
        Defence.setBounds(30, 220, 100, 80);

        GameState.getInstance().getHp().setBounds(90, 70, 100, 80);
        GameState.getInstance().getLvl().setBounds(90, 100, 100, 80);
        GameState.getInstance().getExp().setBounds(70, 130, 100, 80);
        GameState.getInstance().getCoo().setBounds(100, 160, 100, 80);
        GameState.getInstance().getAtk().setBounds(90, 190, 100, 80);
        GameState.getInstance().getDef().setBounds(90, 220, 100, 80);

        Font fanciness = new Font("Arial", Font.ITALIC, 20);
        choice.setBounds(150, 0, 300, 90);
        choice.setFont(fanciness);
        JLabel mapl = new JLabel(String.valueOf(GameState.getInstance().getMap().getMap_lvl()));

        sright.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        sright.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);
        sright.setBounds(190, 70, 200, 380);

        GameState.getInstance().getMap().start(GameState.getInstance().getMyHero());
        while (GameState.getInstance().getMap().getMonsters().size() < ((GameState.getInstance().getMap().getX() * GameState.getInstance().getMap().getY())) * 0.3) {
            GameState.getInstance().getMap().spawnMonsters();
        }
        GameState.getInstance().getMap().lvlMonsters(GameState.getInstance().getMap().getMap_lvl() - 2);

        N.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                GameState.getInstance().getTextArea().append("You moved North.\n");
                GameState.getInstance().getMap().moveup(GameState.getInstance().getMyHero());
                GUI_event_handler.event_status();
                GameState.getInstance().getCoo().setText("(" + GameState.getInstance().getMyHero().getXpos() + "/" + GameState.getInstance().getMyHero().getYpos() + ")");
                GUI_event_handler.levelup();
                frame.revalidate();
                frame.repaint();
            }
        });

        S.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                GameState.getInstance().getTextArea().append("You moved South.\n");
                GameState.getInstance().getMap().movedown(GameState.getInstance().getMyHero());
                GUI_event_handler.event_status();
                GameState.getInstance().getCoo().setText("(" + GameState.getInstance().getMyHero().getXpos() + "/" + GameState.getInstance().getMyHero().getYpos() + ")");
                GUI_event_handler.levelup();
                frame.revalidate();
                frame.repaint();
            }
        });

        F.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                GameState.getInstance().getTextArea().append("You moved East.\n");
                GameState.getInstance().getMap().moveright(GameState.getInstance().getMyHero());
                GUI_event_handler.event_status();
                GameState.getInstance().getCoo().setText("(" + GameState.getInstance().getMyHero().getXpos() + "/" + GameState.getInstance().getMyHero().getYpos() + ")");
                GUI_event_handler.levelup();
                frame.revalidate();
                frame.repaint();
            }
        });

        W.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                GameState.getInstance().getTextArea().append("You moved West.\n");
                GameState.getInstance().getMap().moveleft(GameState.getInstance().getMyHero());
                GUI_event_handler.event_status();
                GameState.getInstance().getCoo().setText("(" + GameState.getInstance().getMyHero().getXpos() + "/" + GameState.getInstance().getMyHero().getYpos() + ")");
                GUI_event_handler.levelup();
                frame.revalidate();
                frame.repaint();
            }
        });

        save.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DB.saveHero(GameState.getInstance().getMyHero(), GameState.getInstance().getMap().getMap_lvl(), GameState.getInstance().getMyHero().getXpos(), GameState.getInstance().getMyHero().getYpos());
                GameState.getInstance().getTextArea().append("Save successful.\n");
            }
        });

        frame.add(level);
        frame.add(lvl);
        frame.add(health);
        frame.add(hp);
        frame.add(EXP);
        frame.add(exp);
        frame.add(coord);
        frame.add(coo);
        frame.add(Attack);
        frame.add(atk);
        frame.add(Defence);
        frame.add(def);
        frame.add(choice);
        frame.add(sright);
        frame.add(mapl);
        frame.add(save);
        frame.add(N);
        frame.add(S);
        frame.add(F);
        frame.add(W);
        frame.setSize(400, 480);
        frame.setResizable(false);
        frame.setLayout(null);
        frame.setVisible(true);
    }
}