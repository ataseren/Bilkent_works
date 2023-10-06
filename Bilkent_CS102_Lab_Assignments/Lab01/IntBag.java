//bags of integers
public class IntBag{
  //properties
  int[] bag;
  int valid = 0;
  
  //constructors
  public IntBag()
  {
    bag = new int[100];
  }
  
  public IntBag( int desiredMax)
  {
    bag = new int[desiredMax];
  }
  
  //methods
  /**
   * adds a value to the collection
   * @param i value that will be added
   */
  public void add(int i)
  {
    bag[valid] = i;
    valid++;
  }
  
  /**
   * same with add method but adds at a spesific location
   * @param value value that will be added
   * @param loc location of the value
   */
  public void addTo(int value,int loc)
  {
      for (int i = valid; i > loc; i--)
      {
        bag[i] = bag[i - 1];
      }
      bag[loc] = value;
      valid++;
   }
  
  /**
   * to remove a value at a location
   * @param loc location of removed value
   */
  public void remove(int loc)
  {
    for (int i = loc + 1; i < valid; i++)
    { 
      bag[i - 1] = bag[i]; 
    }
    valid--;
  }
  
  /**
   * checks if the collection has the given value
   * @param value to be checked in the collection
   * @return some useful result
   */
  public boolean contains(int value)
  {
    for(int i = 0; i <= valid;i++)
    {
      if(bag[i] == value)
      {
        return true;
      }
    }
    return false;
  }
  
  /**
   * classic tostring method
   * @return collection values
   */
  public String toString()
  {
    String result="";
    for(int i = 0; i < valid;i++)
    {
      result = result +" "+ bag[i];
    }
    return result;
  }
  
  /**
   * shows the size of elements that have a value
   * @return filled elements' number
   */
  public int size()
  {
    return valid;
  }
  
  /**
   * gives a value of a location
   * @param loc the location of wanted value
   * @return value at a location
   */
  public int get(int loc)
  {
    return bag[loc];
  }
  
  /**
   * finds locations of given value
   * @param value is wanted value
   * @return indexes of locations
   */
  public String findAll(int value)
  {
    String index = "";
    for (int i = 0;i<valid;i++)
    {
      if(value==bag[i])
      {
        index = index + " " + i;
      }
    }
    return index;
  }
      
}
      
      
      
        
        
        
        
        
        