import java.util.Scanner;
class EMPLOYEE{
    String Ename;
    int Eid;
    double Basic;
    double DA;
    double Gross_Sal;
    double Net_Sal;
    EMPLOYEE(String Ename, int Eid, double Basic){
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

class PartTimeEmp extends EMPLOYEE{
    int hoursWorked;
    final static double hourlyRate = 100;
    PartTimeEmp(String Ename, int Eid, double Basic, int hoursWorked){
        super(Ename, Eid, Basic);
        this.hoursWorked = hoursWorked;
    }
    void compute_net_sal(){
        Net_Sal = hoursWorked *hourlyRate;
        System.out.println("Net salary of part time employee: "+ Net_Sal);
    }
    void display(){
        super.display();
        System.out.println("Hours worked: "+ hoursWorked);
        System.out.println("Hourly rate: "+ hourlyRate);
    }
}
class FullTimeEmp extends EMPLOYEE{
    double bonus;
    double deductions;
    FullTimeEmp(String Ename, int Eid, double Basic, double bonus, double deductions){
        super(Ename, Eid, Basic);
        this.bonus = bonus;
        this.deductions = deductions;
    }
    void compute_net_sal(){
        Net_Sal = Basic + bonus -deductions;
        System.out.println("Net salary of full time employee: "+ Net_Sal);
    }
     void display(){
        super.display();
        System.out.println("Bonus: "+ bonus);
        System.out.println("Deductions: "+ deductions);
    }
}
public class employeeDemolab6 {
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
            e[i] = new EMPLOYEE(Ename, Eid, Basic);
            sc.nextLine();
        }
        System.out.println("*****Displaying data*****");
        for(int i=0;i<n;i++){
            e[i].display();
            e[i].compute_net_sal();
        }
        System.out.println("**********Part time employee**********");
        System.out.print("Enter employee name: ");
        String Ename = sc.nextLine();
        System.out.print("Enter employee ID: ");
        int Eid = sc.nextInt();
        System.out.print("Enter basic salary: ");
        double Basic = sc.nextDouble();
        System.out.print("Enter number of hours worked: ");
        int hoursWorked = sc.nextInt();
        PartTimeEmp pe = new PartTimeEmp(Ename, Eid, Basic, hoursWorked);
        pe.compute_net_sal();
        pe.display();


        System.out.println("**********Full time employee**********");
        sc.nextLine();
        System.out.print("Enter employee name: ");
        String Ename1 = sc.nextLine();
        System.out.print("Enter employee ID: ");
        int Eid1 = sc.nextInt();
        System.out.print("Enter basic salary: ");
        double Basic1 = sc.nextDouble();
        System.out.print("Enter bonus: ");
        double bonus = sc.nextDouble();
        System.out.print("Enter deductions: ");
        double deductions = sc.nextDouble();
        FullTimeEmp fe = new FullTimeEmp(Ename1, Eid1, Basic1, bonus, deductions);
        fe.compute_net_sal();
        fe.display();
        sc.close();
    }
}
