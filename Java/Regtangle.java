import java.util.Scanner;

public class Regtangle {
     protected double width;
     protected double height;
     private double area;
     private double perimeter;

     public Regtangle (double width, double height) {
          this.width = width;
          this.height = height;
     }

     public Regtangle () {
          this.width = 0;
          this.height = 0;
     }

     public void GetInfoWidth() {
          System.out.println("width: " + this.width);
     }

     public void GetInfoHeight() {
          System.out.println("height: " + this.height);
     }

     public void SetInfoWidth(double width) {
          this.width = width;
     }
     
     public void SetInfoHeight(double height) {
          this.height = height;
     }

     public void Area () {
          this.area = (double) this.width * this.height;
     }

     public void Perimeter () {
          this.perimeter = (double) (this.width + this.height) * 2;
     }

     public void GetInput () {
          Scanner sc = new Scanner(System.in);
          System.out.print("width = ");
          this.width = sc.nextDouble();
          System.out.print("height: ");
          this.height = sc.nextDouble();
     }

     @Override
     public String toString() {
          return ("width: " + this.width +"\n" + "height: " + this.height + "\n" + "area: " + this.area + "\n" + "perimeter: " + this.perimeter);
     }
}
