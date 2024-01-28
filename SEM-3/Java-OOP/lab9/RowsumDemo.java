import java.util.Scanner;
class Rowsum implements Runnable{
    int arr[];
    Thread t;
    int rs;
    Rowsum(int arr[], int val){
        this.arr=arr;
        t= new Thread(this, "Thread"+val);
        rs=0;
        t.start();
    }
    public void run(){
        for(int i=0;i<arr.length;i++){
            rs+= arr[i];
        }
        System.out.println("Row sum "+t.getName()+": "+rs);
    }
}
public class RowsumDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int SUM = 0;
        System.out.println("Enter matrix dimension: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.println("Enter matrix elements: ");
        int matrix[][] = new int [m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]= sc.nextInt();
            }
        } 
        Rowsum []rowsum = new Rowsum[m];
        for(int i=0;i<m;i++){
           rowsum[i] = new Rowsum(matrix[i], i);
        }
        for(int i=0;i<matrix.length;i++){
            try{rowsum[i].t.join();}
            catch(InterruptedException e){System.out.println(e);}
            SUM += rowsum[i].rs;
        }
        System.out.println("Matrix Sum: "+SUM);
    }
}
