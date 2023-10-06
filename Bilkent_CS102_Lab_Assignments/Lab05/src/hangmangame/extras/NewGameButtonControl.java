package hangmangame.extras;

import javax.swing.*;
import java.awt.event.*;
import cs102.hangman.*;


public class NewGameButtonControl extends JButton implements ActionListener, IHangmanView
{
  //properties
  private Hangman hangman;
  
  //constructors
  public NewGameButtonControl(Hangman hangman)
  {
    super("New Game");
    this.hangman = hangman;
    this.addActionListener(this);
    this.setEnabled(false);
  }
  
  //methods
  /**
    * actionlistener
    * @param event event
    */
  public void actionPerformed(ActionEvent event)
  {
    hangman.initNewGame();
    this.setEnabled(false); // disables after one use    
  }
  
  /**
    * updates the view
    * @param hangman obj
    */
  public void updateView(Hangman hangman)
  {
    if (hangman.isGameOver())
    {
      this.setEnabled(true);
    }
  }  
}