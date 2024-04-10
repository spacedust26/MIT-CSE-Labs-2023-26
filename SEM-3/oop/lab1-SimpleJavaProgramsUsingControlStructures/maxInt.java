// Program to find the maximum of 3 integer parameters using method 1: if-else-if ladder and method 2: nested if

import java.util.Scanner;

public class maxInt {
  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter three integer parameters: ");
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int m1 = max1(a,b,c);
    int m2 = max2(a,b,c);
    System.out.println("Using method 1: " + m1 );
    System.out.println("Using method 2: " + m2);
    sc.close();
  }
  static int max1(int x, int y, int z){
    if(x > y && x > z) return x;
    else if(y > x && y > z) return y;
    else return z;
  }
  static int max2(int x, int y, int z){
    if(x > y){
      if(x > z) return x;
      else return z;
    }else{
      if(y > z) return y;
      else return z;
    }
  }
}
