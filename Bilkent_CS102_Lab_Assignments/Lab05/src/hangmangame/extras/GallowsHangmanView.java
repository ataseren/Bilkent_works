package hangmangame.extras;

import cs102.hangman.*;
import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;

// I got this from Internet.
public class GallowsHangmanView extends JPanel implements IHangmanView
{
   //properties
   private Rectangle2D.Double[] rec;
   private Line2D.Double[] manLines;
   private Ellipse2D.Double manHead;
   private Hangman hangman;
   private Shape[] man;
   private String secretWord;
   private String tries;
   private String usedWords;
   private static final int PANEL_HEIGHT = 300, WIDTH = 300, X = 0, Y = 50;
   
   //constructors
   public GallowsHangmanView(Hangman hangman)
   {
      super();
      this.hangman = hangman;
      this.setBackground(Color.yellow);
      rec = new Rectangle2D.Double[4];
      manLines = new Line2D.Double[5];
      man = new Shape[6];
      secretWord = "";
      tries = "";
      usedWords = "";
      
      rec[0] = (new Rectangle2D.Double(20 + X, 400 + Y, 300, 50));//bottom rectangle
      rec[1] = (new Rectangle2D.Double(60 + X, 40 + Y, 20, 360));//from bottom vertical
      rec[2] = (new Rectangle2D.Double(80 + X, 40 + Y, 120, 20));//top horizontal
      rec[3] = (new Rectangle2D.Double(194 + X, 60 + Y, 6, 30));//top vertical
      
      manHead = new Ellipse2D.Double(167 + X, 90 + Y, 60, 60);
      
      manLines[0] = new Line2D.Double(manHead.getX() + (manHead.getWidth() / 2), 
                                      manHead.getY() + manHead.getHeight(), 
                                      manHead.getX() + (manHead.getWidth() / 2)
                                         ,manHead.getY() + manHead.getHeight() + 70);
      //leftLeg
      manLines[1] = new Line2D.Double(manLines[0].getX2(), manLines[0].getY2(), manLines[0].getX2() - 30, 
                                      manLines[0].getY2() + 60);
      //right leg
      manLines[2] = new Line2D.Double(manLines[0].getX2(), manLines[0].getY2(), manLines[0].getX2() + 30, 
                                      manLines[1].getY2()); 
      //left arm
      manLines[3] = new Line2D.Double(manLines[0].getX2(), 
                                      ((manLines[0].getY2() - manLines[0].getY1()) / 5) + manLines[0].getY1()
                                         , manLines[0].getX1() - 28, 
                                      ((manLines[0].getY2() - manLines[0].getY1()) / 4) + manLines[0].getY1() + 40);
      //right arm
      manLines[4] = new Line2D.Double(manLines[0].getX2(), manLines[3].getY1(), manLines[0].getX1() + 28, 
                                      manLines[3].getY2());
      
      
      man[0] = manHead;
      for (int i = 1; i < man.length; i++)
      {
         man[i] = manLines[i - 1];
      }
   }
   
   /**
    * viewer of gallows
    * @param hangman obj of hangman
    */
   public void updateView(Hangman hangman)
   {
      if ( !hangman.isGameOver() ) 
      {
         secretWord = hangman.getKnownSoFar();
         tries = "Tries: " + hangman.getNumOfIncorrectTries();
         usedWords = "Used letters: " + hangman.getUsedLetters();
      }
      else
      {
         if ( hangman.hasLost() ){
            secretWord = "Oops";
            tries = "You lost!";
            usedWords = "You used: " + hangman.getUsedLetters();
         }
         else{
            secretWord = "In " + hangman.getNumOfIncorrectTries();
            tries = "Congratulations, you won!!";
            usedWords = "You used: " + hangman.getUsedLetters();
         }
      }
      repaint();
   }
   
   /**
    * to paint stuff
    * @param g painted stuff
    */
   public void paintComponent(Graphics g)
   {
      super.paintComponent(g);
      Graphics2D g2 = (Graphics2D) g;
      
      g2.setPaint(Color.black);
      for(int i = 0; i < rec.length; i++)
      {
         g2.fill(rec[i]);
      }
      
      for(int i = 0; i < hangman.getNumOfIncorrectTries(); i++)
      {
         g2.draw(man[i]);
      }
      
      g2.setPaint(Color.blue);
      
      g2.drawString(secretWord, (int)rec[0].getX() + 20, (int)(rec[0].getY() + rec[0].getHeight()) + 60);
      g2.drawString(usedWords, (int)rec[0].getX() + 20, (int)(rec[0].getY() + rec[0].getHeight()) + 120);
      g2.drawString(tries, (int)(rec[1].getX() + rec[1].getWidth()) + 15, (int)rec[0].getY() - 50);
      
   }
   
}