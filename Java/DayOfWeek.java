import java.util.Scanner;

public class DayOfWeek {
     public static int dayOfWeek (int day, int month, int year) {
          int result;
          result = (day + 2*month + (3*(month + 1)) / 5 + year + (year / 4)) % 7;
          return result;
     }
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.print("day: ");
          int day = sc.nextInt();
          System.out.print("month: ");
          int month = sc.nextInt();
          System.out.print("year: ");
          int year = sc.nextInt();
          int result;
          if(month < 3) {
               month += 12;
               year -= 1;
          }
          result = dayOfWeek(day, month, year);
          System.out.println("day of week: " + result);
     }
}
