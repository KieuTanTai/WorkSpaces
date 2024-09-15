import java.util.Scanner;
import java.lang.Math;
public class SecondDegree {
     public static void SecondDegreeEquation (double a, double b, double c) {
          if (a == 0) {
               System.out.println("not a second degree equation!");
               return;
          }
          double result = Delta(a, b, c);
          if (result < 0)
               System.out.println("not have any solution!");
          else if (result == 0)
               System.out.println("same solution: " + (-b/2*a));
          else {
               double x1 = (-b + Math.sqrt(result)) / (2*a);
               double x2 = (-b - Math.sqrt(result)) / (2*a);
               System.out.println("have two separate solution:" + x1 + "\t" + x2);
          }
     }

     public static double Delta (double a, double b, double c) {
          double delta = (double)(Math.pow(b, 2) - 4*a*c);
          return delta;
     }
     public static void main (String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.print("a = ");
          double a = sc.nextDouble();
          System.out.print("b = ");
          double b = sc.nextDouble();
          System.out.print("c = ");
          double c = sc.nextDouble();
          SecondDegreeEquation(a, b, c);
     }
}
