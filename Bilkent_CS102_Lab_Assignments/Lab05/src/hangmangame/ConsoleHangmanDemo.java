package hangmangame;

import cs102.hangman.*;
import hangmangame.extras.HangmanConsoleView;

/**
 * Simple console-based demo program!
 * @author david
 */
public class ConsoleHangmanDemo {
   
   public static void main(String[] args) {
      System.out.println("Hangman Game v1 ~ 2019");
      
      HangmanModel hm = new HangmanModel( new BasicSetup() );
      
      hm.addView( new HangmanConsoleView() );
      // hm.addView( new HangmanConsoleView() );
      
      hm.tryThis( 'e');
      hm.tryThis( 'i');
      hm.tryThis( 'B');
      hm.tryThis( 'D');
      
//      System.out.println("KnownSoFar      = " + hm.getKnownSoFar() );
//      System.out.println("AllLetters      = " + hm.getAllLetters() );
//      System.out.println("UsedLetters     = " + hm.getUsedLetters() );
//      System.out.println("IncorrectTries  = " + hm.getNumOfIncorrectTries() );
//      System.out.println("MaxAllowedTries = " + hm.getMaxAllowedIncorrectTries() );
//      System.out.println("HasLost         = " + hm.hasLost() );
//      System.out.println("GameOver        = " + hm.isGameOver() );
//      System.out.println();

   }
}
