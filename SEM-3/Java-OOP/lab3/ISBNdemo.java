import java.util.Scanner;
class ISBN{
    int isbn;
    void inputISBN(int isbn){
        this.isbn = isbn;
    }
    void checkISBN(){
        int count=0;
        int num = isbn;
        while(isbn>0){
            isbn/=10;
            count++;
        }
        if(count!=10){
            System.out.println("ISBN should be a 10 digit number.");
            return;
        }
        if(count==10){
            int sum=0,r;
            while(num>0){
                r = num%10;
                for(int i=10;i>0;i--){
                    sum+= r *(i);
                }
                num/=10;
            }
            if(sum%11==0) System.out.println("Legal ISBN");
            else System.out.println("Illegal ISBN");
        }
    }
}
public class ISBNdemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 10 digit ISBN: ");
        int isbn = sc.nextInt();
        ISBN i = new ISBN();
        i.inputISBN(isbn);
        i.checkISBN();
        sc.close();
    }
}
