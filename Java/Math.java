import java.util.Scanner;

public class Math {
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.print("nhap input 1: ");
          int input1 = sc.nextInt();
          System.out.print("nhap input 2 : ");
          int input2 = sc.nextInt();
          System.out.println("sum = " + (input1 + input2));
          System.out.println("multiple = " + (input1 * input2));
          System.out.println("difference = " + (input1 - input2));
          System.out.println("division = " + (input1 / input2));
     }
}
