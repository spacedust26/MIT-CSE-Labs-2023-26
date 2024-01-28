import java.util.Scanner;
class Mixer{
    int []arr;
    void accept(int [] arr){
        this.arr = arr;
    }
    Mixer mix(Mixer A){
        int m = this.arr.length;
        int n = A.arr.length;
        int num =this.arr.length + A.arr.length;
        int [] res = new int [num];
        for(int i=0;i<m;i++){
            res[i] = this.arr[i];
        }
        for(int i=0;i<n;i++){
            res[m+i] = A.arr[i];
        }
        for(int i=0;i<num-1;i++){
            for(int j=i+1;j<num;j++){
                if(res[i]>res[j]){
                    int temp = res[i];
                    res[i]= res[j];
                    res[j]= temp;
                }
            }
        }
        Mixer m3 = new Mixer();
        m3.accept(res);
        return m3;
    }
    void display(){
        System.out.println();
        System.out.println("Displaying: ");
        for(int i=0;i<this.arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
}

public class MixerDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array1 limit: ");
        int m = sc.nextInt();
        System.out.print("Enter array1 elements: ");
        int []arr1 = new int[m];
        for(int i=0;i<m;i++){
            arr1[i] = sc.nextInt();
        }
        System.out.print("Enter array2 limit: ");
        int n = sc.nextInt();
        System.out.print("Enter array2 elements: ");
        int []arr2 = new int[n];
        for(int i=0;i<n;i++){
            arr2[i] = sc.nextInt();
        }
        Mixer mi1 = new Mixer();
        mi1.accept(arr1);
        mi1.display();
        Mixer mi2 = new Mixer();
        mi2.accept(arr2);
        mi2.display();
        Mixer mi3;
        mi3 = mi1.mix(mi2);
        mi3.display();
        sc.close();
    }
}
