package mypackages.pintegers;
import java.util.Scanner;
public class sort {
    int []arr;
    public sort(int [] arr){
        this.arr = arr;
    }
    public void IntSort(){
        int n = arr.length;
        for(int i=0;i<n-1;i++){
            int min=i;
            for(int j =i+1;j<n;j++){
                if(arr[j]<arr[min]){
                    min=j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        System.out.print("\nSelection sort:");
        for(int x : arr){
            System.out.print(x+" ");
        }
    }
    public void BinSearch(){
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter element to be searched: ");
        int k = sc.nextInt();
        int n = arr.length;
        int low=0;
        int high = n-1;
        int count=0;
        do{
            int mid =(low+high)/2;
            if(k<arr[mid]){
                high = mid-1;
            }
            if(k>arr[mid]){
                low= mid+1;
            }
            if(k==arr[mid]){
                count=1;
                System.out.println("\nElement " + k +" found at "+ mid );
                break;
            }
        }while(low<=high);
        if(count==0) System.out.println("\nElement "+ k+ " not found");
    }
}
