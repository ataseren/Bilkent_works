/**
 * circle 
 * @author ata.seren 
 * @version 09.03.2020
 */ 
public abstract class Circle extends Shape
{
  // properties
  double radius;
    
  // constructors
  public Circle (double radius)
  {
    radius = this.radius;
  }
    
  // methods
  public double getArea()
  {
    return Math.PI * radius * radius;
  }
}