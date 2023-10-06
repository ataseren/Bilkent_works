import java.util.*;
/**
 * recursion examples
 * @author ata.seren
 * @version 25.04.2020
 */ 
public class RecursionStuff
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);
      
      //constants
      final String STRING = "abcdefgehrehdhe"; //contains 4 "e"
      final int DECIMAL = 6;
      final int DIGIT = 5;
      //variables
      ArrayList<String> lexo = new ArrayList<String>();
      ArrayList<String> unlexo = new ArrayList<String>();
      
      //program code
      System.out.println(eCounter(STRING));
      decimalBinaryConverter(DECIMAL);
      System.out.println();
      
      lexo.add("a"); lexo.add("b"); lexo.add("c"); lexo.add("d"); lexo.add("e"); lexo.add("f"); lexo.add("g");
      unlexo.add("e"); unlexo.add("x"); unlexo.add("a"); unlexo.add("f"); unlexo.add("b"); unlexo.add("n"); unlexo.add("c"); 
      
      System.out.println(lexOrder(lexo));
      System.out.println(lexOrder(unlexo));
      nDigit(DIGIT,(int)Math.pow(10,DIGIT-1)); 
      System.out.println(digitChecker(132));
      
   }
   
   /**
    * counts e
    * @param str string to be searched for e
    * @return number of e's
    */
   public static int eCounter(String str) 
   {
      int result = 0;
      if(str.length()==0) 
      {
         return result;
      }
      if ((str.substring(0,1).equals("e"))) 
      {     
         result = 1 + eCounter(str.substring(1));
         return result;
      }
      result = eCounter(str.substring(1));
      return result;
   }
   
   /**
    * decimal to binary
    * @param dec decimal to be converted
    */
   public static void decimalBinaryConverter(int dec) 
   {
      if (dec > 0) 
      {
         decimalBinaryConverter(dec/2);
         System.out.print(dec%2);
      }
   }
   
   /**
    * checks if it is lexo or not
    * @param list arraylist that contains strings
    * @return lexo or unlexo boolean
    */
   public static boolean lexOrder(ArrayList<String> list)
   {
      boolean result = false;
      if(list.size()==1)
      {
         return true;
      }
      else if(list.get(0).compareTo(list.get(1))>0) 
      {
         result = false;
      }
      else 
      {
         list.remove(0);
         result = lexOrder(list); 
      } 
      return result;
   }
   
   /**
    * lab d part (works for only 1,2 and 3
    * @param nStart constant start value according to digit
    */
   public static void nDigit(int n, int nStart)
   {
      double nEnd = Math.pow(10,n)-1;
      if (nStart < nEnd)
      {
         if(digitChecker(nStart) && nStart%2 == 0)
         {
            System.out.print(nStart+ " ");
            nDigit(n,nStart + 1);
         }
         else
         {
            nDigit(n,nStart + 1);
         }

//         if((nStart%10 > (nStart/10)%10)&& (((nStart/10)%10)>nStart/100)&&nStart%2==0)
//         {
//            System.out.print(nStart+" ");
//            nDigit(n,nStart + 1);  
//         }
//         else
//         {
//            nDigit(n,nStart + 1);
//         }
      }
      else
      {
      }
   }
   
   public static boolean digitChecker(int n)
   {
      boolean result = false;
      if((n%10 > (n%100)/10) && n/10 != 0)
      {
         result = digitChecker(n/10);
      }
      else if(n/10 == 0)
      {
         return true;
      }
      return result;
   }   
}

