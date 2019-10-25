package WeThinkCode.Swingy.Controller;

import javax.swing.*;

public class Nameverifier extends InputVerifier {
    @Override
    public boolean verify(JComponent input) {
        String ver = ((JTextArea) input).getText();
        if (ver.length() <= 10 && ver.length() > 0)
            return true;
        else {
            Errors.ename();
            ((JTextArea) input).setText("");
            return false;
        }
    }
}
