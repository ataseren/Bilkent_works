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

      // program code
      library = new Library();
      while( !input.equals("Exit"))
      {
        System.out.println("Choose an operation Show,Find,Add,Exit");
        input = scan.nextLine();
        if( input.equals("Find"))
        {
          System.out.println("enter a book to find");
          find = scan.nextLine();
          library.findByTitle(find);
          if(!library.findByTitle(find).equals("there is no book like this"))
          {
             System.out.println("Choose an operation Loan,Remove,Return");
             String subInput = scan.nextLine();
             if(subInput.equals("Loan"))
             {
                System.out.println("enter title to loan");
                String title1 = scan.nextLine();
                System.out.println("enter author to loan");
                String author1 = scan.nextLine();
                System.out.println("enter due date to loan");
                String due = scan.nextLine();
                System.out.println("enter which time this book loaned");
                int time = scan.nextInt();
                library.loanBook(title1, author1, due, time);
             }
             else if(subInput.equals("Return"))
             {
                System.out.println("enter title to return");
                String title1 = scan.nextLine();
                System.out.println("enter author to return");
                String author1 = scan.nextLine();
                System.out.println("enter how many times this book returned");
                int time = scan.nextInt();
                library.loanBook(title1, author1, "", time);
             }
             else if(subInput.equals("Remove"))
             {
                System.out.println("enter title to remove");
                String title1 = scan.nextLine();
                System.out.println("enter author to remove");
                String author1 = scan.nextLine();
                library.remove(title1, author1);
             }
             else if(subInput.equals("Return"))
             {
                System.out.println("enter a title to return");
                String title1 = scan.nextLine();
                System.out.println("enter an author to return");
                String author1 = scan.nextLine();
                library.add(title1, author1);
             }
          }
          else
          { 
             System.out.println("there is no book like this");
          }
             
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
        if( input.equals("Add"))
        {
           System.out.println("enter a title");
           String title = scan.nextLine();
           System.out.println("enter an author");
           String author = scan.nextLine();
           library.add(title, author);
        }
        
      }
              
           
      

   }

} // end class