// how many times to roll
public class DiceGame
{
    // properties
   int dice;

    // constructors
   public DiceGame ( int dice1 ) 
    {
       dice = dice1;    
    }

    // methods
   public int play()
   {
      int count = 0;
      while(dice != 12)
      {
      dice = (int) (Math.random()*6 + 1) + (int) (Math.random()*6 + 1);
      count++;
      }
      return count;
   }
      
      

}