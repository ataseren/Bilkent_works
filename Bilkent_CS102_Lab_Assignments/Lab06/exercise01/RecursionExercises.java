import java.util.*;
/**
 * recursion exercises in bits and pieces
 * @author ata.seren
 * @version 26.04.2020
 */ 
public class RecursionExercises
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);
      
      // constants
      final int ARRAY_SIZE = 5;
      final int INDEX = 0;
      final String[] ARRAY = {"a","b","c","d","e","f","a","b","c","d","a","a"};
      
      // variables
      int[] num;
      
      // program code
      num = new int[ARRAY_SIZE];
      num[0] = 1;
      num[1] = 2;
      num[2] = 3;
      num[3] = 4;
      num[4] = 5;
      printReverse(3,num);
      System.out.println();
      printForward(num,INDEX);
      System.out.println();
      System.out.print(power(2,5));
      System.out.println();
      System.out.print(max(num,3));
      System.out.println();
      values(3,11);  
      System.out.println();
      ArrayList values = new ArrayList();
      ArrayList x = valuesExtra(3,11,values);
      for(int i = 0; i < x.size();i++)
      {
         System.out.print(x.get(i));
      }
      System.out.println();
      System.out.print(findFirst(ARRAY,"d",INDEX));
      System.out.println();
      System.out.print(findLast(ARRAY,"b",ARRAY.length));
      System.out.println();
      System.out.print(findOccurence(ARRAY,"a",INDEX));
      
   }
   
   /**
    * prints first n values of array in reverse order
    * @param n value number to be reversed
    * @param num array
    */
   public static void printReverse(int n, int[] num)
   {   
      if(n > 0)
      {
         System.out.print(num[n-1]);
         printReverse(n-1,num);   
      }        
   }
   
   /**
    * prints elements of array
    * @param num array itself
    * @param index index of array to start to print (constant 0)
    */
   public static void printForward(int[] num, int index)
   {
      if(index < num.length)
      {
         System.out.print(num[index]);
         printForward(num, index + 1);
      }
   }
   
   /**
    * takes power of a num
    * @param x number itself
    * @param y x's power
    * @return x power to y
    */
   public static double power(double x, int y)
   {
      double result = 1;
      if(y > 0)
      {
         result = result*2*power(x,y-1);
      }
      return result;
   }
   
   /**
    * finds max value of an array in first n elements
    * @param array array itself
    * @param n first elements to find max value
    * @return max value of array in first n elements
    */
   public static int max(int[] array, int n)
   {
      if(n == 1)
      {
         return array[0]; 
      }          
      return Math.max(array[n-1], max(array, n-1)); 
   }
   
   /**
    * prints ints from a starting int to an ending int
    * @param start first int
    * @param end last int
    */
   public static void values(int start, int end)
   {
      if(start <= end)
      {
         System.out.print(start);
         values(start+1, end);
      }
   }
   
   /**
    * same with values() method but it returns ints in an arraylist
    * @param start first int
    * @param end last int
    * @return arraylist of ints
    */
   public static ArrayList valuesExtra(int start, int end, ArrayList x)
   {
      if(start <= end)
      {
         x.add(start);
         valuesExtra(start+1, end,x);
      }
      return x;
   }
   
   /**
    * finds index of first occurence of a desired element
    * @param array array to search
    * @param target desired element
    * @param index start index (constant 0)
    * @return index of first occurence of a desired element
    */
   public static int findFirst(String[] array, String target, int index)
   {
      int result = 0;
      if(index < array.length)
      {
         if(array[index].equals(target))
         {
            return index;
         }
         else
         {
            result = findFirst(array,target,index+1);
         }
      }
      return result;
   }
   
   /**
    * finds index of last occurence of a desired element
    * @param array array to search
    * @param target desired element
    * @param index start index (length of array - 1)
    * @return index of last occurence of a desired element
    */
   public static int findLast(String[] array, String target, int index)
   {
      int result = 0;
      if( 0 < index-1 )
      {
         if(array[index-1].equals(target))
         {
            return index-1;
         }
         else
         {
            result = findLast(array,target,index-1);
         }
      }
      return result;
   }
   
    /**
    * finds amount of occurences of a desired element
    * @param array array to search
    * @param target desired element
    * @param index start index (constant 0)
    * @return amount of occurences of a desired element
    */
   public static int findOccurence(String[] array, String target, int index)
   {
      int result = 0;
      if( index < array.length )
      {
         if(array[index].equals(target))
         {
            result = result + 1 + findOccurence(array,target,index+1);;
            
         }
         else
         {
            result = result + findOccurence(array,target,index+1);
         }
      }
      return result;
   }
    
}