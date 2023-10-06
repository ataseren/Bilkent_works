import java.util.Scanner;

/**
 * bags of integers prime version
 * @author ata.seren
 * @version 17.02.2020
 */ 
public class IntBagPrime
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      IntBag primeBag;
      int candidate = 3;
      

      // program code
      primeBag = new IntBag();
      primeBag.add(2);
      while(primeBag.size()<100)
      {
        boolean add = true;
        for(int i=0;i<primeBag.size();i++)
        {
          if(candidate%primeBag.get(i) == 0)
          {
            add = false;
          }
        }
        if(add)
        {
          primeBag.add(candidate);
        }
        candidate++;
      }
      System.out.println(primeBag.toString());
          
        
      
      


   }

} // end class
