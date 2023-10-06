import java.util.Scanner;

/**
 * first "if"
 * @author ata.seren
 * @version 24.10.2019
 */ 
public class Lab03a3
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables

      // program code
      System.out.println("Please enter a number to find the sum of numbers between 1 and number which you entered: ");
      int n = scan.nextInt();
      int sumOfLoop = 0;
      for ( int x = 0; x <= n; x++ )
      {
       sumOfLoop = sumOfLoop + x;
      }
      if (sumOfLoop == (n*(n+1)/2))
      {
        System.out.println("they are same");
      }
      System.out.println(sumOfLoop);

   }

} // end class