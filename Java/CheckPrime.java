import java.util.Scanner;

public class CheckPrime {
     public static boolean checkPrime(int number) {
          if(number < 2)
               return false;
          for(int i = 2; i <= Math.sqrt(number); i++)
               if(number % i == 0)
                    return false;
          return true;
     }
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.print("enter an integer: ");
          int number = sc.nextInt();
          if(checkPrime(number))
               System.out.println(number + " is a prime number!");
          else
               System.out.println(number + " is not a prime number!");
     }
}
