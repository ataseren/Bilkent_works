import java.util.Scanner;

/**
 * good old programming 
 * @author ata.seren
 * @version 28.11.2019
 */ 
public class DiceOldWay
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      int dice1 = 0;
      int dice2 = 0;
      
      // program code
      while(dice1 != 6 || dice2 != 6)
      {
         dice1 = (int) (Math.random()*6 + 1);
         dice2 = (int) (Math.random()*6 + 1);
         System.out.println( dice1 + "   " + dice2);
      }

   }

} // end class