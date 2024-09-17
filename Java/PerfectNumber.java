import java.util.Scanner;

public class PerfectNumber {
     public static boolean perfectnum(int number) {
          int result = 0;
          for(int i = 1; i < number; i++) {
               if(number%i == 0) {
                    result += i;
               }
          }
          if(result == number)
               return true;
          return false;
     }
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.print("num = ");
          int number = sc.nextInt();
          if (perfectnum(number))
               System.out.println("perfect number!");
          
          
     }
}
