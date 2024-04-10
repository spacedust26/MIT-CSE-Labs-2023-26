//To find the sum of the digits of a number

import java.util.Scanner;

public class findSumDemo {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter number: ");
    int n = sc.nextInt();
    int sum = findSum(n);
    System.out.println("Sum of the digits: " + sum);
    sc.close();
  }
  static int findSum(int n){
    int sum = 0;
    while(n != 0){
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
}

