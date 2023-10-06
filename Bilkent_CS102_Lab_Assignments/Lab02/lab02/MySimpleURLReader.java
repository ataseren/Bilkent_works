import java.util.Scanner;
import cs1.SimpleURLReader;

/** simple url reader
  * @author ata.seren
  * @version 03.03.2020
  */
public class MySimpleURLReader extends SimpleURLReader
{
    // properties
  String newUrl;
  SimpleURLReader content; 


    // constructors
  public MySimpleURLReader(String url)
  {
    super(url);
    newUrl = url;
  }

  // methods
  /** 
   * to get url
   * @return the url
   */
  public String getURL()
  {
    return newUrl;
  }
    
  /** 
   * to get the names of files
   * @return the filename
   */
  public String getName()
  {
    int index;
    for(int i = newUrl.length(); i > 0; i--)
    {
      if(newUrl.charAt(i-1) == '/')
      {
        return newUrl.substring(i);
      }
    }
    return "filename not found";
  }
  
  /** 
   * to get contents of url
   * @return the contents
   */
  public String getPageContents()
  {
    content = new SimpleURLReader(newUrl);
    return (content.getPageContents()).substring(4);
  }
        
          

}