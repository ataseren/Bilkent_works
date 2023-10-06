package shapes;
/**
 * rectangle
 * @author ata.seren 
 * @version 09.03.2020
 */ 
public class Rectangle extends Shape implements Selectable
{
  // properties
  double width;
  double height;
  boolean selected;
    
  // constructors
  public Rectangle (double widthRec, double heightRec)
  {
    width = widthRec;
    height = heightRec;
    int xLoc;
    int yLoc;
    selected = false;
  }
    
  // methods
  
  /**
   * computes rectangle's area
   * @return area
   */ 
  public double getArea()
  {
    double result = (width * height);
    return result;
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
  
  public Shape contains(int x, int y)
  {   
      if(xLoc == x && yLoc == y)
      {
        setSelected(true);
        return this;
      }  
    return null;
  }
  
}