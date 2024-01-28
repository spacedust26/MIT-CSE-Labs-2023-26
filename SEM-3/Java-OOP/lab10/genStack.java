interface istack<T>{
  void push(T ele)throws stackOverflowException;
  T pop() throws stackUnderflowException;
  boolean isFull();
  boolean isEmpty();
}
class stackOverflowException extends Throwable{
  public String toString(){
    return "stack overflow";
  }
}
class stackUnderflowException extends Throwable{
  public String toString(){
    return "stack underflow";
  }
}
class stack<T> implements istack<T>{
  T []a;
  int size;
  int top;
  stack(T []a){
    this.a =a;
    size = a.length;
    top=-1;
  }
  public boolean isFull(){
    return (top==size-1);
  }
  public boolean isEmpty(){
    return (top==-1);
  }
  public void push(T ele) throws stackOverflowException{
    if(isFull()) throw new stackOverflowException();
    else{
      a[++top]=ele;
    }    
  }
  public T pop() throws stackUnderflowException{
    if(isEmpty()) throw new stackUnderflowException();
    else return a[top--];
  }
}
class student{
  int sid;
  String sname;
  student(int sid, String sname){
    this.sid = sid;
    this.sname = sname;  
  }
  void display(){
    System.out.print("Student ID: "+sid);
    System.out.print("Student name: "+ sname);
  }
}
class employee{
  int eid;
  String ename;
  employee(int eid, String ename){
    this.eid = eid;
    this.ename = ename;  
  }
  void display(){
    System.out.print("Student ID: "+eid);
    System.out.print("Student name: "+ ename);
  }
}
public class genStack {
  public static void main(String[] args) {
    student []s = new student[5];
    s[0] = new student(1, "abc");
    s[1] = new student(2, "def");
    s[3] = new student(3, "hij");
    s[4] = new student(4, "klm");
    stack<student> ss = new stack<student>(s);
    try{
      ss.push(s[0]);
      ss.push(s[1]);
      student s5 = ss.pop();
      s5.display();
    }catch(stackOverflowException e){
      System.out.println(e);
    }
    catch(stackUnderflowException e){
      System.out.println(e);
    }
    

  }
}
