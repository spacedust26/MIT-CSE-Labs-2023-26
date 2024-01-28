class arr{
  <T> void printArray(T []a){
    for(T x : a){
      System.out.print(x+" ");
    }
  }
}
public class array {
  public static void main(String[] args) {
    arr a = new arr();
    Integer []in = {2,3,4,5};
    a.printArray(in);
    String []s ={"abc","def","hig"};
    a.printArray(s);
  }
}
