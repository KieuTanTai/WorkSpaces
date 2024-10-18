import java.util.Scanner;

public class TestString {
     public static boolean lengthIdClass (String idClass) {
          int length = idClass.length();
          if (length == 8)
               return true;
          System.out.println("length error:");
          return false;
     }

     public static boolean checkStart (String idClass) {
          if(idClass.startsWith("DCT") || idClass.startsWith("DKP"))
               return true;
          System.out.println("start id error");
          return false;
     }

     public static boolean checkEnd (String idClass) {
          String endIdClass = idClass.substring(3, idClass.length());
          try {
               Integer.parseInt(endIdClass);
               return true;
          } catch (Exception e) {
               System.out.println("this end id class is not type number!");
               return false;
          }
     }
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          String idClass;
          do {
               System.out.print("id class: ");
               idClass  = sc.nextLine().trim();
          } while((lengthIdClass(idClass) == false) || (checkStart(idClass) == false) || checkEnd(idClass) == false);
     }
     
}
