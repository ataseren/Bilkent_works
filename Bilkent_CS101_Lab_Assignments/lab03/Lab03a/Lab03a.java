import java.util.Scanner;

/**
 * first "if"
 * @author ata.seren
 * @version 24.10.2019
 */ 
public class Lab03a
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables

      // program code
      for ( int x = 0; x <= 50; x++ )
      {
        if ( x >= 12 && x<= 25)
        {
         System.out.println("out of range 12-25"); 
        }
        else
        {
        System.out.println(x);
        }
      }

   }

} // end class