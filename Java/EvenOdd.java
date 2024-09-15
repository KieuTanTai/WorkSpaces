import java.util.Scanner;

public class EvenOdd {
     public static boolean checkEvenOdd(int number) {
          if (number % 2 == 0)
               return true;
          return false;
     }
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.print("enter an integer: ");
          int number = sc.nextInt();
          if(checkEvenOdd(number))
               System.out.println("Even number!");
          else
               System.out.println("Odd number!");
     }
}
