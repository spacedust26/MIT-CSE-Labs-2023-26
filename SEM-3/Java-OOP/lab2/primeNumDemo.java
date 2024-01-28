import java.util.Scanner;
public class primeNumDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array limit: ");
        int n = sc.nextInt();
        System.out.print("Enter array elements: ");
        int [] arr = new int [n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        System.out.print("Prime numbers: ");
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=1;j<=arr[i];j++){
                if(arr[i]%j==0) count++;
            }
            if(count==2) System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}
