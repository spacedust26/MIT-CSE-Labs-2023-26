import java.util.Scanner;
class EMPLOYEE{
    String Ename;
    int Eid;
    double Basic;
    double DA;
    double Gross_Sal;
    double Net_Sal;
    void read(String Ename, int Eid, double Basic){
        this.Ename = Ename;
        this.Eid = Eid;
        this.Basic = Basic;
    }
    void display(){
        System.out.println();
        System.out.println("Employee name: "+ Ename);
        System.out.println("Employee ID: "+ Eid);
        System.out.println("Basic salary: "+ Basic);
    }
    void compute_net_sal(){
        DA = 0.52 * Basic;
        Gross_Sal = Basic + DA;
        double IT = 0.3 * Gross_Sal;
        Net_Sal = Gross_Sal - IT;
        System.out.println("Net salary: "+ Net_Sal);
    }
}

public class employeeDemolab3 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of employees: ");
        int n = sc.nextInt();
        EMPLOYEE []e = new EMPLOYEE[n];
        sc.nextLine();
        for(int i=0;i<n;i++){
            System.out.println("Employee" + (i+1));
            System.out.print("Enter employee name: ");
            String Ename = sc.nextLine();
            System.out.print("Enter employee ID: ");
            int Eid = sc.nextInt();
            System.out.print("Enter basic salary: ");
            double Basic = sc.nextDouble();
            e[i] = new EMPLOYEE();
            e[i].read(Ename, Eid, Basic);
            sc.nextLine();
        }
        System.out.println("*****Displaying data*****");
        for(int i=0;i<n;i++){
            e[i].display();
            e[i].compute_net_sal();
        }
        sc.close();
    }
}
