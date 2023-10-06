// Librarian plus
public class Library
{
    // properties
  LibraryBook b1;
  LibraryBook b2;
  LibraryBook b3;
  LibraryBook b4;

    // constructors
  public Library()
  {
    b1 = null;
    b2 = null;
    b3 = null;
    b4 = null;
  }
  

    // methods
  
  /**
 * to check lab if it's empty or not
 */
  public boolean isEmpty()
  {
    if (b1 == null && b2 == null && b3 == null && b4 == null)
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
     if (b1 == null && b2 == null && b3 == null && b4 == null)
    {
      System.out.println("there are no books in the library");
    }
    else
    {
      if(b1 != null)
      {
         System.out.println(b1.toString());
      }
      if(b2 != null)
      {
         System.out.println(b2.toString());
      }
      if(b3 != null)
      {
         System.out.println(b3.toString());
      }
      if(b4 != null)
      {
         System.out.println(b4.toString());
      }
    }
   }
   
  /**
 * to add books
 * @param title is title of the book
 * @param author is author of the book
 */ 
  public void add(String title, String author)
   {
     if(b1 == null)
     {
      b1 = new LibraryBook(title, author,"",0);
     }
     else if(b2 == null)
     {
      b2 = new LibraryBook(title, author,"",0);
     }
     else if(b3 == null)
     {
      b3 = new LibraryBook(title, author,"",0);
     }
     else if(b4 == null)
     {
      b4 = new LibraryBook(title, author,"",0);
     }
     else
     {
        System.out.println("library is full");
     }
   }
   
   /**
 * to remove books
 * @param title is title of the book
 * @param author is author of the book
 */ 
  public void remove(String title, String author)
   {
     if(b1 != null)
     {
        if(title.equals(b1.getTitle()) && author.equals(b1.getAuthor()))
        {
           b1 = null;
        }
     }
      else if(b2 != null)
      {
         if(title.equals(b2.getTitle()) && author.equals(b2.getAuthor()))
         {
            b2 = null;
         }
      }
      else if(b3 != null)
      {     
         if(title.equals(b3.getTitle()) && author.equals(b3.getAuthor()))
         {
            b3 = null;
         } 
      }
      else if(b4 != null)
      {
         if(title.equals(b4.getTitle()) && author.equals(b4.getAuthor()))
         {
            b4 = null;
         }
      }
     else
     {
       System.out.println("the book you entered has not found");
     }
   }
   
    /**
 * to find books
 * @param title is title of the book
 * @return book
 */  
  public String findByTitle(String title)
   {
     if(b1 != null && title.equals(b1.getTitle()))
     {               
       return b1 + "";       
     }
     else if (b2 != null && title.equals(b2.getTitle()))
     {       
       return b2 + "";
     }
     else if (b3 != null && title.equals(b3.getTitle()) )
     {        
       return b3 + "";
     }
     else if (b4 != null && title.equals(b4.getTitle()))
     {
       return b4 + "";
     }
       return "there is no book like this";
   }
   
   /**
 * to loan books
 * @param title is title of the book
 * @param author is author of the book
 * @param due is due date
 * @param time is how many times this book loaned
 * @return book
 */   
  public void loanBook(String title, String author, String due, int time)
   { 
     if( b1 != null && title.equals(b1.getTitle()))
     {
       b1 = new LibraryBook(title, author, due, time);
     }
     else if( b2 != null && title.equals(b2.getTitle()))
     {         
       b2 = new LibraryBook(title, author, due, time);
     }
     else if( b3 != null && title.equals(b3.getTitle()))
     {
         b3 = new LibraryBook(title, author, due, time);
     }
     else if( b4 != null && title.equals(b4.getTitle()))
     {
         b4 = new LibraryBook(title, author, due, time);
     }
     else
     {
       System.out.println("there is no book like this");
     }       
   }
   
  /**
 * to return books
 * @param title is title of the book
 * @param author is author of the book
 * @param due is due date
 * @param time is how many times this book returned
 * @return book
 */  
  public void returnBook(String title, String author, String due, int time)
    {
      if(title.equals(b1.getTitle()))
      {
         b1 = new LibraryBook(title, author, "", time);
      }
      else if(title.equals(b2.getTitle()))
      {
         b2 = new LibraryBook(title, author, "", time);
      }
      else if(title.equals(b3.getTitle()))
      {
         b3 = new LibraryBook(title, author, "", time);
      }
      else if(title.equals(b4.getTitle()))
      {
         b4 = new LibraryBook(title, author, "", time);
      }
      else
      {
         System.out.println("there is no book like this");
      }  
    }
       
           
  
}