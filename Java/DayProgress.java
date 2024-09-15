import java.util.Scanner;


public class DayProgress {
     public static int getDaysInMonth(int month, int year) {
          int days;
          switch (month) {
               case 1: // January
               case 3: // March
               case 5: // May
               case 7: // July
               case 8: // August
               case 10: // October
               case 12: // December
                    days = 31;
                    break;
               case 4: // April
               case 6: // June
               case 9: // September
               case 11: // November
                    days = 30;
                    break;
               case 2: // February
                    if (isLeapYear(year)) {
                         days = 29;
                    } else {
                         days = 28;
                    }
                    break;
               default:
                    throw new IllegalArgumentException("Invalid month. Month should be between 1 and 12.");
          }
          return days;
     }
  
     public static boolean isLeapYear(int year) {
     return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
     }

     // check correct day
     public static boolean correctDay(int day, int month, int year) {
          int dayOfMonth = getDaysInMonth(month, year);
          if (day > dayOfMonth) 
               return false;
          return true;
     }

     public static void theDayBefore(int day, int month, int year) {
          if((day == 1) && (month == 1))
               System.out.println(getDaysInMonth(month + 11, year - 1) + " / " + (month + 11) + " / " + (year - 1));
          else if(day == 1)
               System.out.println(getDaysInMonth(month - 1, year) + " / " + (month - 1) + " / " + year);
          else 
               System.out.println((day - 1) + " / " + month + " / " + year);
     }

     public static void theDayAfter(int day, int month, int year) {
          if((day == getDaysInMonth(month, year)) && (month == 12))
               System.out.println( 1 + " / " + (month - 11) + " / " + (year + 1));
          else if(day == getDaysInMonth(month, year))
               System.out.println(1 + " / " + (month + 1) + " / " + year);
          else
               System.out.println((day + 1) + " / " + month + " / " + year);
     }
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          int day, month, year;
          do {
               System.out.print("\033\143");
               System.out.print("day: ");
               day = sc.nextInt();
               System.out.print("month: ");
               month = sc.nextInt();
               System.out.print("year: ");
               year = sc.nextInt();
          } while((month < 0) || (month > 31) || (correctDay(day, month, year) == false));
          theDayBefore(day, month, year);
          theDayAfter(day, month, year);
     }
}
