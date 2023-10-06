import java.util.Scanner;

/**
 * first "if"
 * @author ata.seren
 * @version 24.10.2019
 */ 
public class Lab03a1
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      int odd = 0;
      int even = 0;
      
      // program code
      for ( int x = 0; x <= 50; x++ )
      {
        if ( x%2 == 0)
        {
         even++; 
        }
        else
        {
          odd++;
        }
        
      }
      System.out.println("odd numbers: " + odd );
      System.out.println("even numbers: " + even);
          

   }

} // end class