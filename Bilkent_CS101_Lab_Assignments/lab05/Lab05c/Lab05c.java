import java.util.Scanner;

/**
 * SimpleCalculator
 * @author ata.seren
 * @version 06.11.2019
 */ 
public class Lab05c
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      double currentSum = 0;
      String input;
      String inputOperator;
      double num;
      boolean quit = false;
      String inputNum;
      

      // program code
      System.out.println("Welcome to \"SimpleCalculator\"...");
      do
      {
         System.out.println("------------------");
         System.out.println("[ " + currentSum + " ]");
         System.out.println("------------------");
         System.out.println("+,-,*,/ value");
         System.out.println("Clear");
         System.out.println("Quit");
         System.out.println("------------------");
         System.out.println("Select: ");
         input = scan.nextLine();
         if(input.equals("clear") || input.equals("Clear") || input.equals("c") || input.equals("C"))
         {
            currentSum = 0;
         }
         else if(input.equals("quit") || input.equals("Quit") || input.equals("q") || input.equals("Q"))
         {
            quit = true;
         }
         else
         {
            inputOperator = input;
            inputOperator = inputOperator.replaceAll("[0-9]","");
            inputOperator = inputOperator.replaceAll(" ","");
            inputNum = input.replaceAll("\\D+","");
            num = Double.parseDouble(inputNum);
            if(inputOperator.equals("+"))
            {
               currentSum = currentSum + num;
            }
            else if(inputOperator.equals("-"))
            {
               currentSum = currentSum - num;
            }
            else if(inputOperator.equals("*")) 
            {
               currentSum = currentSum * num;
            }
            else if(inputOperator.equals("/")) 
            {
               currentSum = currentSum / num;
            }
         }
         
         
      }while(quit == false);
      System.out.println("Thanks for using \"SimpleCalc\", goodbye.");
         
         

   }

} // end class