import java.util.Scanner;
public class reverseDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter integer parameter: ");
        int n = sc.nextInt();
        int reverse = reverse(n);
        System.out.println("Reversed integer: "+ reverse);
        if(n==reverse) System.out.println("Palindrome");
        else System.out.println("Not palindrome");
        sc.close();
    }
    static int reverse(int n){
        int rd, rev=0;
            while(n>0){
                rd = n%10;
                rev = rev*10 + rd;
                n/=10;
            }
        return rev;
    }
}
