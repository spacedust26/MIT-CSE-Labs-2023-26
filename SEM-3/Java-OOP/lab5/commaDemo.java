import java.util.Scanner;
class comma{
    String num;
    static int count;
    static{
        count=0;
    }
    comma(String num){
        this.num = num;
    }
    void commaCount(){
        String c="";
        String c1="";
        for(int i= num.length()-1;i>=0;i--){
            c+= num.charAt(i);
            count++;
            if(count%3==0 && i>0){
                c+=',';
            }
        }
        for(int i = c.length()-1;i>=0;i--){
            c1+= c.charAt(i);
        }
        System.out.println("Comma punctuated string is: "+ c1);
    }
}
public class commaDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number string");
        String num = sc.nextLine();
        comma com = new comma(num);
        com.commaCount();
        sc.close();
    }
}
