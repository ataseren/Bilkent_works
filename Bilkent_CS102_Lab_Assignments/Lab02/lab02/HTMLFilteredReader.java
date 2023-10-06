import java.util.Scanner;
import cs1.SimpleURLReader;

/** html filtering
  * @author ata.seren
  * @version 03.03.2020
  */
public class HTMLFilteredReader extends MySimpleURLReader
{
    // properties
  String newUrl;



    // constructors
  public HTMLFilteredReader(String url)
  {
    super(url);
    newUrl = url;
  }

    // methods
  /**
   * to get the text with html
   * @return the text with html
   */
  public String getUnfilteredPageContents() 
  {
    content = new MySimpleURLReader(newUrl);
    return content.getPageContents();
  }
  
  /**
   * to get the text without html
   * @return the text without html
   */
  public String getPageContents()
  {
    boolean code = false;
    content = new MySimpleURLReader(newUrl);
    String result = "";
    String text = content.getPageContents(); 
    for(int i = 0; i < text.length(); i++)
    {
      if( text.charAt(i) == '<')
      {
        code = true;
      }
      else if ( text.charAt(i) == '>')
      { 
        code = false;
      }
      else if ( code == false)
      {
        result = result + text.charAt(i);
      }        
    }
    return result;
  }
                                         
 
  
          

}