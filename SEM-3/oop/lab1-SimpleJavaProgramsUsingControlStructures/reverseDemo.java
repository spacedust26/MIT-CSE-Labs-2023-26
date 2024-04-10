//Program to reverse an integer parameter and return the reverse of the accepted digits 
//Check if palindrome

import java.util.Scanner;

public class reverseDemo {
  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter number: ");
    int n = sc.nextInt();
    int rev = reverse(n);
    System.out.println("Reversed number : " + rev);
    if(n == rev) System.out.println("Palindrome");
    else System.out.println("Not a palindrome");
    sc.close();
  }
  static int reverse(int n){
    int rev = 0;
    while(n != 0){
      rev = (rev * 10) + (n % 10);
      n /= 10;
    }
    return rev;
  }
}
