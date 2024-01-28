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
    void formatEmployeeName(){
        String fname="";
        int pos=0;
        int i;
        for(i=0;i<Ename.length();i++){
            if(Ename.charAt(i)==' '){
                fname+=Ename.substring(pos, pos+1).toUpperCase();
                fname+=Ename.substring(pos+1, i).toLowerCase();
                fname+=" ";
                pos=i+1;
            }
        }
        fname+=Ename.substring(pos, pos+1).toUpperCase();
        fname+=Ename.substring(pos+1, i).toLowerCase();
        System.out.println("Formatted name: "+ fname);
    }
    void generateEmail(){
        String mailname="";
        int i;
        int pos=0;
        for(i=0;i<Ename.length();i++){
            if(Ename.charAt(i)==' '){
                mailname+= Ename.substring(pos,pos+1).toLowerCase();  
                pos=i+1;     
                mailname+= Ename.substring(pos, Ename.length()).toLowerCase();
                break;
            }
        }
        mailname+="@example.com";
        System.out.println("Email generated: "+ mailname);
    }
}

public class employeeDemolab5 {
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
            e[i].formatEmployeeName();
            e[i].generateEmail();
        }
        sc.close();
    }
}
