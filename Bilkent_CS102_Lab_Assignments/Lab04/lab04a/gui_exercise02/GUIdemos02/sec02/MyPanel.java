import java.awt.*;
import java.awt.event.*;

public class MyPanel extends Panel implements ActionListener
{
   // properties
   Label      label;
   TextField  tf;
   Panel p;
   Button b;
   
   // constructor
   public MyPanel()
   {
      //Button b;
      setLayout( new FlowLayout() );
      
      label = new Label( "Welcome to ONLINE Java");     
      add( label );   
      
      b = new Button( "ok");
      add( b);

      b.addActionListener( this);
      b.addActionListener( new MyActionListener() );
      b.addActionListener( new ActionListener() {
         public void actionPerformed( ActionEvent e)
         {
            System.out.println( "Button pressed from Anon Inner class ");
         } 
      });
     b.addActionListener( new MyOtherActionListener());
     add(b);
     
     
      tf = new TextField( 25);
      tf.addActionListener( new TFActionListener() );
      tf.addActionListener( new MyOtherTFActionListener());
      add( tf );
      tf.addActionListener( this );
      
      p = new Panel();
      p.setPreferredSize( new Dimension( 200, 200) );
      p.setBackground( Color.cyan);
      add( p);
   }
   
   // methods
   
   // this panel
   public void actionPerformed( ActionEvent e)
   {
      if ( e.getSource() != tf  ) 
         System.out.println( "Button pressed! ");
      else
         System.out.println( "TF enter pressed! ");
      
       //label.setText( "Button pressed!" ); 
      // label.setText( tf.getText() );
   }
   
   // inner class
   public class MyActionListener implements ActionListener
   {
      public void actionPerformed( ActionEvent e)
      {
         System.out.println( "Button pressed in innerClass");
         Graphics g;
         g = p.getGraphics();
         g.drawString( "xyz", 50, 50);
      }      
   }

   // inner class
   public class TFActionListener implements ActionListener
   {
      public void actionPerformed( ActionEvent e)
      {
         System.out.println( "TF in innerClass : " + tf.getText() );
      }      
   }
   
   //inner class
   public class MyOtherTFActionListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
         System.out.println("TextField enter key pressed");
         System.out.println( tf.getText());
         label.setText(tf.getText());
      }
   }
      
   
      
   }
