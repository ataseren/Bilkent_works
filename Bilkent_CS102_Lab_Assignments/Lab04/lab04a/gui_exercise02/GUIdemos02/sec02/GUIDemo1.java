import java.util.Scanner;
import java.awt.*;
// import java.awt.Frame;
// import java.awt.Button;

/**
 * GUIDemo1
 * @author Sec02
 * @version 12/03/2020
 */ 
public class GUIDemo1
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      MyFrame  mf;
      
      Frame  f;
      Button b;

      // program code
      System.out.println( "Start...");

      mf = new MyFrame();
      // new MyFrame();
      // new MyFrame();
      
//      f = new Frame();
//      f.setSize( 450, 300);
//      
//      f.setLayout( new FlowLayout() );
//
//      b = new Button( "Hello");
//      f.add( b);
//      f.add(  new Button( "Time to go home!" ) );
//      
//      f.setVisible( true);

      
      System.out.println( "End.");
   }

}