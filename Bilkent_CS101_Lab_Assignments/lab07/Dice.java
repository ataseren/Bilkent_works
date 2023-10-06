// values of dice
public class Dice
{
    // properties
    int value1;
    int value2;

    // constructors
    public Dice ( int dieValue1, int dieValue2) 
    {
       value1 = dieValue1;
       value2 = dieValue2;
    }


    // methods
    public int roll()
    {
       value1 = (int) (Math.random()*6 + 1);
       value2 = (int) (Math.random()*6 + 1);
       return value1 + value2;
    }
    
    public int getDie1FaceValue()
   {
      return value1;
   }
   
    public int getDie2FaceValue()
   {
      return value2;
   }
    
    public int getDiceTotal()
   {
      return value1 + value2;
   }
    
    public String toString()
   {
      return value1 + "\n" + value2;
   }  
    
}