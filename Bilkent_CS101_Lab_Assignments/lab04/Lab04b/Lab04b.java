import java.util.Scanner;

/**
 * processing
 * @author ata.seren
 * @version 27.10.2019
 */ 
public class Lab04b
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants
      final int LOOP_COUNT = 6;
      

      // variables
      int numCount;
      int n;
      double sum;
      double avg;
      int max = 0;
      int min = 2147483647;
      // this number is the max value in java

      // program code
      System.out.println("Please enter 6 numbers: ");
      numCount = 0;
      sum = 0;
      while(numCount < LOOP_COUNT)
      {
        n = scan.nextInt();
        sum = sum + n;
        numCount++;
        if(n > max)
        {
          max = n;
        }
        
        if(n < min)
        {
          min = n;
        }
      }
      avg = (sum / numCount);
      System.out.println("Sum is " + sum + " and there are " + numCount + " numbers.");
      System.out.println("Average is " + avg + ".");
      System.out.println("Max is " + max + " and min is " + min + ".");
        
        

   }

} // end class