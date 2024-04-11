//Program to reverse an array

import java.util.Scanner;

public class reverseDemo {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter array size: ");
    int n = sc.nextInt();
    System.out.print("Enter array elements: ");
    int []arr = new int[n];
    for(int i = 0 ; i < n ; i++){
      arr[i] = sc.nextInt();
    }
    sc.close();
    System.out.println("Reversed array elements: ");
    int i,j;
    for(i = 0 ,j = n-1; i < j ; i++,j--){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    for(int k = 0 ; k  < n ; k++){
      System.out.print(arr[k] + " ");
    }
  }
}
