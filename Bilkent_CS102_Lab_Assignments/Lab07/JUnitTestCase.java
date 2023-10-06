import junit.framework.TestCase;

/**
 * testing list class with JUnit 
 * @author Ata Seren
 * @version 10.05.2020
 */ 
public class JUnitTestCase extends TestCase 
{
        
   /** 
    * junit test method of isempty() method
    **/
   public void testIsEmpty() 
   {
      List list = new List();
      
      //assertFalse(list.isEmpty());
      list.addToHead("test");  
      assertFalse(list.isEmpty());
      assertTrue(list.isEmpty());
   }

   /** 
    * junit test of contains() method
    **/
   public void testContains() 
   {
      List list = new List();
      
      assertFalse(list.contains("hl"));
      list.addToHead("hl");
      assertTrue(list.contains("hl"));
   }
      
}
