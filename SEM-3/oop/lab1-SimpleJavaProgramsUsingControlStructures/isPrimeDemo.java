//Check whether an integer is prime or not 
//To generate first n prime numbers 

import java.util.Scanner;

class isPrimeDemo{
  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter one integer parameter: ");
    int n = sc.nextInt();
    if(isPrime(n) == 1) System.out.println("Prime");
    else System.out.println("Not prime");
    System.out.println("The first N prime numbers in this range are: ");
    for(int i = 2 ; i <= n ; i++){
      if(isPrime(i) == 1) System.out.print(i + " ");
    }
    sc.close();
  }
  static int isPrime(int n){
    for(int i = 2 ; i < n ; i++){
      if(n % i == 0) return 0;
    }
    return 1;
  }
}