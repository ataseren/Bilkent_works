/**
 * rectangle
 * @author ata.seren 
 * @version 09.03.2020
 */ 
public abstract class Rectangle extends Shape
{
  // properties
  double width;
  double height;
    
  // constructors
  public Rectangle (double width, double height)
  {
    width = this.width;
    height = this.height;
  }
    
  // methods
  public double getArea()
  {
    return width * height;
  }
}