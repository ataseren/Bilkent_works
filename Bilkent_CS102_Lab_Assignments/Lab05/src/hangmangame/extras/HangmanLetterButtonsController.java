package hangmangame.extras;

import java.awt.event.*;
import cs102.hangman.*;
import javax.swing.*;

public class HangmanLetterButtonsController implements ActionListener
{
   
   //properties 
   private Hangman hangman;
   
   //constructors
   public HangmanLetterButtonsController(Hangman hangman)
   {
      this.hangman = hangman;
   }
   
   //methods (actionlistener)
   /**
    * actionlistener
    * @param e event
    */
   public void actionPerformed(ActionEvent e)
   {
      JButton b = (JButton) e.getSource();
      char c = b.getText().charAt(0);
      hangman.tryThis(c);
   }
}