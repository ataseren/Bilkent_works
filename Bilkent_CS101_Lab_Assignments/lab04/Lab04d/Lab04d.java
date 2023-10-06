import java.util.Scanner;

/**
 * __program description___ 
 * @author __your name___
 * @version __date__
 */ 
public class Lab04d 
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      String ch;
      String chEnd;
      int widthEntered;
      int widthPrinted = 0;

      // program code
      System.out.println("Please enter a character: ");
      ch = scan.nextLine();
      System.out.println("Please enter a width: ");
      widthEntered = scan.nextInt();
      chEnd = ch;
      while(widthPrinted != widthEntered)
      {
        System.out.println(chEnd);
        chEnd = chEnd + ch;
        widthPrinted++;   
      }
      
      
      

   }

} // end class