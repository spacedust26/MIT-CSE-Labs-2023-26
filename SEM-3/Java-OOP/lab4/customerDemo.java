import java.util.Scanner;
class customer{
    private int id;
    private int creditLimit;
    customer(int id, int creditLimit){
        this.id= id;
        this.creditLimit= creditLimit;
    }
    void display(){
        System.out.println();
        System.out.println("Customer ID: "+ id);
        System.out.println("Credit limit: "+creditLimit);
    }
}

public class customerDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of customers: ");
        int n = sc.nextInt();
        customer []c = new customer[n];
        for(int i=0;i<n;i++){
            System.out.println("Customer "+ (i+1));
            System.out.print("Enter Customer ID: ");
            int id = sc.nextInt();
            System.out.print("Enter credit limit: ");
            int creditLimit = sc.nextInt();
            c[i]= new customer(id, creditLimit);
        }
        for(int i=0;i<n;i++){
            c[i].display();
        }
        sc.close();
    }
}
