import java.util.Scanner;

/**
 * mymethods 
 * @author ata.seren
 * @version 12.11.2019
 */ 
public class Lab06
{
   /**
    * takes power of a number
    * @param x is base number
    * @param y is power number
    * @return x power of y
    */
   public static double powerMethod( double x, int y)
   {
      double result = x;
      for (int r = 1; r < y; r++)
      {
         result = result * x;
      }
      return result;
   }
   
   /**
    * takes factorial
    * @param n is the number to take factorial
    * @return factorial of n
    */
   public static double factorialMethod( int n)
   {
      double result = n;
      while(1 < n)
      {
         n--;
         result = result * n;
      }
      return result;
   }
   
   /**
    * reverser
    * @param s is word to be reversed
    */
   public static void reverseMethod(String s)
   {  
      for ( int index = (s.length() - 1);  -1 < index; index--)
      {
         System.out.println( s.charAt( index) );
      }
   }
   
   /**
    * better reverser
    * @param s is word to be reversed
    * @return reversed string
    */
   public static String reverseType2(String s)
   {
      String result = "";
      for ( int index = (s.length() - 1);  -1 < index; index--)
      {
         char ch = s.charAt(index);
         String st = String.valueOf(ch);
         result = result + st;
      }
      return result;
   }
   
  /**
    * base2 to base10
    * @param base2 is binary
    * @return decimal
    */
   public static int toDecimal( String base2)
   {
     int digit = 0;
     int result = 0;
     int index = base2.length() - 1;
     while( 0 < index + 1 )
     {
        char s = base2.charAt(digit);
        String a = String.valueOf(s); 
        int i=Integer.parseInt(a);
        int pow = (int) Math.pow(2, index);
        result = result + i * pow;
        index--;
        digit++;
     }
     return result;  
   }
   
   /**
    * base10 to base2
    * @param base10 is decimal
    * @return binary
    */
   public static String toBinary( int base10)
   {
      int remainder;
      String result = "";
      while(base10 != 0 )
      {
         remainder = base10 % 2;
         base10 = base10 / 2;
         String a = String.valueOf(remainder);
         result = result + a;
         
         
      }
      return result;
   }
   
   /**
    * to reverse binary when it is needed to be
    * @param binary binary
    * @return binary "correctly"
    */
   public static String reverseBinary (String binary)
   {
      String result = "";
      int index = binary.length() - 1;
      while( 0 < index + 1)
      {
         char s = binary.charAt(index);
         String c = String.valueOf(s);
         result = result + c;
         index--;
      }
      return result;
   }
      
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants
      

      // variables
      int pow = 1;
      int powTaken = -1;
      int factorial = 1;
      String binary1;
      String binary2;
      int decimal;
      String sentence;
      int loop;
      int index;
      String resultSentence = "";
      String resultWord = "";
      int termNum = 0;
      int x = 30;
      int minusVal = 1;
      double sinResult = 0;
      
      

      // program code
      System.out.println("Taking power of some numbers");
      for(int a = 0; a < 12; a++)
      {
         
         for (int b = 0; b < 4; b++)
         { 
            System.out.print( powerMethod( powTaken, pow) + "\t");
            pow++;
         }
         System.out.println();
         pow = 1;
         powTaken++;
      }
      System.out.println();
      
      for(int c = 0; c < 15; c++)
      {
         System.out.println(factorialMethod(factorial));
         factorial++;
      }
      System.out.println();
      
      System.out.println("Enter 2 binary value");
      binary1 = scan.nextLine();
      binary2 = scan.nextLine();
      decimal = toDecimal(binary1) + toDecimal(binary2);
      System.out.println(toDecimal(binary1));
      System.out.println(toDecimal(binary2));
      System.out.println(reverseBinary(toBinary(decimal)));
      System.out.println();
              
      System.out.println("Enter a string to reverse its words:");
      sentence = scan.nextLine();
      String[] words = sentence.split(" ");
      String reverseString = "";
      for (int i = 0; i < words.length; i++) 
      {
         String word = words[i];    
         String reverseWord = "";
         reverseWord = reverseWord + reverseType2(word);
         reverseString = reverseString + reverseWord + " ";
      }   
      System.out.println(reverseString);
      System.out.println();
      
      while(termNum < 10)
      { 
         System.out.print( termNum +  "\t");
         System.out.print( powerMethod(-1,termNum) +  "\t");
         System.out.print( powerMethod(x,((2 * termNum) +1)) +  "\t");
         System.out.print( factorialMethod((2 * termNum) + 1) + "\t");
         System.out.println();
         termNum++;
      }
      termNum = 0;
      
      
      
      while(termNum < 10)
      {         
         sinResult = sinResult + ((powerMethod(-1,termNum) * powerMethod(x,((2 * termNum) +1))) / factorialMethod((2 * termNum) + 1));
         termNum++;
      }
      System.out.println( sinResult);
      termNum = 0;
      
         
      
      
      
      
      
                             
                             
            
      
      
      

   }

} // end class