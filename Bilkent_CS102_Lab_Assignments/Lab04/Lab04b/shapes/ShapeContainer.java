package shapes;

import java.util.ArrayList;
import java.util.Iterator;

public class ShapeContainer implements Iterable {
   ArrayList<Shape> container = new ArrayList();

   public void add(Shape s) {
      if (s instanceof Selectable) {
         this.container.add(s);
      } else {
         System.out.println("Error NOT ADDED!");
      }
   }

   public String toString() {
      String s = "ShapeContainer [\n";

      for(int i = 0; i < this.container.size(); ++i) {
         s = s + "\t" + ((Shape)this.container.get(i)).toString() + "\n";
      }

      return s + "] ";
   }

   public double getArea() {
      double totalArea = 0.0D;

      for(int i = 0; i < this.container.size(); ++i) {
         totalArea += ((Shape)this.container.get(i)).getArea();
      }

      return totalArea;
   }

   public Iterator<Shape> iterator() {
      return this.container.iterator();
   }

   public int size() {
      return this.container.size();
   }

   public Shape contains(int x, int y) {
      Iterator var3 = this.container.iterator();

      Shape s;
      do {
         if (!var3.hasNext()) {
            return null;
         }

         Shape shape = (Shape)var3.next();
         s = ((Selectable)shape).contains(x, y);
      } while(s == null);

      return s;
   }

   public void removeSelected() {
      for(int i = 0; i < this.container.size(); ++i) {
         if (((Selectable)this.container.get(i)).getSelected()) {
            this.container.remove(i);
            i--;
         }
      }

   }

   public int selectAllAt(int x, int y) {
      int count = 0;
      Iterator var4 = this.container.iterator();

      while(var4.hasNext()) {
         Shape shape = (Shape)var4.next();
         Shape s = ((Selectable)shape).contains(x, y);
         if (s != null) {
            ((Selectable)s).setSelected(true);
            ++count;
         }
      }

      return count;
   }
}
