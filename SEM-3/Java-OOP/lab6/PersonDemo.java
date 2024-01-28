class person{
    private String name;
    private String dob;
    person(String name, String dob){
        this.name = name;
        this.dob = dob;
    }
    void setname(String name){
        this.name = name;
    }
    String getname(){
        return name;
    }
    void setdob(String dob){
        this.dob = dob;
    }
    String getdob(){
        return dob;
    }
}
class collegeGraduate extends person{
    private double gpa;
    private int gradYR;
    collegeGraduate(String name, String dob,double gpa, int gradYR){
        super(name, dob);
        this.gpa = gpa;
        this.gradYR = gradYR;
    }
    void setgpa(double gpa){
        this.gpa = gpa;
    }
    double getgpa(){
        return gpa;
    }
    void setgradYR(int gradYR){
        this.gradYR = gradYR;
    }
    int getgradYR(){
        return gradYR;
    }

}
public class PersonDemo {
 public static void main(String [] args){
    person p = new person("abc","1jan2000");
    System.out.println("Person name: "+ p.getname());
    System.out.println("Persons DOB: " + p.getdob());
    collegeGraduate c = new collegeGraduate("pqr", "2feb2001", 9.5, 2020);
    System.out.println("College graduate name: "+ c.getname());
    System.out.println("College graduate DOB: "+ c.getdob());
    System.out.println("College graduate GPA: "+ c.getgpa());
    c.setgradYR(2000);
    System.out.println("College graduate graduation year: "+ c.getgradYR());
 }
}
