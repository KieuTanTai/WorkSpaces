import java.util.Scanner;

public class FirstDegree {
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          double result;
          System.out.print("a = ");
          double a = sc.nextDouble();
          System.out.print("b = ");
          double b = sc.nextDouble();
          if (a == 0)
               if (b==0)
                    System.out.println("infinite many solution!");
               else
                    System.out.println("there is no solution");
          else {
               result = (-b) / 2*a;
               System.out.println("result = " + result);
          }
     }
}
