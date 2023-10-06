
// welcome to gambling
public class Die
{
    // properties
   int value;

    // constructors
   public Die( int dieValue) 
   {
      value = dieValue;
   }
  

    // methods
   public int roll()
   {
      value = (int) (Math.random()*6 + 1);
      return value;
   }
   public int getFaceValue()
   {
      return value;
   }
   public String toString()
   {
      return value + "";
   }  
}
