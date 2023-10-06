import java.util.ArrayList;
// Librarian plus
public class Library
{
    // properties
  ArrayList<LibraryBook> book;

    // constructors
  public Library()
  {
    book = new ArrayList<LibraryBook>();
  }
  

    // methods
  
  /**
 * to check lab if it's empty or not
 */
  public boolean isEmpty()
  {
    if (book == null)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
   
  /**
 * to show books
 */
  public void newToString()
  {
    if (book.isEmpty() == true)
    {
      System.out.println("there are no books in the library");
    }
    else
    {
      System.out.println(book);
    }
  }
  
  /**
 * to add books
 * @param title is title of the book
 * @param author is author of the book
 */ 
  public void addBook(LibraryBook a)
  {
      book.add(a);
  }
   
   /**
 * to remove books
 * @param title is title of the book
 * @param author is author of the book
 */ 
  public void removeBook(LibraryBook a)
   {
    if(book.contains(a.toString()) == true)
    {
      int index = book.indexOf(a);
      book.remove(index);
    }
   }
   
    /**
 * to find books
 * @param title is title of the book
 * @return book
 */  
  public void findByTitle(LibraryBook a)
   {
     if(book.contains(a) == true)
     {
       System.out.println(a + "");
     }

   }
  
}