import java.util.Scanner;

/**
 * bag menu
 * @author ata.seren
 * @version 17.02.2020
 */ 
public class BagMenu
{
   public static void main( String[] args)
   {
      Scanner scan = new Scanner( System.in);

      // constants

      // variables
      int menu = 0;
      int value = 0;
      int valueTest = 0;
      int index;
      int contains;
      int location;
      String locations ="";
      IntBag bag;
      bag = new IntBag();

      // program code
      System.out.println("Welcome to IntBag menu:");
      System.out.println("1: Create a new empty collection");
      System.out.println("2: Add a set of positive values into the collection");
      System.out.println("3: Print the collection of values");
      System.out.println("4: Add a value to the collection at a spesific location");
      System.out.println("5: Remove a value at a specified location");
      System.out.println("6: Read a single test value");
      System.out.println("7: Compute the set of locations of the test value");
      System.out.println("8: Print the set of locations");
      System.out.println("9: Quit the program");
      System.out.println("0: Print the menu values");
      
      while(menu != 9)
      {
        System.out.println("Enter a menu value");
        menu = scan.nextInt();
        if(menu == 1)
        {
          bag = new IntBag();
          System.out.println("New collection is created.");
        }
        else if(menu == 2)
        {
          System.out.println("Enter a negative int to end the reading.");
          value = 0;
          while(value >= 0)
          {
            value = scan.nextInt();
            if(value >= 0)
            {      
              bag.add(value);
            }
          }
        }
        else if(menu == 3)
        {
          System.out.println(bag.toString());
        }
        else if(menu == 4)
        {
          System.out.println("Write your value:");
          value = scan.nextInt();
          System.out.println("Write the location:");
          location = scan.nextInt();
          bag.addTo(value,location);
        }
        else if(menu == 5)
        {
          System.out.println("Write the index of value you want to remove:");
          index = scan.nextInt();
          bag.remove(index);
        }
        else if(menu == 6)
        {
          System.out.println("Write your test value:");
          valueTest = scan.nextInt();
        }
        else if(menu == 7)
        {
          locations = bag.findAll(valueTest);
          System.out.println("Locations are computed.");
        }
        else if(menu == 8)
        {
          System.out.println(locations);
        }
        else if(menu == 0)
        {
          System.out.println("1: Create a new empty collection");
          System.out.println("2: Add a set of positive values into the collection");
          System.out.println("3: Print the collection of values");
          System.out.println("4: Add a value to the collection at a spesific location");
          System.out.println("5: Remove a value at a specified location");
          System.out.println("6: Read a single test value");
          System.out.println("7: Compute the set of locations of the test value");
          System.out.println("8: Print the set of locations");
          System.out.println("9: Quit the program");
          System.out.println("0: Print the menu values");
        }
      }
          
          
          
      

   }

} // end class