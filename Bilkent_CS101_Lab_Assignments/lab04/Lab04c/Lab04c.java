import java.util.Scanner;

/**
 * processing 2
 * @author ata.seren
 * @version 30.10.2019
 */ 
public class Lab04c
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      boolean negativeValue;
      double sum;
      double n;
      double min = 2147483647;
      double max = 0;
      double average;
      int numCount;

      // program code
      System.out.println("Please enter numbers:");
      negativeValue = false;
      sum = 0;
      numCount = 0;
      while(negativeValue == false)
      {
        n = scan.nextDouble();
        if(n < 0)
        {
          negativeValue = true;
        }
        else
        {
          numCount++;
          sum = n + sum; 
          if(n > max)
          {
            max = n;
          }
        
          if(n < min)
          {
            min = n;
          }  
        }
   
      }
      average = (sum / numCount);
      System.out.println("Sum is " + sum + " and there are " + numCount + " numbers.");
      System.out.println("Average is " + average + ".");
      System.out.println("Max is " + max + " and min is " + min + ".");
        

        
        

   }

} // end class
