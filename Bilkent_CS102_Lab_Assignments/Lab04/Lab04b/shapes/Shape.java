package shapes;
/**
 * shape
 * @author ata.seren 
 * @version 09.03.2020
 */ 
public abstract class Shape implements Locatable
{
  // properties
  int xLoc;
  int yLoc;
  boolean selected;
  
  // constructors
  
  // methods
  public abstract double getArea(); 
  
  /**
   * set a location value to a shape
   * @param a x value
   * @param b y value
   */
  public void setLocations(int x, int y)
  {
    xLoc = x;
    yLoc = y;
    selected = selected;
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
  
  
  
}