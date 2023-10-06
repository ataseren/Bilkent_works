import java.util.Scanner;

/**
 * computingPi
 * @author ata.seren
 * @version 06.11.2019
 */ 
public class Lab05d
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      double infiniteNum = 0;
      double termNum;
      double infiniteCal = 1;
      double infinitePi = 0;
      double pi;
      double piMinus = 1;
      double infinitePiFirst = 0;

      // program code
      System.out.println("Pi Calculator:");
      System.out.println();
      
      //Math.PI method
      System.out.println("Java Math.PI method:");
      System.out.println(Math.PI);
      System.out.println();
      
      //infinite formula
      System.out.println("Infinite formula:");
      System.out.println("How many terms do you want to be computed?");
      termNum = scan.nextInt();
      while(infiniteNum < termNum)
      {
         pi = (4 / infiniteCal) * piMinus;
         infinitePi = infinitePi + pi;
         infiniteCal = infiniteCal + 2;
         piMinus = piMinus * (-1);
         infiniteNum++;
         
      }
      System.out.print(infinitePi);
      infinitePi = 0;
      infiniteCal = 1;
      piMinus = 1;
      
      //pi with accuracy
      System.out.println();
      System.out.println("Pi with accuracy:");
      do
      {
         infinitePiFirst = infinitePi;
         pi = (4 / infiniteCal) * piMinus;
         infinitePi = infinitePi + pi;
         infiniteCal = infiniteCal + 2;
         piMinus = piMinus * (-1);
         
      }while(Math.abs(infinitePiFirst-infinitePi) > 0.01 );
      System.out.println(infinitePi);
      
         
         
      

   }

} // end class