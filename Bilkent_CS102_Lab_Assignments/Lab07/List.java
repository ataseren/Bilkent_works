import junit.framework.TestCase;

/**
 * list class and methods
 * @author Ata Seren
 * @version 10.05.2020
 */ 
public class List 
{
   
   // properties
   private Node head;
   
   //constructors
   public List() 
   {
      this.head = null;
   }
   
   /** 
    * adds a node to the head
    * @param item string
    **/
   public void addToHead(String item)
   {
      Node nodeAdd = new Node(item, null);
      if (head == null) 
      {
         head = nodeAdd;
      }
      else 
      {
         nodeAdd.next = head;
         head = nodeAdd;
      }
   }
   
   /** 
    * adds a node to the tail 
    * @param item string 
    **/
   public void addToTail(String item) 
   {
      if (head == null) 
      {
         Node temp = new Node(item, null);
         head = temp;
      }
      else 
      {
         Node currNode = tail();
         Node tail = new Node(item, null);
         currNode.next = tail;
      }
      
   }
   
   /**
    * removes a node from the head 
    * @return data stored data in the node
    **/
   public String removeFromHead() 
   {
      Node temp = head;
      if (temp == null) 
      {
         return null;
      }
      head = head.next;
      return temp.data;
   }
   
   /** 
    * checks empty 
    * @return boolean of empty
    **/
   public boolean isEmpty() 
   {
      if (head == null) 
      {
         return true;
      }
      return false;
   }
   
   /** 
    * returns the data from node
    * @param index index from node
    * @return data 
    **/
   public String getData (int index)
   {
      Node currentNode = head;
      int counter = 0;
      
      while (currentNode != null) 
      {
         if(counter == index)
         {
            return currentNode.data;
         }
         else 
         {
            currentNode = currentNode.next;
         }
         counter = counter + 1;
      }
      return null;
   }
   
   /** 
    * prints all nodes
    **/
   public void print() 
   {
      Node currNode = head;
      System.out.print("List: ");
      
      while (currNode != null) 
      { 
         System.out.print(currNode.data + " ");
         currNode = currNode.next; 
      } 
   }
   
   
   /** 
    * prints stuff in reverse order recursively
    **/
   public void printReverse() 
   {
      Node temp = head;
      if (head != null) 
      {
         printReverseStuff(temp);
      } 
      else 
      {
         System.out.println("List is Empty");
      }
   }
   
   /** 
    * This method is a helper method for printReverse() method.
    * @param n node from printReverse()
    **/
   private void printReverseStuff(Node n){
      if ( n == null) 
      {
         return;
      }      
      printReverseStuff(n.next);
      System.out.print(n.data + " ");
   }
   
   /** 
    * checks a node if list has it or not
    * @param target desired string
    * @return boolean of contain
    **/
   public boolean contains(String target) 
   {
      Node current = head; 
      boolean contains = false; 
      while (current != null && !contains) 
      { 
         if ((current.data).equals(target))
         {
            contains = true;
         }
         current = current.next; 
      }
      return contains;
   }
   
   /** 
    * checks lexo or not (i hate this)
    * @return boolean of lexo
    **/
   public boolean isOrdered() 
   {
      Node current = head;   
      if (head == null) 
      {
         return true;
      }  
      if (head.next == null)
      {
         return true;
      }  
      boolean ordered = true; 
      while (current != null && current.next != null&& ordered) 
      { 
         if ((current.data).compareTo((current.next).data) > 0)
         {
            ordered = false;
         }
         current = current.next; 
      }
      return ordered;
   }
   
   /** 
    * iterating helper method for inner Node class
    * @return next data
    **/
   private Node next(Node n) 
   {
      if (n.next != null) 
      {
         return n.next;
      }
      else 
      {
         return null;
      }
   }
   
   /** 
    * iterating helper method for inner Node class
    * @return previous data
    **/
   private Node previous(Node n) 
   {
      Node currNode = head;
      if (isEmpty()) 
      {
         return null;
      }   
      while (currNode.next != null) 
      {
         if (((currNode.next).data).equals(n.data)) 
         {
            return currNode;
         }
         currNode = currNode.next;
      }      
      return null;
   }
   
   /** 
    * iterating helper method for inner Node class
    * @return tail node
    **/
   private Node tail() 
   {
      Node current = head;
      while (current.next != null) 
      {
         current = current.next;
      }      
      return current;
   }
   
   /** 
    * classic toString() method
    * @param none. 
    * @return all of the list
    **/
   public String toString() 
   {
      String list = "";
      Node currNode = head;
      while (currNode != null) 
      {
         list = list + currNode.data + " ";
         currNode = currNode.next;
      }
      return list;
   }
   
   // inner class
   private class Node 
   {
      String data; 
      Node next; 
      public Node( String data, Node next) 
      {
         this.data = data; 
         this.next = next; 
      } 
   }
      
}