package shapes;

public class Circle extends Shape implements Selectable {
   private int radius;
   boolean selected;

   public Circle() {
      this.radius = 0;
   }

   public Circle(int pRadius) {
      this.radius = pRadius;
   }

   /**
   * calculates area
   * @return area
   */  
   public double getArea() {
      return Math.pow((double)this.radius, 2.0D) * 3.141592653589793D;
   }

   /**
   * tostring method
   * @return string
   */  
   public String toString() {
      return "Circle: " + (this.selected ? "* " : "  ") + super.toString() + " " + this.radius;
   }

   /**
   * sets radius
   */  
   public void setRadius(int pRadius) {
      this.radius = pRadius;
   }

   /**
   * gets radius
   * @return radius
   */   
   public int getRadius() {
      return this.radius;
   }
   
  /**
   * selected thing
   * @return boolean
   */  
   public boolean getSelected()
  {
     return selected;
  }


   public Shape contains(int x, int y) {
      int deltaX2 = (x - this.getX()) * (x - this.getX());
      int deltaY2 = (y - this.getY()) * (y - this.getY());
      return deltaX2 + deltaY2 <= this.radius * this.radius ? this : null;
   }

   public boolean isSelected() {
      return this.selected;
   }

   public void setSelected(boolean state) {
      this.selected = state;
   }
}
