import java.util.Scanner;

import practice.Data;
class Data{
    int n;
    boolean ctrl = false;
    synchronized void put(int val){
        if(ctrl){
            try{ wait();}
            catch(InterruptedException e){System.out.println(e);}
        }
        n=val;
        System.out.println("Put: "+ val);
        ctrl = true;
        notify();
    }
    synchronized void get(){
         if(!ctrl){
            try{ wait();}
            catch(InterruptedException e){System.out.println(e);}
        }
        System.out.println("Get: "+ n);
        ctrl = false;
        notify();
    }
}
class Producer implements Runnable{
    Data d;
    Thread t;
    int val;
    Producer(Data d,int val){
        this.d = d;
        t= new Thread(this,"Producer");
        this.val = val;
        t.start();
    } 
    public void run(){
        for(int i=0;i<=val;i++){
            d.put(i);
        }
    }
}
class Consumer implements Runnable{
    Data d;
    Thread t;
    int val;
    Consumer(Data d,int val){
        this.d = d;
        t= new Thread(this,"Consumer");
        this.val = val;
        t.start();
    } 
    public void run(){
        for(int i=0;i<=val;i++){
            d.get();
        }
    }
}
public class pcDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter limit: ");
        int n = sc.nextInt();
        Data d = new Data();
        Producer p = new Producer(d, n);
        Consumer c = new Consumer(d, n);
    }
}
