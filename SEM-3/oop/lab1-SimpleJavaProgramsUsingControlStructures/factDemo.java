//To find the factorial of a number and to compute NCR

import java.util.Scanner;

public class factDemo {
  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter an integer parameter: ");;
    int num = sc.nextInt();
    int f = fact(num);
    System.out.println("The factorial is : " + f);
    System.out.print("Enter value of n and r to find nCr: ");
    int n = sc.nextInt();
    int r = sc.nextInt();
    int ncr = fact(n) / (fact(r) * fact(n-r));
    System.out.println("nCr: " + ncr);
    sc.close();
  }
  static int fact(int n){
    int f  = 1;
    for(int i = 1 ; i <= n ; i++){
      f *= i;
    }
    return f;
  }
}
