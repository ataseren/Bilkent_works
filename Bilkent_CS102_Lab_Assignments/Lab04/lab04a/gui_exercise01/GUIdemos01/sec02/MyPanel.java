import java.awt.*;
import javax.swing.*;

public class MyPanel extends JPanel
{
   
   public MyPanel()
   {
      JButton b;
      
      //setLayout( new FlowLayout() );
      
      add( new JLabel( "Welcome to ONLINE Java") );   
      b = new JButton( "Hello");
      add( b);
     
      add( new JTextField( 25) );
   }
   
}
