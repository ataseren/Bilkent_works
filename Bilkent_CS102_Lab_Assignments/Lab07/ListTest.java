/**
 * main class of list class methods 
 * @author Ata Seren
 * @version 10.05.2020
 */ 
public class ListTest
{
   public static void main(String[] args) 
   { 
      
      //constants
      final int INDEX = 2;
      final String CHECK = "third";
      
      //variables
      List list = new List();
           
      //program code
      
      System.out.println("add elements to head");
      list.addToHead("fifth");
      list.addToHead("fourth");
      list.addToHead("third");
      list.addToHead("second");
      list.addToHead("first");
      System.out.println(list);   
      System.out.println();
      
      System.out.println("add elements to tail");
      list.addToTail("last3");
      list.addToTail("last2");
      list.addToTail("last1");
      System.out.println(list);
      System.out.println();
      
      System.out.println("remove element from head");
      list.removeFromHead();
      System.out.println(list);
      System.out.println();
      
      
      System.out.println("get element from index");
      System.out.println("index=" + INDEX + "\n" + list.getData(INDEX));  
      System.out.println();
      
      System.out.println("print list");
      list.print();
      System.out.println();
      
      System.out.println("print list in reverse order");
      list.printReverse();
      System.out.println();
      
      System.out.println("checks an element from list");
      if (list.contains(CHECK)) 
      {
         System.out.println("in the list");
      } 
      else 
      {
         System.out.println("not in the list");
      }
      System.out.println();
      
      System.out.println("checks list if it is lexo or not");
      List lexo = new List();
      lexo.addToHead("e");
      lexo.addToHead("d");
      lexo.addToHead("c");
      lexo.addToHead("b");
      lexo.addToHead("a");
      System.out.println(list.isOrdered());
      System.out.println(lexo.isOrdered());
      System.out.println();
      
      System.out.println("create a list from array");
      String array[] = new String[4];
      array[0] = "newFirst";
      array[1] = "newSecond";
      array[2] = "newThird";
      array[3] = "newFourth";
      System.out.println(createFrom(array));
      System.out.println();
      
      System.out.println("create a list from a string");
      String str = "neat stuff";
      System.out.println(createFrom(str));
      System.out.println();
      

      System.out.println("merging stuff");
      List merge1 = new List();
      merge1.addToTail("A");
      merge1.addToTail("D");
      merge1.addToTail("C");
      
      List merge2 = new List();
      merge2.addToTail("K");
      merge2.addToTail("B");
      merge2.addToTail("A");
      merge2.addToTail("C");
      merge2.addToTail("R");
      System.out.println(merge1);
      System.out.println();
      System.out.println(merge2);
      System.out.println();
      System.out.println(merger(merge1, merge2));
      System.out.println();
          
   }
   
   
   /** 
    * to create a list form a string
    * @param strings array of strings
    * @return list of array of strings
    **/
   public static List createFrom(String[] strings) 
   {
      List list = new List();
      for (int i = 0; i < strings.length; i++) 
      {
         list.addToHead(strings[i]);
      }
      return list;
   }
   
   /** 
    * String version of createFrom instead of String[]
    * @param str string to be added
    * @return list of string
    **/
   public static List createFrom(String str) 
   {
      List list = new List();
      for (int i = 0; i < str.length(); i++) 
      {
         list.addToHead(str.substring(i,i+1));
      }
      return list;
   }
   
   
   /** 
    * merges 2 lists
    * @param a first list
    * @param b second list
    * @return the merged list
    **/
   public static List merger (List a, List b) 
   {
      List list = new List();

      for (int i = 0 ; a.getData(i) != null ; i++)
      {
         if (!b.contains(a.getData(i))) 
         {
            list.addToTail(a.getData(i));
         }
      }
      
      for (int j = 0 ; b.getData(j) != null ; j++) 
      {
         if (!a.contains(b.getData(j))) 
         {
            list.addToTail(b.getData(j));
         }
      }
      return list;
      
   }
}