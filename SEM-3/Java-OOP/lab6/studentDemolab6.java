import java.util.Scanner;
class STUDENT{
    String sname;
    double []marks_array;
    double total;
    double avg;
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
class ScienceStudent extends STUDENT{
    private int practicalMarks;
    ScienceStudent(String sname, double [] marks_array,int practicalMarks){
        super(sname,marks_array);
        this.practicalMarks =practicalMarks;
    }
    void compute(){
        System.out.println();
        total=0;
        for(int i=0;i<marks_array.length;i++){
            total+= marks_array[i];
        }
        total+= practicalMarks;
        avg = total/(marks_array.length+1);
        System.out.println("Total: " + total);
        System.out.println("Average: "+ avg);
    }
    void displayPracticalMarks(){
        System.out.println("Practical marks: "+ practicalMarks);
    }
}
class ArtsStudent extends STUDENT{
    private String elective;
    ArtsStudent(String sname, double [] marks_array,String elective){
        super(sname,marks_array);
        this.elective= elective;
    }
    void displayElective(){
        System.out.println("Subject Elective: "+ elective);
    }
}
public class studentDemolab6 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int n = sc.nextInt();
        STUDENT []s = new STUDENT[n];
        sc.nextLine();
        for(int i=0;i<n;i++){
            System.out.print("Enter student name: ");
            String sname = sc.nextLine();
            System.out.print("Enter total subjects: ");
            int subject = sc.nextInt();
            System.out.print("Enter marks in each subject: ");
            double [] marks_array = new double[subject];
            for(int j=0;j<subject;j++){
                marks_array[j] = sc.nextDouble();
            }
            s[i] = new STUDENT(sname,marks_array);
            sc.nextLine();
        }
        for(int i=0;i<n;i++){
            s[i].display();
            s[i].compute();
        }
        STUDENT student;

        System.out.println("***********Science Student**********");
        System.out.print("Enter student name: ");
        String sname = sc.nextLine();
        System.out.print("Enter total subjects: ");
        int subject = sc.nextInt();
        System.out.print("Enter marks in each subject: ");
        double [] marks_array = new double[subject];
        for(int j=0;j<subject;j++){
            marks_array[j] = sc.nextDouble();
        }
        System.out.print("Enter Practical Marks: ");
        int practicalMarks = sc.nextInt();
        ScienceStudent ss = new ScienceStudent(sname, marks_array, practicalMarks);
        student = ss;
        student.compute();
        ss.displayPracticalMarks();

        System.out.println("***********Arts Student**********");
        sc.nextLine();
        System.out.print("Enter student name: ");
        String aname = sc.nextLine();
        System.out.print("Enter total subjects: ");
        int asubject = sc.nextInt();
        System.out.print("Enter marks in each subject: ");
        double [] amarks_array = new double[asubject];
        for(int j=0;j<asubject;j++){
            amarks_array[j] = sc.nextDouble();
        }
        sc.nextLine();
        System.out.print("Enter subject elective: ");
        String elective = sc.nextLine();
        ArtsStudent as = new ArtsStudent(aname, amarks_array, elective);
        as.displayElective();
        sc.close();
    }
}
