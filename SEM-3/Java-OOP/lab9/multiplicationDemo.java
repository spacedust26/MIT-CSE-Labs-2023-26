class multiplication extends Thread{
    int n;
    multiplication(int n){
        this.n=n;
        start();
    }
    public void run(){
        for(int i=1;i<=10;i++){
            System.out.println(n + " X " + i +" = " + (n*i));
        }
    }
}
public class multiplicationDemo {
    public static void main(String [] args){
        multiplication m5 = new multiplication(5);
        multiplication m7 = new multiplication(7);
    }
}
