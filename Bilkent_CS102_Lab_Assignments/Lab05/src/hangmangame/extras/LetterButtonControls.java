package hangmangame.extras;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import javax.swing.border.*;

/**
 * LetterButtonControls - keyboard for MVC demo of Hangman, but general purpose.
 *
 * @author David
 * @version 1.00
 */
public class LetterButtonControls extends JPanel {

   public LetterButtonControls(String letters) {
      this(letters, 2, 13);
   }

   public LetterButtonControls(String letters, int rows, int cols) {
      setBorder(new TitledBorder("Choose a letter..."));
      setLayout(new GridLayout(rows, cols));

      for (int i = 0; i < letters.length(); i++) {
         JButton b = new JButton("" + letters.charAt(i));
         b.setMargin(new Insets(1, 2, 1, 2));
         add(b);
      }
   }

   public void addActionListener(ActionListener l) {
      Component[] buttons = getComponents();
      for (Component b : buttons) {
         ((JButton) b).addActionListener(l);
      }
   }

   public void setEnabledAll(boolean state) {
      for (Component c : getComponents()) {
         ((JButton) c).setEnabled(state);
      }
   }

   public void setDisabled(String letters) {
      letters = letters.toUpperCase();    // bug fix! ?think about this!
      for (Component c : getComponents()) {
         char ch = ((JButton) c).getText().charAt(0);
         ch = Character.toUpperCase(ch);  // bug fix!
         if (letters.indexOf(ch) >= 0) {
            ((JButton) c).setEnabled(false);
         }
      }
   }
}
