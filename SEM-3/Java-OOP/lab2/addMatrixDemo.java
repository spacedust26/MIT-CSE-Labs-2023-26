import java.util.Scanner;
public class addMatrixDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter dimensions of matrix 1: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.print("Enter dimensions of matrix 2: ");
        int p = sc.nextInt();
        int q = sc.nextInt();
        if(m!=p || n!=q){
            System.out.println("Cannot be added.");
            System.exit(0);
        } 
        System.out.print("Enter elements of matrix 1: ");
        int m1[][] = new int [m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                m1[i][j] = sc.nextInt();
            }
        }
         System.out.print("Enter elements of matrix 2: ");
        int m2[][] = new int [p][q];
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                m2[i][j] = sc.nextInt();
            }
        }
        System.out.println("Matrix Additon: ");
        int m3[][] =new int [m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                m3[i][j] = m1[i][j] + m2[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.print(m3[i][j]+ "\t");
            }
            System.out.println();
        }
        sc.close();
    }
}
