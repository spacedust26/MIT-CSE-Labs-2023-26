import java.util.Random;
class counter{
    private int count;
    counter(){
        count=0;
    }
    synchronized void increment(){
        while(count>=3){
            try{
                System.out.println("Waiting for decrement.Current count: "+ count);
                wait();
            }
            catch(InterruptedException e){System.out.println(e);}
        }
        count++;
        System.out.println("Incremented count: "+ count);
        notify();
    }
    synchronized void decrement(){
        while(count<=0){
            try{
                System.out.println("Waiting for increment.Current count: "+count);
                wait();
            }
            catch(InterruptedException e){
                System.out.println(e);
            }
        }
            count--;
            System.out.println("Decremented count: "+ count);
            notify();
    }
}
class IncrementThread implements Runnable{
    counter c ;
    Thread t;
    Random random = new Random();
    IncrementThread(counter c){
        t= new Thread(this);
        this.c = c;
        t.start();
    }
    public void run(){
        for(int i=0;i<20;i++){
            synchronized(c){c.increment();}
            try{
                Thread.sleep(random.nextInt(501));
            }
            catch(InterruptedException e){
                System.out.println(e);
            }
        }
    }
}
class DecrementThread implements Runnable{
    counter c ;
    Thread t;
    Random random = new Random();
    DecrementThread(counter c){
        t= new Thread(this);
        this.c = c;
        t.start();
    }
    public void run(){
        for(int i=0;i<20;i++){
             synchronized(c){c.decrement();}
            try{
                Thread.sleep(random.nextInt(501));
            }
            catch(InterruptedException e){
                System.out.println(e);
            }
        }
    }
}
public class CounterDemo {
    public static void main(String [] args){
        counter c = new counter();
        IncrementThread it = new IncrementThread(c);
        DecrementThread dt = new DecrementThread(c);
    }
}
