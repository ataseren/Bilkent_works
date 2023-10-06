
import java.awt.Graphics;
import shapes.*;
import java.awt.Color;

public class Balloon extends Circle implements Drawable 
{
  //variables
  static final int DEFAULT_SIZE = 25;
  static final int SIZE_INCREMENT = 1;
  static final int MAX_SIZE = 100;
  
  public Balloon(int x, int y) 
  {
    super(25);
    this.setLocations(x, y);
  }

  /**
   * creates circles
   */  
  public void draw(Graphics g) 
  {    
    //int radius = this.getRadius();
    //    g.drawOval(this.getX() - radius, this.getY() - radius, radius * 2, radius * 2);
    int R = (int) (Math.random( )*256);
    int G = (int)(Math.random( )*256);
    int B= (int)(Math.random( )*256);
    Color randomColor = new Color(R, G, B);
    g.setColor(randomColor);
    int radius = this.getRadius();
    g.drawOval(this.getX() - radius, this.getY() - radius, radius * 2, radius * 2);
    //  g.fillOval(this.getX() - radius, this.getY() - radius, radius * 2, radius * 2);
  }
  
  /**
   * blows balloons (delete circles) 
   */  
  public void burst() 
  {
    this.setRadius(0);
    this.setSelected(true);
  }
  
  /**
   * grow balloons (increase circle's radius)
   */  
  public boolean grow() 
  {
    this.setRadius(this.getRadius() + 1);
    if (this.getRadius() > 100) 
    {
      this.burst();
    }
    return this.getRadius() != 0;
  }
}