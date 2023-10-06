package shapes;
/**
 * square 
 * @author ata.seren 
 * @version 09.03.2020 
 */ 
public class Square extends Rectangle
{
  // properties
  double side;
  boolean selected;
  
  // constructors
  public Square(double sideS)
  {
    super(sideS,sideS);
    side = sideS;
    int xLoc;
    int yLoc;
    selected = false;
  }
  
   
  // methods
  /**
   * computes square's area
   * @return area
   */  
  public double getArea()
  {
    Rectangle rec = new Rectangle(side,side);
    return rec.getArea();
  }
  
 /**
   * set a location value to a shape
   * @param a x value
   * @param b y value
   */
  public void setLocations(int x, int y)
  {
    xLoc = x;
    yLoc = y;
  }
    
  /**
   * gets a shape's x value
   * @return x value
   */
  public int getX()
  {
    return xLoc;
  }
 
  /**
   * gets a shape's y value
   * @return y value
   */
  public int getY()
  {
    return yLoc;
  }
  
  /**
   * gets a shape's selection value
   * @return selection value
   */
  public boolean getSelected()
  {
     return selected;
  }
  
  /**
   * sets a shape's selection value
   * @param i desired value
   */
  public void setSelected(boolean i)
  {
     if(i)
     { 
        selected = true;
     }
     else
     {
        selected = false;
     }
  }
  
  
}