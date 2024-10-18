public class Main {
     public static void main (String[] args) {
          Regtangle test = new Regtangle(12, 22);
          test.Area();
          test.Perimeter();
          System.out.println(test.toString());
          test.GetInfoWidth();
          test.GetInfoHeight();
          test.SetInfoWidth(44);
          test.SetInfoHeight(12);
          test.Area();
          test.Perimeter();
          System.out.println(test.toString());
     }
     
}
