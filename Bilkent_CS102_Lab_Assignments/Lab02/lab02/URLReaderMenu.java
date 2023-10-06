import java.util.Scanner;
import cs1.SimpleURLReader;
import java.util.ArrayList;

/**
 * simple url reader menu
 * @author ata.seren
 * @version 17.02.2020
 */ 
public class URLReaderMenu
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      ArrayList<MySimpleURLReader> collection = new ArrayList<MySimpleURLReader>();
      MySimpleURLReader textPoem;
      HTMLFilteredReader htmlPoem;  
      int menu = 0;
      int index = 0;
      String url;
      boolean b;

      // program code
      System.out.println("Welcome to URLReader!");
      System.out.println("Enter:");
      System.out.println("1 to add a url of a poem");
      System.out.println("2 to read a poem");
      System.out.println("3 to quit the menu");
      
      while( menu != 3)
      {
        menu = scan.nextInt();
        if(menu == 1)
        {
          url = scan.next();
          if(url.substring(url.length()-3).equals("txt"))
          {
            textPoem = new MySimpleURLReader(url);
            collection.add(textPoem);
            System.out.println("You have added a poem to the collection.");
          }
          else if (url.substring(url.length()-3).equals("htm"))
          {
            htmlPoem = new HTMLFilteredReader(url);
            collection.add(htmlPoem);
            System.out.println("You have added a poem to the collection.");            
          }
            
        }
        else if (menu == 2)
        {
          if(collection.size() == 0)
          {
            System.out.println("There are no poem in the collection.");
          }
          else
          {
          System.out.println("There is/are " + collection.size()+ " poem/s in the collection.");
          System.out.println("Enter an index to show a poem.");
          index = scan.nextInt();
          b = false;
          
          while (b == false)
          {         
            if(index > collection.size()-1)
            {
              System.out.println("Please enter a proper index.");
              index = scan.nextInt();
            }
            else
            {
              b = true;
            }
          } 
          
          System.out.println(collection.get(index).getPageContents());
          }
        }
      }
          
          
          
          
          
      
      
     
   }

} // end class