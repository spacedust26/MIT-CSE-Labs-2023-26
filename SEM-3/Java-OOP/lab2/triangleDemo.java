import java.util.Scanner;
class triangleDemo{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter row limit: ");
        int n = sc.nextInt();
        int [][] arr  = new int [n][];
        for(int i=0;i<n;i++){
            arr[i] = new int [i+1];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                arr[i][j]= i+j;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<n-i;j++){
                System.out.print("\t");
            }
            for(int k=1;k<=2*i-1;k++){
                System.out.print(arr[i-1][k-1] + " \t");
            }
            System.out.println();
        }
        sc.close();
    }
}