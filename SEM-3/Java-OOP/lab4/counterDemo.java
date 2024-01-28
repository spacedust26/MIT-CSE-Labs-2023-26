class counter{
    static int count;
    static{
        count=0;
    }
    counter(){
        count+=1;
    }
    static void showCount(){
        System.out.println("Count of objects: "+count);
    }
}
public class counterDemo {
    public static void main(String [] args){
        counter c1 = new counter();
        counter c2 = new counter();
        counter c3 = new counter();
        counter c4 = new counter();
        counter.showCount();
    }
}
