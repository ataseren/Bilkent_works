import java.awt.*;
import java.awt.event.*;

/**
 *  
 * @author 
 * @version 
 */ 
public class MyFrame extends Frame // implements WindowListener
{
   // properties

   // constructors
   public MyFrame()
   {
      Button b;
      Panel  p;
      
      // addWindowListener( this);
      addWindowListener( new MyWindowListener() );

      // setSize( 450, 300);
      setLocation( 250, 250);
      setLayout( new FlowLayout() );
      
      add( new MyPanel() );
      
//      p = new Panel();
//      p.setPreferredSize( new Dimension( 200, 200) );
//      p.setBackground( Color.cyan);
//      add( p);
      
      // add( new MyPanel() );
      // add( new MyPanel() );

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
   
   public class MyWindowListener extends WindowAdapter // MyWindowAdapter
   {
      @Override
      public void windowClosing( WindowEvent e)
      { 
         System.out.println( "Window closing" );
         System.exit( 0 );
         // dispose();
      }
   }
   
//   public class MyWindowAdapter implements WindowListener
//   {
//      public void windowActivated( WindowEvent e) {}
//      public void windowClosed( WindowEvent e) {}
//      public void windowClosing( WindowEvent e) {}
//      public void windowDeactivated( WindowEvent e) {}
//      public void windowDeiconified( WindowEvent e) {}
//      public void windowIconified( WindowEvent e) {}
//      public void windowOpened( WindowEvent e) {}
//   }
}