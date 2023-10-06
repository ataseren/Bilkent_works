import java.util.Scanner;

/**
 * task 5 and 6
 * @author ata.seren
 * @version 14.11.2019
 */ 
public class Lab06Task5and6
{
   public static double factorialMethod( double n)
   {
      double result = n;
      while(1 < n)
      {
         n--;
         result = result * n;
      }
      return result;
   }
   
   public static double powerMethod( double x, int y)
   {
      double result = x;
      for (int r = 1; r < y; r++)
      {
         result = result * x;
      }
      return result;
   }
   
   public static double sinMethod(double x)
   {
     double result;
     double term;
     double minusPow;
     double factorial;
     result = 0;
     term = 0;
     for( int n = 0; n <= 10; n++)
     {
        factorial = factorialMethod(2*n +1);
        minusPow = Math.pow(-1,n);
        term = (minusPow * Math.pow(x, 2*n +1) / factorial);
        result = result + term ;
     }
     return result;
   }
       
     
   
  
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      int termNum;
      double sinResult = 0;
      int x;

      // program code
      System.out.println("enter a degree for sin");
      x = scan.nextInt();
      termNum = 0;
      while(termNum < 10)
      {         
         sinResult = sinResult + ((Math.pow(-1,termNum) * Math.pow(x,((2 * termNum) +1))) / factorialMethod((2 * termNum) + 1));
         termNum++;
      }
      System.out.println( sinResult);
      termNum = 0;   
      System.out.println(sinMethod(x));
      System.out.println(Math.sin(x));
      
      
      

   }

} // end class