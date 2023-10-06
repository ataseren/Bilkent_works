import java.util.ArrayList;

/**
 *  
 * @author 
 * @version 
 */ 
public class ShapeContainer
{
  // properties
  ArrayList<Shape> container;
    
  // constructors
  public ShapeContainer()
  {
    container = new ArrayList<Shape>();
  }
    
  // methods
  public void add (Shape s)
  {
    container.add(s);
    System.out.println("Shape added.");
  }

}
