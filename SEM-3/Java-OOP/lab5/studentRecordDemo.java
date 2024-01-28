import java.util.Scanner;
class studentrec{
    int reg;
    String name;
    String doj;
    short sem;
    float gpa;
    float cgpa;
    static int count;
    static{
        count=0;
    }
    studentrec(String name, String doj, short sem, float gpa, float cgpa){
        count+=1;
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
    static void sortsem(studentrec []sr){
        for(int i=0;i<sr.length-1;i++){
            for(int j=i+1;j<sr.length;j++){
                if(sr[i].sem>sr[j].sem){
                    studentrec temp = sr[i];
                    sr[i] = sr[j];
                    sr[j] = temp;
                }
            }
        }
    }
    static void sortCGPA(studentrec []sr){
        for(int i=0;i<sr.length-1;i++){
            for(int j=i+1;j<sr.length;j++){
                if(sr[i].cgpa>sr[j].cgpa){
                    studentrec temp = sr[i];
                    sr[i] = sr[j];
                    sr[j] = temp;
                }
            }
        }
    }
    static void sortName(studentrec [] sr){
        for(int i=0;i<sr.length-1;i++){
            for(int j=i+1;j<sr.length;j++){
                if(sr[i].name.compareTo(sr[j].name)>0){
                    studentrec temp = sr[i];
                    sr[i] = sr[j];
                    sr[j] = temp;
                }
            }
        }
    }
    static void charName(studentrec []sr){
        int j=0;
        int count=0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the initial character to be searched for: ");
        char c = sc.next().charAt(0);
        for(int i=0;i<sr.length;i++){
            if(sr[i].name.charAt(j)== c){
                System.out.println(sr[i].name+" ");
                count=1;
            }
        }
        if(count==0) System.out.println("No name starts with that character.");
        sc.close();
    }    
    static void substrings(studentrec [] sr){
        Scanner sc = new Scanner(System.in);
        int count=0;
        System.out.println("Enter the substring to be searched for: ");
        String sub = sc.nextLine();
        for(int i=0;i<sr.length;i++){
            if(sr[i].name.contains(sub)){
                System.out.print(sr[i].name+" ");
                count=1;
            }
        }
        if(count==0)System.out.println("No name contains the substring entered.");
        sc.close();
    }
    void familyname(){
        String rname="";
        int pos=0;
        int i;
        for(i=0;i<name.length();i++){
            if(name.charAt(i)==' '){
                rname+= name.substring(pos, pos+1).toUpperCase();
                rname+= '.';
                pos=i+1;
            }
        }
        rname+= name.substring(pos, pos+1).toUpperCase();
        rname+=name.substring(pos+1, i).toLowerCase();
        System.out.println("Modified name: "+ rname);
    }
}

public class studentRecordDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter total number of students: ");
        int n = sc.nextInt();
        studentrec []sr = new studentrec[n];
        sc.nextLine();
        for(int i=0;i<n;i++){
            System.out.print("Enter full name: ");
            String name = sc.nextLine();
            System.out.print("Enter date of joining (ddmmmyyyy): ");
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
        for(int i=0;i<n;i++){
            sr[i].display();
            sr[i].familyname();
        }
        studentrec.sortsem(sr);
        System.out.println("Sorting wrt ascending semester: ");
        for(int i=0;i<n;i++){
            sr[i].display();
        }
        System.out.println("Sorting wrt ascending CGPA: ");
        studentrec.sortCGPA(sr);
        for(int i=0;i<n;i++){
            sr[i].display();
        }
        studentrec.sortName(sr);
        System.out.println("Sorting names alphabetically: ");
        for(int i=0;i<n;i++){
            sr[i].display();
        }
        studentrec.charName(sr);
        studentrec.substrings(sr);
        sc.close();
    }
}
