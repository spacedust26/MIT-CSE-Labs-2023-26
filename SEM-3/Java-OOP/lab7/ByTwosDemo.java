interface Series{
    int GetNext();
    void reset();
    void setStart(int start);
}
class ByTwos{
    int start;
    int val;
    ByTwos(){
        start=0;
        val=0;
    }
    public int GetNext(){
        val+=2;
        return val;
    }
    public void reset(){
        val = start;
    }
    public void setStart(int x){
       start= val =x;
    }
}
public class ByTwosDemo {
    public static void main(String [] args){
        ByTwos bt = new ByTwos();
        bt.setStart(4);
        for(int i=0;i<5;i++)
            System.out.println(bt.GetNext());
        bt.reset();
        for(int i=0;i<5;i++)
            System.out.println(bt.GetNext());
    }
}
