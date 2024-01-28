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
    void extractInitials(){
        int pos=0;
        int i;
        String initials="";
        for(i=0;i<sname.length();i++){
            if(sname.charAt(i)==' '){
                initials+= sname.substring(pos,pos+1).toUpperCase();
                pos=i+1;
            }
        }
        initials+= sname.substring(pos,pos+1).toUpperCase();
        System.out.println("Initals: "+ initials);
    }
    void removeWhitespace(){
        String whitespace="";
        for(int i=0;i<sname.length();i++){
            if(sname.charAt(i)!=' '){
                whitespace+= sname.charAt(i);
            }
        }
        System.out.println("Name without white spaces: "+ whitespace);
    }
    static void substrings(STUDENT [] s){
        Scanner sc = new Scanner(System.in);
        int count=0;
        System.out.print("Enter the substring to be searched: ");
        String sub = sc.nextLine();
        for(int i=0;i<s.length;i++){
            if(s[i].sname.contains(sub)){
                System.out.println(s[i].sname+" ");
                count=1;
            }
        }
        if(count==0)System.out.println("Substring not found");
        sc.close();
    }
    static void sort(STUDENT []s){
        for(int i=0;i<s.length-1;i++){
            for(int j=i+1;j<s.length;j++){
                if(s[i].sname.compareTo(s[j].sname)>0){
                    STUDENT st = s[i];
                    s[i] = s[j];
                    s[j] = st;
                }
            }
        }
    }
}

public class studentDemolab5 {
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
            s[i].extractInitials();
            s[i].removeWhitespace();
        }
        STUDENT.substrings(s);
        STUDENT.sort(s);
        for(int i=0;i<n;i++){
            s[i].display();
        }
        sc.close();
    }
}
