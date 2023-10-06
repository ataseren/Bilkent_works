import java.util.Scanner;

/**
 * sixsixcounter
 * @author ata.seren
 * @version 28.11.2019
 */ 
public class DiceGameTest
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      DiceGame count;

      // program code
      count = new DiceGame(0);
      System.out.println(count.play());

   }

} // end class