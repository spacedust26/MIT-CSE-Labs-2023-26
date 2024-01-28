import java.lang.Math;
class wc<T extends Number>{
  T o;
  wc(T o){
    this.o=o;
  }
  boolean compare(wc <?> obj){
    if(Math.abs(this.o.doubleValue())==(Math.abs(obj.o.doubleValue())))return true;
    else return false;
  }
}
public class wildcard {
  public static void main(String[] args) {
    wc<Integer> w1 = new wc<Integer>(-5);
    wc<Double> w2 = new wc<Double>(5.0);
    if(w1.compare(w2))System.out.println("yes");
    else System.out.println("no");
  }
}

