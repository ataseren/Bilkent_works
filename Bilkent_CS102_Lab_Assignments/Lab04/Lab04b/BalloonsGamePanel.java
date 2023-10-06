import java.awt.*;
import java.awt.event.*;
import java.util.Iterator;
import javax.swing.*;
import shapes.*;


public class BalloonsGamePanel extends JPanel 
{
   //variables
   final int DEFAULT_WIDTH = 800;
   final int DEFAULT_HEIGHT = 800;
   final int MAX_ELAPSED_TIME = 300;
   final int UPDATE_PERIOD = 100;
   final int INIT_BALLOONS = 25;
   final int MIN_BALLOONS = 15;  
   ShapeContainer balloons;
   Timer timer;
   JLabel pointsLabel = new JLabel();
   JLabel timeLabel = new JLabel();
   int points;
   int passedTime;
   MouseListener pin;
   
   
   //constructors
   public BalloonsGamePanel() 
   {
      this.add(this.pointsLabel);
      this.add(this.timeLabel);
      this.setBackground(Color.black);
      this.setPreferredSize(new Dimension(800, 800));
      this.pin = new Pin();
      this.timer = new Timer(100, new GrowListener());
      this.initGame();
   }
   
   //methods
   
   /**
    * initiates the game
    */    
   public void initGame() 
   {
      this.passedTime = 0;
      this.points = 0;
      this.pointsLabel.setText("Score: " + this.points);
      this.pointsLabel.setForeground(Color.white);
      this.timeLabel.setText("Time: " + this.passedTime);
      this.timeLabel.setForeground(Color.white);
      this.balloons = new ShapeContainer();
      this.addRandomBalloons(25, 800, 800);
      this.addMouseListener(this.pin);
      this.timer.start();
   }
   
   /**
    * adds random sized balloons to the game
    */    
   public void addRandomBalloons(int number, int width, int height) 
   {
      for (int i = 0; i < number; ++i) 
      {
         int x = (int)(Math.random() * (double)width);
         int y = (int)(Math.random() * (double)height);
         Balloon b = new Balloon(x, y);
         this.balloons.add(b);
      }
   }
   
   /**
    * method about drawing circles
    */    
   public void paintComponent(Graphics g)
   {
      super.paintComponent(g);
      Iterator it = this.balloons.iterator();
      while (it.hasNext()) 
      {
         ((Drawable)((Object)it.next())).draw(g);
      }
   }
   
   /**
    * about grow and timer stuff
    * @author ata.seren
    * @version 07.04.2020
    */  
   public class GrowListener implements ActionListener 
   {
      public GrowListener() 
      {
      }
      
      /**
       * classic action performer
       */  
      public void actionPerformed(ActionEvent e) 
      {
         Iterator it = BalloonsGamePanel.this.balloons.iterator();
         while (it.hasNext()) 
         {
            ((Balloon)it.next()).grow();
            BalloonsGamePanel.this.timeLabel.setText("Time: " + BalloonsGamePanel.this.passedTime);   
         }
         
         BalloonsGamePanel.this.balloons.removeSelected();
         if (BalloonsGamePanel.this.balloons.size() < 15)
         {
            BalloonsGamePanel.this.addRandomBalloons(1, BalloonsGamePanel.this.getWidth(), BalloonsGamePanel.this.getHeight());
         }
         
         BalloonsGamePanel.this.repaint();
         BalloonsGamePanel.this.passedTime++;
         if (BalloonsGamePanel.this.passedTime >= 100) 
         {
            BalloonsGamePanel.this.timer.stop();
            BalloonsGamePanel.this.removeMouseListener(BalloonsGamePanel.this.pin);
            int again = JOptionPane.showConfirmDialog(BalloonsGamePanel.this, "Play again? ", "GAME OVER", 0);
            if (again == 0) 
            {
               BalloonsGamePanel.this.initGame();
            }
         }
      }
   }
   
   /**
    * about mouse clicking
    * @author ata.seren
    * @version 07.04.2020
    */  
   public class Pin extends MouseAdapter {
      public Pin() 
      {
      }
      
      /**
       * mouse listener
       */  
      public void mousePressed(MouseEvent e) 
      {
         int popCount = BalloonsGamePanel.this.balloons.selectAllAt(e.getX(), e.getY());
         if (popCount >= 1) 
         {
            BalloonsGamePanel.this.points += popCount;
            BalloonsGamePanel.this.pointsLabel.setText("Points: " + BalloonsGamePanel.this.points);
            BalloonsGamePanel.this.timeLabel.setText("Time: " + BalloonsGamePanel.this.passedTime);
         }
      }
   } 
}