import java.util.Scanner;
import cs1.SimpleURLReader;
import java.util.ArrayList;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;


/** html filtering plus
 * @author ata.seren
 * @version 03.03.2020
 */


public class XHTMLFilteredReader extends HTMLFilteredReader
{
    // properties
  String newUrl;
  ArrayList <String>link;
  String htmlString;
  HTMLFilteredReader x;



    // constructors
  public XHTMLFilteredReader(String url)
  {
    super(url);
    newUrl = url;
  }

    // methods
  
  /** 
   * to get the percentage betwen html and the code
   * @return percentage
   */
   public String getPercentage()
  {
     content = new MySimpleURLReader(newUrl);
     x = new HTMLFilteredReader(newUrl);
     String all = content.getPageContents();
     String nohtml = x.getPageContents();
     double big = all.length();
     double small = nohtml.length();
     return "%"+ (100*(big-small)/small);
  }
     
  
  /** 
   * to store href data (links)
   * @return links
   */
  public ArrayList<String> getLinks()
  {
    content = new MySimpleURLReader(newUrl);
    String text = content.getPageContents();
    String add;
    link = new ArrayList<String>();
    int index = 0;
    while(text.indexOf("href",index) != -1)
    {
      index = text.indexOf("href",index);
      add = text.substring(index+6,text.indexOf("\"",index+7));
      link.add(add);
      index = index+6;
    }
    return link;
  }
  
  
  /** 
   * something called jsoup
   * @return html
   */
  public String jSoupHTML()
  {
     x = new HTMLFilteredReader(newUrl);
     htmlString = x.getUnfilteredPageContents();
     Document doc = Jsoup.parse(htmlString);
     return doc.toString();
  }
  
  /** 
   * something called jsoup to get links
   * @return links
   */
  public ArrayList<String> links()
  {
     x = new HTMLFilteredReader(newUrl);
     ArrayList<String> links = new ArrayList<String>();
     htmlString = x.getUnfilteredPageContents();
     Document doc = Jsoup.parse(htmlString);
     Elements elements = doc.select("a");
        for (Element element : elements) {
            links.add(element.attr("href"));
        }
     return links;
  }
  
  
                                
     

}
