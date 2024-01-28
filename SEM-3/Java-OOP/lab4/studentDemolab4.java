import java.util.Scanner;
class STUDENT{
    String sname;
    double []marks_array;
    double total;
    double avg;
    STUDENT(){
        sname = "default";
        marks_array = new double [] {0.0,0.0,0.0};
    }
    STUDENT(String sname, double [] marks_array){
        this.sname = sname;
        this.marks_array = marks_array;
    }
    void display(){
        System.out.println();
        System.out.println("Student name: " + sname);
        System.out.print("Marks array: ");
        for(int i=0;i< marks_array.length;i++){
            System.out.print(marks_array[i]+ " ");
        }
    }
    void compute(){
        System.out.println();
        total=0;
        for(int i=0;i<marks_array.length;i++){
            total+= marks_array[i];
        }
        avg = total/marks_array.length;
        System.out.println("Total: " +total);
        System.out.println("Average: "+avg);
    }
}

public class studentDemolab4 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student name: ");
        String sname = sc.nextLine();
        System.out.print("Enter total subjects: ");
        int n = sc.nextInt();
        System.out.print("Enter marks in each subject: ");
        double [] marks_array = new double[n];
        for(int i=0;i<n;i++){
            marks_array[i] = sc.nextDouble();
        }
        STUDENT s = new STUDENT();
        s.display();
        s.compute();
        STUDENT s1 = new STUDENT(sname,marks_array);
        s1.display();
        s1.compute();
        sc.close();
    }
}
