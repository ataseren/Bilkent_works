import java.util.Scanner;
import java.math.RoundingMode;
import java.text.DecimalFormat;

/**
 * first while
 * @author ata.seren
 * @version 27.10.2019
 */ 
public class Lab04a
{
   private static DecimalFormat df2 = new DecimalFormat("#.##");
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      int n;
      int printInt;
      int printAmount;
      double equals;
      int fiveBreaker;

      // program code
      System.out.println("Please enter a value:");
      n = scan.nextInt();
      printInt = 0;
      if(n <= 0)
      {
        System.out.println("You didn't enter a positive value.");
      }
      else
      {
        while(printInt < n - 1)
        {
          printInt++;
          System.out.print(printInt + " ");
        }
        
        System.out.println();
       
       //
        fiveBreaker = 0;
        printInt = 0;
        System.out.println();
        while( printInt < n - 1)
        {
           fiveBreaker++;
           printInt++;
           System.out.print(printInt + " ");
           if(fiveBreaker % 5 == 0 && fiveBreaker != 0)
           {
             System.out.println();
           }
          
        }
        
        System.out.println();

       //
        printInt = n;
        System.out.println();
        while(printInt >= 0)
        {
          System.out.print(printInt + " ");
          printInt--;
        }
        
        System.out.println();
        
        //
        printInt = -n;
        System.out.println();
        while(printInt < n + 1)
        {
          if(printInt % 2 != 0)
          {
            printInt++;
          }
          System.out.print(printInt + " ");
          printInt = printInt + 2;
        }
        
        System.out.println();
          
        printInt = 0;
        System.out.println();
        fiveBreaker = 0;
        while(printInt < n)
        {
          if(printInt % 2 != 0)
          {
            printInt++;
          }
          System.out.print((printInt * printInt) + " ");
         fiveBreaker++;
          printInt = printInt + 2;
          if(fiveBreaker % 5 == 0 && fiveBreaker != 0)
          {
             System.out.println();
          }    
          
        }
        
        System.out.println();
        
        //
        printInt = n;
        printAmount = 0;
        System.out.println();
        while(printInt >= 3 )
        {
          if(printInt % 3 == 0)
          {
            if(printInt % 12 != 0)
            {
              System.out.print(printInt + " ");
              printInt--;
              printAmount++;
              if(printAmount % 5 == 0 && printAmount != 0)
              {
                System.out.println();
              }
            }
            else
            {
              printInt--;
            }
          }
          else if (printInt % 4 == 0)
          {
             if(printInt % 12 != 0)
            {
              System.out.print(printInt + " ");
              printInt--;
              printAmount++;
              if(printAmount % 5 == 0 && printAmount != 0)
              {
                System.out.println();
              }
            }
             else
            {
              printInt--;
            }
          }
          else
          {
            printInt--;
          }
          
 
        }
       
        //
        printInt = 1;  
        System.out.println();
        while(printInt < n+1)
        {
          if(n % printInt == 0)
          {
            System.out.print(printInt + " ");
          }
          printInt++;
        }
        
        System.out.println();
        
        //
        printInt = n;
        System.out.println();
        while(printInt > 0)
        {
          equals = 1.0/printInt;
          System.out.print(df2.format(equals) + " ");
          printInt--;
        }
          
          
          
        
        

      }
          
          
      

   }

} // end class