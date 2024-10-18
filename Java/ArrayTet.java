import java.lang.reflect.Array;

public class ArrayTet {
     public static void main(String[] args) {
          int[][] arr = {{2, 3, 5}, {4, 5, 6}};
          int temp = Array.getLength(arr);
          System.out.println("test array!" + temp);
          for(int i = 0; i < arr.length; i++) {
               for(int j = 0; j < arr[i].length; j++) {
                    System.out.println(arr[i][j]);
               }
          }

     }
}
