import java.util.Scanner;


/**
 * gambling 101
 * @author ata.seren
 * @version 28.11.2019
 */ 
public class DieTest
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      Die value1;
      Die value2;
      Dice dice1;
      Dice dice2;

      // program code
      value1 = new Die(0);
      value2 = new Die(0);
      dice1 = new Dice(0, 0);
      System.out.println(value1.roll());
      System.out.println(value1.getFaceValue());
      System.out.println(value1);
      System.out.println(value2.roll());
      System.out.println(value2.getFaceValue());
      System.out.println(value2);
      System.out.println();
      
      System.out.println(dice1.roll());
      System.out.println(dice1.getDie1FaceValue());
      System.out.println(dice1.getDie2FaceValue());
      System.out.println(dice1.getDiceTotal());
      System.out.println(dice1.toString());
      
      


   }

} // end class