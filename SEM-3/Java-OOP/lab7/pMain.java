import java.util.Scanner;
import mypackages.pintegers.sort;
public class pMain {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int [] arr = new int [n];
        System.out.println("Enter array elemennts: ");
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        sort s = new sort(arr);
        s.IntSort();
        s.BinSearch();
        sc.close();
    }
}
