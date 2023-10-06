package hangmangame.extras;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import cs102.hangman.*;

public class LetterButtonListener implements ActionListener
{
   
   // properties
   Hangman hangman;
   LetterButtonControls letterButtonControls;
   
   // constructors
   public LetterButtonListener( Hangman hangman) 
   {
      this.hangman = hangman;
   }
   
   //methods
   /**
    * actionlistener
    * @param event event
    */
   public void actionPerformed( ActionEvent event) 
   {
      ( ( JButton)event.getSource()).setEnabled( false);
      hangman.tryThis( ( ( JButton)event.getSource()).getActionCommand().charAt( 0));
   }
}

