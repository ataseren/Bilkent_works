import javax.swing.*;
import java.awt.*;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JComponent;


public class MyDrawingPanel extends JPanel
{
   public MyDrawingPanel()
   {
      setPreferredSize(new Dimension(300,250)); 
      setLayout( new FlowLayout() );
      setBackground(Color.YELLOW); 
   }
   public MyDrawingPanel(int width, int height)
   {
      setPreferredSize(new Dimension(width,height));
      setLayout( new FlowLayout() );
      setBackground(Color.BLUE);      
}
   public void changeBg(String color)
   {
      if(color.toLowerCase().equals("pink"))
         setBackground(Color.PINK);
      if(color.toLowerCase().equals("orange"))
         setBackground(Color.ORANGE);
      if(color.toLowerCase().equals("red"))
         setBackground(Color.RED);
      if(color.toLowerCase().equals("black"))
         setBackground(Color.BLACK);
      if(color.toLowerCase().equals("cyan"))
         setBackground(Color.CYAN);
      if(color.toLowerCase().equals("dark gray"))
         setBackground(Color.DARK_GRAY);
      if(color.toLowerCase().equals("green"))
         setBackground(Color.GREEN);
      if(color.toLowerCase().equals("white"))
         setBackground(Color.WHITE);
   }
   
   public void paintComponent(Graphics g)
   {
      super.paintComponent(g);
      g.setColor(Color.BLACK);
      g.fillRect(0, 0, 200, 200);
      g.setColor(Color.RED);
      g.fillOval(getWidth()/4, getHeight()/4, 
                 getWidth()/2, getHeight()/2);
      g.setColor(Color.CYAN);
      g.fillRect(200,200,150,100);
      g.drawLine(20,20,300,300);
      g.setColor(Color.RED);
      g.drawString("dude",40,60);
   }
}