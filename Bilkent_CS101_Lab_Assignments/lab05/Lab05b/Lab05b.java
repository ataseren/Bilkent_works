import java.util.Scanner;

/**
 * rows and columns
 * @author ata.seren
 * @version 06.11.2019
 */ 
public class Lab05b
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      double row;
      double column;
      int rowPrinted = 1;
      int columnPrinted = 1;
      int cellNumber = 0;
      int rowNumber = 1;
      String rowString = ",-";
      

      // program code
      System.out.println("Please enter the amount of row and columns, respectively.");
      row = scan.nextInt();
      column = scan.nextInt();
      System.out.println("Row and column numbers:");
      
      // row,col numbers
      for(int r = 0; r < row; r++)
      {
         for(int c = 0; c < column; c++)
         {
            if((row * 10) / 10 < 10 && (column * 10) / 10 < 10)
            {
               System.out.print("   " + rowPrinted + "," + columnPrinted);
               columnPrinted++;
            }
            else if((row * 10) / 10 < 10 && (column * 10) / 10 >= 10 && (column * 10) / 10 < 100)
            {
               if(columnPrinted < 10)
               {
                  System.out.print("   " + rowPrinted + "," + columnPrinted);
                  columnPrinted++;
               }
               else
               {
                  System.out.print("  " + rowPrinted + "," + columnPrinted);
                  columnPrinted++;
               }
            }
            else if((row * 10) / 10 >= 10 && (column * 10) / 10 < 10)
            {
               if(rowPrinted < 10)
               {
                  System.out.print("   " + rowPrinted + "," + columnPrinted);
                  columnPrinted++;
               }
               else
               {
                  System.out.print("  " + rowPrinted + "," + columnPrinted);
                  columnPrinted++;
               }
            }
            else if((row * 10) / 10 < 10 && (column * 10) / 10 >= 100)
            {
               if(columnPrinted < 10)
               {
                  System.out.print("   " + rowPrinted + "," + columnPrinted);
                  columnPrinted++;
               }
               else if (columnPrinted >= 10 && columnPrinted < 100)
               {
                  System.out.print("  " + rowPrinted + "," + columnPrinted);
                  columnPrinted++;
               }
               else
               {
                  System.out.print(" " + rowPrinted + "," + columnPrinted);
                  columnPrinted++;
               }
               
            }
               
               
         }
         columnPrinted = 1;
         rowPrinted++;
         System.out.println();
      }
      
      //product of row,col
      System.out.println();
      System.out.println("Product of row and column numbers:");
      rowPrinted = 1;
      columnPrinted = 1;
      for(int r = 0; r < row; r++)
      {
         for(int c = 0; c < column; c++)
         {
             if(rowPrinted * columnPrinted < 10)
             {
                System.out.print("   " + rowPrinted * columnPrinted);
             }
             else if(rowPrinted * columnPrinted >= 10 && rowPrinted * columnPrinted < 100)
             {
                 System.out.print("  " + rowPrinted * columnPrinted);
             }
             else
             {
                 System.out.print("  " + rowPrinted * columnPrinted);
             }
             columnPrinted++;
            
            
         }
         rowPrinted++;
         columnPrinted = 1;
         System.out.println();
      }
      
      // cell numbers
      System.out.println();
      System.out.println("Cell numbers:");
      for(int r = 0; r < row; r++)
      {
         for(int c = 0; c < column; c++)
         {
            if(cellNumber < 10)
            {
               System.out.print("   " + cellNumber);
               cellNumber++;
            }
            else if ( cellNumber >= 10 && cellNumber < 100)
            {
               System.out.print("  " + cellNumber);
               cellNumber++;
            }
            else
            {
               System.out.print(" " + cellNumber);
               cellNumber++;
            }
               
               
         }
         System.out.println();
      }
      
      // row numbers
      
      System.out.println();
      System.out.println("Row numbers:");
      for(int r = 0; r < row; r++)
      {
         System.out.print(rowNumber);
         for(int w = 0; w < column - 1; w++)
         {
            System.out.print(rowString);
         }
         System.out.println();
         rowNumber++;
        
      }
        
      
      
      
      
      
                  
            
      
         
        
      
      
      
      
      
         

   }

} // end class