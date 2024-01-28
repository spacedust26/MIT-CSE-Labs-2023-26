import java.util.Scanner;
class stack{
    private int []arr;
    private int top;
    private int size;
    void initialize(int size){
        this.size = size;
        arr = new int [size];
        top =-1;
    }
    boolean isEmpty(){
        if(top==-1) return true;
        else return false;
    }
    boolean isFull(){
        if(top==size-1) return true;
        else return false;
    }
    void push(int ele){
        if(!isFull()) arr[++top]= ele;
        else System.out.println("Stack overflow");
    }
    int pop(){
        if(!isEmpty()) return arr[top--];
        else{
            System.out.println("Stack underflow");
            return -99;
        }
    }
    void display(){
        System.out.println("\nDisplaying: ");
        for(int i=0;i<=top;i++){
            System.out.print(arr[i]+" ");
        }
    }
}

public class stackDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size");
        int size = sc.nextInt();
        stack s = new stack();
        s.initialize(size);
        s.push(5);
        s.push(4);
        s.push(3);
        s.push(2);
        s.display();
        s.pop();
        s.display();
        sc.close();
    }
}
