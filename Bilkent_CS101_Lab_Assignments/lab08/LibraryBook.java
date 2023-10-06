// library 101
public class LibraryBook
{
    // properties
   String title;
   String author;
   String dueDate; 
   int timesLoaned;

    // constructors
   public LibraryBook( String theTitle, String theAuthor, String theDue, int theLoanTime ) 
   {
      title = theTitle;
      author = theAuthor;
      dueDate = theDue;
      timesLoaned = theLoanTime;      
   }
   
    // methods
   public String toString() 
   {
      return title + " " + author + " " + dueDate + " " + timesLoaned;
   }
   
   public String loanBook(String newDue, int loanTime)
   {
      dueDate = newDue;
      timesLoaned = loanTime;
      boolean loaned = true;
      return dueDate + ", " + timesLoaned + " " + "days left to due.";
   }
   
    public void returnBook()
    {
       dueDate = "";
    }
    
    public int getTimesLoaned()
    {
       return timesLoaned;
    }
    
    public String getTitle()
    {
       return this.title;
    }
    
    public String getAuthor()
    {
       return this.author;
    }
    
    public boolean onLoan()
    {
       if (dueDate.equals(""))
       {
          return true;
       }
       else
       {
          return false;
       }
    }
    
    public boolean equal(LibraryBook book)
    {
       if( this.title.equals(book.getTitle()) && this.author.equals(book.getAuthor()))
       {
          return true;
       }
       else
       {
          return false;
       }
    }


}