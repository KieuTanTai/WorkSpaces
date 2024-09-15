import java.lang.Math;
import java.util.Scanner;

public class MathWithCirle {
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.print("enter radius: ");
          float radius = sc.nextFloat();
          System.out.println("circumference = " + (Math.PI * 2 * radius));
          System.out.println("area = " + (Math.PI * Math.pow(radius, 2)));
     }
}