import java.util.Scanner;
class intarr{
    int []arr;
    intarr(){
        arr = new int []{ 0,1,2,3};
    }
    intarr(int []arr){
        this.arr = arr;
    }
    void display(){
        System.out.println("\nDisplaying: ");
        for(int x:  arr){
            System.out.println(x+" ");
        }
    }
    void search(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter element to be searched: ");
        int k = sc.nextInt();
        int count=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==k){
                System.out.println(k + " found at position "+ i);
                count=1;
                return;
            }
        }
        if(count==0)System.out.println("Element "+ k+ " not found.");
    }
    void compare(intarr a1, intarr a2){
        for(int i=0;i<a1.arr.length;i++){
            if(a1.arr[i]== a2.arr[i]){
                System.out.println("Equal arrays");
                return ;
            }
        }
        System.out.println("Unequal arrays");
    }
}

public class intarrDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter array1 limit: ");
        int n = sc.nextInt();
        System.out.println("Enter array1 elements: ");
        int []arr = new int [n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        intarr a1 = new intarr(arr);
        a1.display();
        a1.search();
        System.out.println("Enter array2 limit: ");
        int m = sc.nextInt();
        System.out.println("Enter array2 elements: ");
        int []arr2 = new int [m];
        for(int i=0;i<m;i++){
            arr2[i] = sc.nextInt();
        }
        intarr a2 = new intarr(arr2);
        a2.display();
        a2.search();
        a2.compare(a1, a2);
        sc.close();
    }
}
