import java.util.Scanner;
class SeatsFilledException extends Exception{
    public String toString(){
        return "Seats are full.";
    }
}
class studentrec{
    int reg;
    String name;
    String doj;
    short sem;
    float gpa;
    float cgpa;
    static int count;
    static{
        count=24;
    }
    studentrec(String name, String doj, short sem, float gpa, float cgpa) throws SeatsFilledException{
        count+=1;
        if(count>25) throw new SeatsFilledException();
        this.name =name;
        this.doj= doj;
        this.sem = sem;
        this.gpa=gpa;
        this.cgpa= cgpa;
        String r = doj.substring(7, 9);
        reg = Integer.valueOf(r) * 100 + count;
    }
    void display(){
        System.out.println();
        System.out.println("Registeration number: "+ reg);
        System.out.println("Full name: "+ name);
        System.out.println("Date of joining: " + doj);
        System.out.println("Semester: "+sem);
        System.out.println("GPA: "+gpa);
        System.out.println("CGPA: "+cgpa);
    }
}

public class StudentDemoLab8 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter total number of students: ");
        int n = sc.nextInt();
        studentrec []sr = new studentrec[n];
        sc.nextLine();
        try{
            for(int i=0;i<n;i++){
                System.out.print("Enter full name: ");
                String name = sc.nextLine();
                System.out.print("Enter date of joining (ddmmyyyy): ");
                String doj= sc.nextLine();
                System.out.print("Enter semester: ");
                short sem = sc.nextShort();
                System.out.print("Enter GPA: ");
                float gpa = sc.nextFloat();
                System.out.print("Enter CGPA: ");
                float cgpa = sc.nextFloat();
                sr[i] = new studentrec(name, doj, sem, gpa, cgpa);
                sc.nextLine();
            }
        }
        catch(SeatsFilledException e){System.out.println(e);}
        for(int i=0;i<n;i++){
            sr[i].display();
        }
        sc.close();
    }
}
