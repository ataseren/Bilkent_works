import java.awt.FlowLayout;
import javax.swing.JFrame;

/**
 * balloon stuff 
 * @author ata.seren
 * @version 06.04.2020
 */ 
public class Lab04b extends JFrame 
{
   public Lab04b() 
   {
      this.setTitle("Balloons");
      this.setDefaultCloseOperation(3);
      this.setLayout(new FlowLayout());
      BalloonsGamePanel bp = new BalloonsGamePanel();
      this.add(bp);
      this.pack();
      this.setVisible(true);
   }

   public static void main(String[] args) 
   {
      System.out.println("Lab04b...");
      new Lab04b();
   }
}
