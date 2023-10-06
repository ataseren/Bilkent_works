import java.util.*;
import javax.swing.*;
import java.awt.*;
/**
 * some stuff i still didn't totally understand (pot luck) 
 * @author ata.seren
 * @version 30.03.2020
 */ 

public class PotLuckTest
{  
  public static void main (String[] args)
  {
    PotLuck game = new PotLuck();
    JFrame frame = new JFrame ("POT LUCK");
    frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
    
    frame.getContentPane().add(game);   
    frame.pack();   
    frame.setVisible(true);
  }
  
}