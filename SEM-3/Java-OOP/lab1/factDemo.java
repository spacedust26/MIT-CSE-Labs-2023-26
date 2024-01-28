import java.util.Scanner;
public class factDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter integer parameter: ");
        int n = sc.nextInt();
        System.out.println("Factorial : "+factorial(n));
        System.out.println("Enter r value: ");
        int r = sc.nextInt();
        System.out.println("nCr: "+ factorial(n)/(factorial(r)*factorial(n-r)));
        sc.close();
    }
    static int factorial(int n){
        int f =1;
        for(int i=1;i<=n;i++){
            f= f*i;
        }
        return f;
    }

}
