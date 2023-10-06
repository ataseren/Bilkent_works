import java.util.Scanner;
import java.lang.Math;

/**
 * gardening in a better way
 * @author ata.seren
 * @version 24.10.2019
 */ 
public class Lab03b1
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);
      
      // constants

      // variables
      double firstValue;
      double secondValue;
      double thirdValue;
      double s;
      double area;
      double flowerNumDouble;
      double flowerNumInt;

      // program code
     System.out.println("Please enter your values of triangle garden: ");
     firstValue = scan.nextDouble();
     secondValue = scan.nextDouble();
     thirdValue = scan.nextDouble();
     s = (firstValue + secondValue + thirdValue)/2;
     area = Math.sqrt(s*(s-firstValue)*(s-secondValue)*(s-thirdValue));
     flowerNumDouble = area*17;
     flowerNumInt = (int) flowerNumDouble;
     if ( flowerNumInt !=0 )
     {
        System.out.println("You can plant " + flowerNumInt + " flowers.");
     }
     else
     {
       System.out.println("Values you entered does not make a triangle.");
     }
       
       
   }

} // end class