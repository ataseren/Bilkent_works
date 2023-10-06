import java.util.Scanner;
import java.nio.file.*;  
import java.io.*;

/**
 * gardening in a better way
 * @author ata.seren
 * @version 24.10.2019
 */ 
public class Lab03c 
{
  public static void main(String[] args) 
  { 
    Scanner scan = new Scanner( System.in);
   
    // constants
    final double TAX_RATE = 0.15;
    final double POOR_TAX = 0.05;
    final double RICH_TAX = 0.20;

    // variables
    String name;
    double age;
    double salaryGross;
    String comment;
    double salaryNet;
    double taxRate;
    
    // program code
    
   
    System.out.println("Please enter your name: ");
    name = scan.nextLine();
   
    System.out.println("Please enter your comments: ");
    comment = scan.nextLine();
    
    System.out.println("Please enter your age: ");
    do{
   
      age = scan.nextDouble();
       if (age <1)
       {
         System.out.println("Please enter a valid age.");
       }
    }while( age<1);
      
    
    
    System.out.println("Please enter your salary: ");                  
    do{
      
      salaryGross = scan.nextDouble();
       if (salaryGross >10000)
       {
         System.out.println("Please enter a valid salary.");
       }
     }while( salaryGross >10000);
     
     if (salaryGross<1000)
     {
       salaryNet = salaryGross - salaryGross*POOR_TAX;
       taxRate = POOR_TAX;
     }
     else if (salaryGross>5000)
     {
       salaryNet = salaryGross - salaryGross*RICH_TAX;
       taxRate = RICH_TAX;
     }
     else
     {
       salaryNet = salaryGross - salaryGross*TAX_RATE;
       taxRate = TAX_RATE;
     }
     
     
       
    
    
   
    
    
    
    
    System.out.println("<!DOCTYPE html>");
    System.out.println();
    System.out.println("<html>");
    System.out.println();
    System.out.println("<head>");
    System.out.println("<title>"+name+"'s Home Page</title>");
    System.out.println("</head>");
    System.out.println();
    System.out.println("<body>");
    System.out.println();
    System.out.println("<hr>");
    System.out.println("<img src="+"\"big-lebowski.jpg\"");
    System.out.println("<h1>"+name+"</h1>");
    System.out.println("<p>Age: "+age+"</p>");
    System.out.println("<p>Salary: "+salaryNet+ " ["+taxRate+"]"+"</p>");
    System.out.println("<p>Comments: "+comment+"</p>");
    System.out.println("<hr>");
    System.out.println();
    System.out.println("</body>");
    System.out.println();
    System.out.println("</html>");
    

  }
  
 
}// end class
