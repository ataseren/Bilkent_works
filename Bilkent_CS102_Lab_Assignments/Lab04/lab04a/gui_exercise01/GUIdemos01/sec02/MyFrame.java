import java.awt.*;
import javax.swing.*;
/**
 *  
 * @author 
 * @version 
 */ 
public class MyFrame extends JFrame
{
   // properties

   // constructors
   public MyFrame()
   {
      JButton b;
      JPanel  p;
      
      // setSize( 450, 300);
      setLayout( new FlowLayout() );
      
      add( new MyPanel() );
      MyDrawingPanel panelNew;
      panelNew = new MyDrawingPanel();
      panelNew.changeBg("blue");
      add( panelNew);
      //add( new MyDrawingPanel(100,200));
      
      
      

//      p = new Panel();
//      p.setLayout( new FlowLayout() );
//      
//      p.add( new Label( "Welcome to ONLINE Java") );
//      
//      b = new Button( "Hello");
//      p.add( b);
//      // add(  new Button( "Time for a break!" ) );
//      
//      p.add( new TextField( 25) );
      
//      add(p);
      
      pack();
      setVisible( true);      
   }

   // methods
     
}