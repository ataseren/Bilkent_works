import java.util.Scanner;

/**
 * i'm a librarian
 * @author ata.seren
 * @version 28.11.2019
 */ 
public class TestLibraryBook
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      LibraryBook info1;
      LibraryBook info2;
      LibraryBook book1, book2, book3, book11;
      

      // program code
      book1 = new LibraryBook("", "", "", 0);
      book11 = book1;
      book2 = new LibraryBook("", "", "", 0);
      book3 = new LibraryBook("x", "x", "x", 0);
      info1 = new LibraryBook("", "", "", 0);
      info2 = new LibraryBook("", "", "", 0);
      System.out.println(info1.loanBook("30.11.2019", 3));
      info1.returnBook();
      System.out.println(info1.getTimesLoaned());
      System.out.println(info1.onLoan());
      System.out.println(info1.toString());
      if (info1 == info2)
      {
        System.out.println("they are same");
      }
      else
      {
        System.out.println("they are different");
      }
      
      if (info1.equals(info2))
      {
        System.out.println("they are same");
      }
      else
      {
        System.out.println("they are different");
      }
      System.out.println();
      
      
      if(book1 == book2)
      {
         System.out.println("They are equal.");
      }
      else
      {
         System.out.println("They are not equal.");
      }
      
      if(book1.equals(book2))
      {
         System.out.println("They are equal.");
      }
      else
      {
         System.out.println("They are not equal.");
      }
      
      if(book1 == book11)
      {
         System.out.println("They are equal.");
      }
      else
      {
         System.out.println("They are not equal.");
      }
      
      if(book1.equals(book11))
      {
         System.out.println("They are equal.");
      }
      else
      {
         System.out.println("They are not equal.");
      }
      
      if(book2 == book3)
      {
         System.out.println("They are equal.");
      }
      else
      {
         System.out.println("They are not equal.");
      }
      
       if(book2.equals(book3))
      {
         System.out.println("They are equal.");
      }
      else
      {
         System.out.println("They are not equal.");
      }
      
      if(book1.equal(book2) == true);
      {
         System.out.println("They are same");
      }
      

   }

} // end class