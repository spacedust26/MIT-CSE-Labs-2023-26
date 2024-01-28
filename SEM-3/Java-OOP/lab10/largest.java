class large{
  <T extends Comparable<T>> T largeThree(T a, T b, T c){
    T large;
    if(a.compareTo(b)>0) large =a;
    else large=b;
    if(b.compareTo(c)>0)large =b;
    else large=c;
    if(a.compareTo(c)>0)large =a;
    else large=c;
    return large;
  }
}
public class largest {
  public static void main(String[] args) {
    large l = new large();
    Integer m= l.largeThree(4, 5, 6);
    System.out.println(m);
  }
}
