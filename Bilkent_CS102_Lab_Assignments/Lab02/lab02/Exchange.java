import java.util.Scanner;
import cs1.SimpleURLReader;

/** exchange
  * @author ata.seren
  * @version 03.03.2020
  */
public class Exchange
{
    // properties
   String data;
   SimpleURLReader x;
   String sub;
   String rateBuy;
   String rateSell;
 

    // constructors
   public Exchange(String url)
   {
      x = new SimpleURLReader(url);
      data = x.getPageContents();
   }
  
    // methods
   /** 
   * to get USD rate
   * @return buy and sell rate
   */
   public String getUSD()
   {
      sub = data.substring(data.indexOf("<Isim>ABD DOLARI</Isim>"),data.indexOf("<CrossRateOther/>")+17);
      rateBuy = sub.substring(sub.indexOf("<ForexBuying>")+13,sub.indexOf("<ForexBuying>")+19);
      rateSell = sub.substring(sub.indexOf("<ForexSelling>")+14,sub.indexOf("<ForexSelling>")+20);
      return "Buy rate: "+ rateBuy +" " +"Sell rate: " + rateSell;
   }
   
   /** 
   * to get Euro rate
   * @return buy and sell rate
   */
   public String getEuro()
   {
      sub = data.substring(data.indexOf("<Isim>EURO</Isim>"),data.indexOf("<CrossRateOther>"));
      rateBuy = sub.substring(sub.indexOf("<ForexBuying>")+13,sub.indexOf("<ForexBuying>")+19);
      rateSell = sub.substring(sub.indexOf("<ForexSelling>")+14,sub.indexOf("<ForexSelling>")+20);
      return "Buy rate: "+ rateBuy +" " +"Sell rate: " + rateSell;
   }
      
      
   
   
 

}