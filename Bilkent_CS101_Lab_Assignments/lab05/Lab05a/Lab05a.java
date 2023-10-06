import java.util.Scanner;

/**
 * rectangle
 * @ata.seren
 * @version 04.11.2019
 */ 
public class Lab05a
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      int height;
      int thickness;
      int width;
      boolean oneMore = false;
      String again;

      // program code
      do
      {
         System.out.println("Please enter height: ");
         height = scan.nextInt();
         System.out.println("Please enter width: ");
         width = scan.nextInt();
         System.out.println("Please enter thickness: ");
         thickness = scan.nextInt();
           
         if( height <= 0 || width <= 0 || thickness <= 0)
         {
            System.out.println("Please enter positive values.");
         }
         else
         {
            for(int h = 0; h < height; h++)
            {
               for(int w = 0; w < width; w++)
               {
                  if (h - thickness < 0 || thickness + h > height - 1 || w - thickness < 0 || w + thickness > width - 1 )
                  {
                     System.out.print("*" + " "); 
                  }
                  else
                  {
                     System.out.print("  ");
                  }
               }
               System.out.println();
            }
         }
            
         if(height < thickness * 2 || width < thickness * 2)
         {
            System.out.println("Oops no hole...");
         }
         System.out.println("Again?");
         scan.nextLine();
         again = scan.nextLine();
         if( again.equals("Y") || again.equals("y"))
         {
            oneMore = true;
         }
         else
         {
            oneMore = false;
            System.out.println("Goodbye.");
         }
      }while(oneMore == true); 
      
         

   }

} // end class