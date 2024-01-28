import java.util.Scanner;
import java.util.ArrayList;
class substring{
    String data;
    String sub;
    substring(String data, String sub){
        this.data = data;
        this.sub = sub;
    }
    void find(){
        int count=0;
        ArrayList<Integer> c = new ArrayList<>();
        for(int i=0;i<data.length();i++){
            if(data.substring(i).startsWith(sub)){
                count++;
                c.add(i);
            }
        }
        if(count==0) System.out.println("String not found");
        else{
            System.out.print("Sub string found at " + count +" positions namely ");
            for(int pos : c){
                System.out.print(pos + " ");
            }
        }
    }
}
public class substringDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter string: ");
        String data= sc.nextLine();
        System.out.println("Enter substring to be found: ");
        String sub = sc.nextLine();
        substring ss = new substring(data,sub);
        ss.find();
        sc.close();
    }
}
