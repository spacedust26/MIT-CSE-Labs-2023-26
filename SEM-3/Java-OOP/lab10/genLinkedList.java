interface ilink<T>{
  void insertFirst(T data);
  node<T> deleteFirst() throws emptyLinkedListException;
  void displayll() throws emptyLinkedListException;
}
class emptyLinkedListException extends Throwable{
  public String toString(){
    return "Empty list";
  }
}
class node<T>{
  T data;
  node<T> next;
  node(T data){
    this.data = data;
  }
  void display(){
    System.out.print(data+" ");
  }
}
class linkedList<T>{
  node <T> head;
  linkedList(){
    head=null;
  }
  public void insertFirst(T data){
    node<T> newnode = new node<T>(data);
    newnode.next=head;
    head=newnode;
  }
  public node<T> deleteFirst() throws emptyLinkedListException{
    if(head==null) throw new emptyLinkedListException();
    node<T> temp = head;
    head=head.next;
    return temp;
  }
  public void displayll() throws emptyLinkedListException{
    if(head==null) throw new emptyLinkedListException();
    node<T> temp = head;
    while(temp!=null){
      temp.display();
      temp=temp.next;
    }
  }
}
class student{
  int id;
  String name;
  student(int id, String name){
    this.id=id;
    this.name=name;
  }
  void displaystudent(){
    System.out.println("ID: "+ id);
    System.out.println("Name: "+ name);
  }
}
class genLinkedList{
  public static void main(String[] args) {
    linkedList<String> l1 = new linkedList<String>();
    try{
      l1.insertFirst("abc");
      l1.insertFirst("def");
      l1.deleteFirst();
      l1.displayll();
    }catch(emptyLinkedListException e){
    System.out.println(e);
  }
  student s1= new student(1, "pranamya");
  linkedList<student> ss= new linkedList<student>();
    ss.insertFirst(s1);
    s1.displaystudent();
  }
}
