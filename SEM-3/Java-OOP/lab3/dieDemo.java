import java.util.Random;
class die{
    int sideUp;
    int getSideUp(){
        return sideUp;
    }
    void roll(){
        Random rand = new Random();
        int min=1;
        int max=6;
        sideUp = rand.nextInt(max - min +1) + min;
    }
}

public class dieDemo {
    public static void main(String [] args){
        die d1 = new die();
        die d2 = new die();
        d1.roll();
        d2.roll();
        int m= d1.getSideUp();
        int n =d2.getSideUp();
        System.out.println(m);
        System.out.println(n);
        System.out.println("SUM: "+ (m+n));
    }

}
