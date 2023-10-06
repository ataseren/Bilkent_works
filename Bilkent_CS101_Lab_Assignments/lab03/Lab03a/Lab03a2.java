import java.util.Scanner;

/**
 * first "if"
 * @author ata.seren
 * @version 24.10.2019
 */ 
public class Lab03a2
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
    
      
      // program code
      for ( int x = 0; x <= 50; x++ )
      {
        if (x%5 == 0)
        {
          System.out.println("Hi fives");
        }
        else if ( x%2 == 0)
        {
          System.out.println("Hi two");
        }
        else if ( x%3 == 0 || x%7 == 0)
        {
          System.out.println("Hi ThreeorSeven");
        }
        else
        {
          System.out.println("Hi others");
        }
      }
      

   }

} // end class