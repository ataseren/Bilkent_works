import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PotLuck extends JPanel
{
  
  //properties
  private final int ROW = 5;
  private final int COLUMN = 5;
  private final int RES_BUTTON = ROW*COLUMN + 1;
  
  private int count;
  private ArrayList<JButton> buttons;
  private PotLuckLabel label;
  private JButton button;
  private JButton butRes;
  Random rand = new Random();
  int  prize;
  JPanel buttonPanel;
  
  //constructors
  public PotLuck()
  {    
    prize = rand.nextInt(ROW*COLUMN);   
    butRes = new JButton("Restart");
    butRes.setVisible(false);
    label = new PotLuckLabel();
    this.add(label, BorderLayout.NORTH);
    
    buttons = new ArrayList<JButton>();
    
    for( int i = 0; i < ROW*COLUMN; i++ )
    {
      button = new JButton ("*");
      buttons.add(button);
    }
    
    for( int a = 0; a < ROW*COLUMN; a++ )
    {    
      buttons.get(a).addActionListener(new ButtonListener(a));           
    }
    butRes.addActionListener(new ButtonListener(RES_BUTTON));
        
    JPanel buttonPanel = new JPanel(new GridLayout(ROW, COLUMN));
    
    for( int b = 0; b < ROW*COLUMN; b++ )
    {
      buttonPanel.add(buttons.get(b));
    }    
    this.add(buttonPanel);
    this.add(butRes,BorderLayout.SOUTH);
    setPreferredSize (new Dimension(600, 300));
    
    
  }
  
  //inner class
  private class ButtonListener implements ActionListener
  {
    int index;
    
    public ButtonListener(int index)
    {
      this.index = index;
    }
    
    public void actionPerformed (ActionEvent event)
    {
      count++;
      if(index == prize)
      {
        label.setText("You found the prize in " + count + "  tries.");
        count = 0;
        prize = rand.nextInt(ROW*COLUMN);
        buttons.get(index).setBackground(Color.GREEN);
        for(int q = 0; q < ROW*COLUMN; q++)
        {
          buttons.get(q).setEnabled(false);
        }
        butRes.setVisible(true);
      }
      else if(index == RES_BUTTON)
      {
        for(int q = 0; q < ROW*COLUMN; q++)
        {
          buttons.get(q).setEnabled(true);
          buttons.get(q).setBackground(null);
        }
        butRes.setVisible(false);
        count--;
      }       
      else
      {
        label.setText("You pushed: " + count);
        buttons.get(index).setEnabled(false);
      }     
    }
  }
  

}