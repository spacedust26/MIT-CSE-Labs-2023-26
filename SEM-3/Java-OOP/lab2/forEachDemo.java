import java.util.Scanner;
public class forEachDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter N: ");
        int n = sc.nextInt();
        int [] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = i+1;
        }
        System.out.print("Arary elements are: ");
        for(int x : arr){
            System.out.print(x +" ");
        }
        sc.close();
    }
}
