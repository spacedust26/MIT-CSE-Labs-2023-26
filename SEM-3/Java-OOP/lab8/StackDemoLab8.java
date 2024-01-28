import java.util.Scanner;
class PushException extends Exception{
    public String toString(){
        return "Stack overflow";
    }
}
class PopException extends Exception{
    public String toString(){
        return "Stack underflow";
    }
}
class stackLab8{
    private int []arr;
    private int top;
    private int size;
    stackLab8(int l){
        size=l;
        arr= new int [size];
        top=-1;
    }
    void push(int ele) throws PushException{
        if(top == size -1){
            throw new PushException();
        }
        else{
            arr[++top] = ele;
        }
    }
    int pop() throws PopException{
        if(top==-1){
            throw new PopException();
        }
        else{
            return arr[top--];
        }
    }
    void display(){
        for(int i=0;i<=top;i++){
            System.out.print(arr[i]+" ");
        }
    }
}

public class StackDemoLab8 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size: ");
        int size = sc.nextInt();
        System.out.print("MENU: 1.Push 2.Pop 3.Display 4.Exit: ");
        stackLab8 s = new stackLab8(size);
        int choice;
        do{
            System.out.print("\nEnter choice: ");
            choice= sc.nextInt();
            switch(choice){
                case 1: {
                    System.out.print("\nEnter element to be pushed: ");
                    int ele = sc.nextInt();
                    try{s.push(ele);} catch(PushException e){System.out.println(e);}
                    break;
                }
                case 2: {
                    try{System.out.print("Element popped: "+ s.pop());}
                    catch(PopException e){System.out.println(e);}
                    break;
                }
                case 3:{
                    System.out.println("Dispalying: ");
                    s.display();
                    break;
                }
                default: break;
            }
       }while(choice!=4);
       sc.close();
    }
}
