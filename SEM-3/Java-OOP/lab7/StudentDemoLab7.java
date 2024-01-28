import java.util.Scanner;
interface Sports{
    void putGrade();
}
class Student{
    private int rollNo;
    private double marks;
    Student(int rollNo, double marks){
        this.rollNo = rollNo;
        this.marks = marks;
    }
    void setrollNo(int rollNo){
        this.rollNo = rollNo;
    }
    int getrollNo(){
        return rollNo;
    }
    void setmarks(double marks){
        this.marks = marks;
    }
    double getmarks(){
        return marks;
    }
}
class Result extends Student implements Sports{
    String grade;
    double sportmark;
    double result;
    Result(int rollNo, double marks, String grade){
        super(rollNo, marks);
        this.grade = grade;
    }
    public void putGrade(){
        if(grade.equals("A")) sportmark = 100;
        if(grade.equals("B")) sportmark = 75;
        if(grade.equals("C")) sportmark = 50;
        if(grade.equals("D")) sportmark = 25;
        result = (sportmark + getmarks())/2;
        System.out.println("Results: " + result);
    }
}
public class StudentDemoLab7 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter roll number: ");
        int rollNo = sc.nextInt();
        System.out.println("Enter marks: ");
        double marks = sc.nextDouble();
        sc.nextLine();
        System.out.println("Enter grade in sports (A/B/C/D): ");
        String grade = sc.nextLine();
        Result r = new Result(rollNo, marks, grade);
        r.putGrade();
        sc.close();
    }
}
