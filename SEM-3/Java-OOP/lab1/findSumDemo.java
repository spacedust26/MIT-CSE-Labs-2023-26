import java.util.Scanner;
public class findSumDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number: ");
        int n = sc.nextInt();
        System.out.println("Sum of digits: "+ findSum(n));
        sc.close();
    }
    static int findSum(int n){
        int rd, sum=0;
        while(n>0){
            rd = n%10;
            sum+=rd;
            n/=10;
        }
        return sum;
    }
}
