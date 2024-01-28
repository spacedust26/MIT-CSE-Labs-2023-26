import java.util.Scanner;
public class primeDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter integer parameter: ");
        int n = sc.nextInt();
        int p = isPrime(n);
        if(p==1) System.out.println("Prime");
        else System.out.println("Not prime");
        System.out.println("Enter N value to generate prime numbers: ");
        int N = sc.nextInt();
        int count=0;
        System.out.println("Prime numbers generated are: ");
        for(int i=1;i<=N;i++){
            if(isPrime(i)==1){
                System.out.println(i+ " ");
                count=1;
            }
        }
        if(count==0)System.out.println("No prime numbers in this range");
        sc.close();
    }
    static int isPrime(int n){
        int count=0;
        for(int i=1;i<=n;i++){
            if(n%i==0) count++;
        }
        if(count==2) return 1;
        else return 0;
    }
}
