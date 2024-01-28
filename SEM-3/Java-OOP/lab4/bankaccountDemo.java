import java.util.Scanner;
class bankaccount{
    String depname;
    int accNum;
    String accType;
    double balance;
    static int roi;
    bankaccount(){
        depname="default";
        accNum = 0;
        accType ="default account";
        balance = 0.0;
    }
    bankaccount(String depname, int accNum, String accType, double balance){
        this.depname = depname;
        this.accNum = accNum;
        this.accType = accType;
        this.balance = balance;
    }
    static{
        roi=5;
    }
    void depositAmount(double deposit){
        balance+=deposit;
        System.out.println("Rs " + deposit + " is credited to your bank account. Total balance: "+ balance);
    }
    void withdrawAmount(double withdraw){
        double min = 500;
        if(balance - withdraw < min){
            System.out.println("Insufficent amount present in account");
        }
        else{
            balance-=withdraw;
            System.out.println("Rs " + withdraw + " is debited from your bank account. Total balance: "+ balance);
        }
    }
    void display(){
        System.out.println();
        System.out.println("Depositors name: " + depname);
        System.out.println("Account Number: "+ accNum);
        System.out.println("Account Type: "+accType);
        System.out.println("Bank Balance: ");
    }
    static void roidisplay(){
        System.out.println("Rate of interest: "+ roi);
    }
}
public class bankaccountDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter depositor's name: ");
        String depname = sc.nextLine();
        System.out.print("Enter account number: ");
        int accNum = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter account type: ");
        String accType = sc.nextLine();
        System.out.print("Enter balance amount: ");
        double balance = sc.nextDouble();
        bankaccount b0 = new bankaccount(depname, accNum, accType, balance);
        b0.display();
        bankaccount.roidisplay(); 
        System.out.print("Enter amount to be deposited: ");
        double deposit = sc.nextDouble();
        b0.depositAmount(deposit);
        System.out.print("Enter the amount to be withdrawn: ");
        double withdraw = sc.nextDouble();
        b0.withdrawAmount(withdraw);
        bankaccount b = new bankaccount();
        b.display();
        bankaccount.roidisplay();  
        sc.close();    
    }
} 
