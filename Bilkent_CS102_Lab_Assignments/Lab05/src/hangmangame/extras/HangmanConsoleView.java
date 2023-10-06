package hangmangame.extras;

import cs102.hangman.Hangman;
import cs102.hangman.IHangmanView;

/**
 * Simple console (text-only) view of the associated hangman model.
 * @author david
 */
public class HangmanConsoleView implements IHangmanView {

   @Override
   public void updateView( Hangman hm) {
      System.out.println("KnownSoFar      = " + hm.getKnownSoFar() );
      System.out.println("AllLetters      = " + hm.getAllLetters() );
      System.out.println("UsedLetters     = " + hm.getUsedLetters() );
      System.out.println("IncorrectTries  = " + hm.getNumOfIncorrectTries() );
      System.out.println("MaxAllowedTries = " + hm.getMaxAllowedIncorrectTries() );
      System.out.println("HasLost         = " + hm.hasLost() );
      System.out.println("GameOver        = " + hm.isGameOver() );
      System.out.println();      
   }
   
}
