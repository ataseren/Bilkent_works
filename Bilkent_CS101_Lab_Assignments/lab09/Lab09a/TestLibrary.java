import java.util.Scanner;

/**
 * librarian 102
 * @author ata.seren
 * @version 05.12.2019
 */ 
public class TestLibrary
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      Library library;
      String input = "";
      String find;
      String find1;
      LibraryBook a;

      // program code
      library = new Library();
      while( !input.equals("Exit"))
      {
        System.out.println("Choose an operation Show,Find,Add,Remove,Exit");
        input = scan.nextLine();
        
        if( input.equals("Find"))
        {
          System.out.println("enter a title to find book");
          find = scan.nextLine();
          System.out.println("enter it's author to find book");
          find1 = scan.nextLine();
          a = new LibraryBook(find, find1,"",0);          
          library.findByTitle(a);        
        }
        if( input.equals("Show"))
        {
           if(library.isEmpty() == true)
           {
              System.out.println("library is empty");
           }
           else
           {
              library.newToString();
           }
        }
        if( input.equals("Remove"))
        {
          System.out.println("enter a title to find book");
          find = scan.nextLine();
          System.out.println("enter it's author to find book");
          find1 = scan.nextLine();
          LibraryBook c = new LibraryBook(find, find1,"", 0);
          library.removeBook(c);
        }
        if( input.equals("Add"))
        {
           System.out.println("enter a title");
           String title = scan.nextLine();
           System.out.println("enter an author");
           String author = scan.nextLine();
           LibraryBook b = new LibraryBook(title, author, "", 0);
           library.addBook(b);
        }
        
      }
              
           
      

   }

} // end class