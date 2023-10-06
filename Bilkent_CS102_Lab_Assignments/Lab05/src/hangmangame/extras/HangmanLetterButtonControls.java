package hangmangame.extras;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import cs102.hangman.*;

public class HangmanLetterButtonControls extends LetterButtonControls implements IHangmanView 
{
   
   // properties
   Hangman hangman;
   
   // constructors
   public HangmanLetterButtonControls( Hangman hangman) 
   {
      this( hangman.getAllLetters(), 13, 2);
      this.hangman = hangman;
   }
   
   public HangmanLetterButtonControls( String letters, int rows, int columns)
   {
      super( letters, rows, columns);
   }
   
   //methods
   /**
    * update view
    * @param hangman obj
    */
   public void updateView( Hangman hangman) 
   {
      setDisabled( hangman.getUsedLetters());
      if ( hangman.isGameOver() ) 
      {
         setEnabledAll( false);
      }
      if ( hangman.getUsedLetters().length() == 0 ) 
      {
         setEnabledAll( true);
      }
   }
}


