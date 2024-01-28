import java.util.Scanner;
class ex{
  <T>void exchange(T[] a,int m, int n){
    T temp = a[m];
    a[m] = a[n];
    a[n] = temp;
    for(T x: a){
      System.out.print(x+" ");
    }
  }
}
public class exchange {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Integer in[]={2,3,4,5};
    System.out.println("Enter the positions to be exchanged: ");
    int m = sc.nextInt();
    int n = sc.nextInt();
    ex e = new ex();
    e.exchange(in, m, n);
  }
}
