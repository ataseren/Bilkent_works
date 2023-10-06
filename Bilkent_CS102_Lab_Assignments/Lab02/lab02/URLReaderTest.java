import java.util.Scanner;
import cs1.SimpleURLReader;

/**
 * simple url reader
 * @author ata.seren
 * @version 17.02.2020
 */ 
public class URLReaderTest
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      SimpleURLReader reader;
      MySimpleURLReader newReader;
      HTMLFilteredReader html;
      XHTMLFilteredReader xhtml;
      XHTMLFilteredReader xhtml2;
      XHTMLFilteredReader xhtml3;
      Exchange rate;
         

      // program code
      newReader = new MySimpleURLReader("https://tcmb.gov.tr/kurlar/today.xml");
      reader = new SimpleURLReader("http://www.cs.bilkent.edu.tr/~david/housman.txt");
      html = new HTMLFilteredReader("http://www.cs.bilkent.edu.tr/~david/housman.htm");
      xhtml = new XHTMLFilteredReader("http://www.cs.bilkent.edu.tr/~david/housman.htm");
      xhtml2 = new XHTMLFilteredReader("http://www.cs.bilkent.edu.tr/~david/index.html");
      xhtml3 = new XHTMLFilteredReader("http://www.cs.bilkent.edu.tr/~david/housman.htm");
      rate = new Exchange("https://tcmb.gov.tr/kurlar/today.xml");
      
      System.out.println(reader.getPageContents());
      System.out.println(reader.getLineCount());
      System.out.println("---------------------------------------");
      System.out.println(newReader.getURL());
      System.out.println(newReader.getName());
      System.out.println("---------------------------------------");
      System.out.println(newReader.getPageContents());
      System.out.println("---------------------------------------");
      System.out.println(html.getUnfilteredPageContents());    
      System.out.println("---------------------------------------");
      System.out.println(html.getPageContents());
      System.out.println("---------------------------------------");
      System.out.println(xhtml.getPercentage());
      System.out.println(xhtml2.getLinks());
      System.out.println("---------------------------------------");
      System.out.println("---------------------------------------");
      System.out.println("---------------------------------------");
      System.out.println("---------------------------------------");
      System.out.println(xhtml3.jSoupHTML());
      System.out.println("---------------------------------------");
      System.out.println(xhtml2.links());
      System.out.println("---------------------------------------");
      System.out.println("---------------------------------------");
      System.out.println("---------------------------------------");
      System.out.println("---------------------------------------");      
      System.out.println(rate.getUSD());
      System.out.println(rate.getEuro());
      
      
      
      
      
     
   }

} // end class