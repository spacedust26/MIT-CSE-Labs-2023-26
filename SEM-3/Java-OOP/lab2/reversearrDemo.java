import java.util.Scanner;
public class reversearrDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array limit: ");
        int n = sc.nextInt();
        System.out.print("Enter array elements: ");
        int []arr = new int [n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        sc.close();
        int i,j;
        for(i=0,j=n-1;i<j;i++,j--){
            int temp = arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
        }
        System.out.print("Reversed element: ");
        for(int k=0;k<n;k++){
            System.out.print(arr[k] +" ");
        }
    }
}
