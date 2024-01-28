import java.util.Scanner;
public class LinearSearch {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter limt: ");
        int n = sc.nextInt();
        System.out.println("Enter array elements: ");
        int [] arr = new int [n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter element to be searched: ");
        int k = sc.nextInt();
        int count=0;
        for(int i=0;i<n;i++){
            if(k== arr[i]){
                count=1;
                System.out.println("Element " + k + " found at " + i + " th position");
                break;
            }
            else count=0;
        }
        if(count==0) System.out.println("Element not found");
        sc.close();
    }
}
