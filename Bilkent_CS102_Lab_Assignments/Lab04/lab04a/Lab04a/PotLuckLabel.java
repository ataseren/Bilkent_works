import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PotLuckLabel extends JPanel
{
  //variables
  int count;
  public JLabel label;
  
  //constructors
  public PotLuckLabel()
  {
    count = 0;
    label = new JLabel ("Pushes: " + count);
    add (label);   
    label.setVerticalAlignment  (JLabel.TOP);
    label.setHorizontalAlignment(JLabel.CENTER); 
    setPreferredSize (new Dimension(600, 40));
  }
  
  //methods
  public void setText(String string)
  {
    label.setText(string);
  }
}