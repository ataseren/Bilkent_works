import java.util.Scanner;

/**
 * bags of integers
 * @author ata.seren
 * @version 17.02.2020
 */ 
public class IntBagTest
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      IntBag bag;

      // program code
      bag = new IntBag();
      bag.add(1);
      bag.add(2);
      bag.add(3);
      bag.add(45);
      bag.add(92);
      System.out.println(bag.toString());
      System.out.println(bag.size());
      bag.addTo(31,2);
      System.out.println(bag.toString());
      System.out.println(bag.size());
      bag.remove(3);
      System.out.println(bag.toString());
      System.out.println(bag.size());
      System.out.println(bag.get(3));
      System.out.println(bag.contains(3));
      System.out.println(bag.contains(45));
      
      


   }

} // end class
