import java.util.Scanner;

public class javaIII {
     public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);
          System.out.print("enter your full name: ");          
          String fullName = sc.nextLine();
          int mathScore, physhicsScore, chemistryScore;

          do {
               System.out.print("enter your math's score: ");
               mathScore = sc.nextInt();
               System.out.print("enter your physics's score: ");
               physhicsScore = sc.nextInt();
               System.out.print("enter your chemistry's score: ");
               chemistryScore = sc.nextInt();
          } while((mathScore > 10 || physhicsScore > 10 || chemistryScore > 10) || (mathScore < 0 || physhicsScore < 0 || chemistryScore < 0));
          float average = (float)(mathScore + physhicsScore + chemistryScore) / 3;
          System.out.println("Full Name: " + fullName);
          System.out.println("Math's score: " + mathScore + "\tPhysics's score: " + physhicsScore + "\tchemistry's score: " + chemistryScore);
          System.out.println("Average: " + average);
     }
}
