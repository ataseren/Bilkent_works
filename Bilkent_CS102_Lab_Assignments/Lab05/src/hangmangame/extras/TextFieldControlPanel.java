package hangmangame.extras;

import cs102.hangman.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class TextFieldControlPanel extends JPanel implements ActionListener 
{
  //properties
  private JTextField textField;
  private Hangman hangman;
  
  //constructors
  public TextFieldControlPanel(Hangman hangman)
  {
    super();
    this.hangman = hangman;
    textField = new JTextField(10);    
    this.add(textField);
    textField.addActionListener(this);
  }
  
  /**
    * actionlistener
    * @param e event
    */
  public void actionPerformed(ActionEvent e)
  {
    String str = textField.getText();
    for (int i = 0; i < str.length(); i++)
    {
      hangman.tryThis(str.charAt(i));
    }
    textField.setText("");
  }  
}