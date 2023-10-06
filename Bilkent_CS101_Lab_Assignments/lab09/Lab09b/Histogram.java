import java.util.ArrayList;
import java.util.Scanner;

/**
 * __program description___ 
 * @author __your name___
 * @version __date__
 */ 
public class Histogram
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      ArrayList<Integer> data = new ArrayList<Integer>();
      Dice dice = new Dice(0,0);
      int counter2 = 0;
      int counter3 = 0;
      int counter4 = 0;
      int counter5 = 0;
      int counter6 = 0;
      int counter7 = 0;
      int counter8 = 0;
      int counter9 = 0;
      int counter10 = 0;
      int counter11 = 0;
      int counter12 = 0;

      // program code
      for( int i = 0; i < 1000; i++)
      {
        dice.roll();
        data.add(dice.getDiceTotal());
        System.out.println(data);
      }
        
      for( int a = 0; a < 1000; a++)
      {
        if(data.get(a)== 2)
        {
          counter2++;
        }
      }
      for( int b = 0; b < 1000; b++)
      {
        if(data.get(b)== 3)
        {
          counter3++;
        }
      }
      for( int c = 0; c < 1000; c++)
      {
        if(data.get(c)== 4)
        {
          counter4++;
        }
      }
      for( int d = 0; d < 1000; d++)
      {
        if(data.get(d)== 5)
        {
          counter5++;
        }
      }
      for( int e = 0; e < 1000; e++)
      {
        if(data.get(e)== 6)
        {
          counter6++;
        }
      }
      for( int f = 0; f < 1000; f++)
      {
        if(data.get(f)== 7)
        {
          counter7++;
        }
      }
      for( int g = 0; g < 1000; g++)
      {
        if(data.get(g)== 8)
        {
          counter8++;
        }
      }
      for( int h = 0; h < 1000; h++)
      {
        if(data.get(h)== 9)
        {
          counter9++;
        }
      }
      for( int j = 0; j < 1000; j++)
      {
        if(data.get(j)== 10)
        {
          counter10++;
        }
      }
      for( int k = 0; k < 1000; k++)
      {
        if(data.get(k)== 11)
        {
          counter11++;
        }
      }
      for( int l = 0; l < 1000; l++)
      {
        if(data.get(l)== 12)
        {
          counter12++;
        }
      }
      
      for(int column = 0; column < 11; column++)
      {
        
      
      

   }

} // end class