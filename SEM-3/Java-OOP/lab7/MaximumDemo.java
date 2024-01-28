import mypackages.p1.Maximum;
public class MaximumDemo {
    public static void main(String [] args){
        System.out.println(Maximum.maximum(1, 8, 9));
        System.out.println(Maximum.maximum(7.2f, 9.8f, 5.6f));
        int []arr = new int []{1,2,3};
        System.out.println(Maximum.maximum(arr));
        int [][] arr1 = new int [][]{{1,56,3},{4,5,6}};
        System.out.println(Maximum.maximum(arr1));
    }
}
