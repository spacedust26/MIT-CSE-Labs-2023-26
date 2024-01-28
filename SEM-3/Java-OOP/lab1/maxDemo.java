import java.util.Scanner;
public class maxDemo{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 3 integer parameters: ");
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        int m1 = max1(x, y, z);
        System.out.println("Greatest: "+ m1);
        int m2 = max2(x, y, z);
        System.out.println("Greatest: "+ m2);
        sc.close();
    }
    static int max1(int x, int y, int z){
        if(x > y && x > z) return x;
        else if (y>x && y>z) return y;
        else return z;
    }
    static int max2(int x, int y, int z){
        if(x>y){
            if(x>z) return x;
            else return z;
        }
        if(y>z) return y;
        else return z;
    }
}