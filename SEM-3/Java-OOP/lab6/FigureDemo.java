abstract class figure{
    int a;
    int b;
    figure(int a, int b){
        this.a =a;
        this.b = b;
    }
    figure(int c){
        a=c;
        b=c;
    }
    abstract double area();
}
class rectangle extends figure{
    rectangle(int a, int b){
        super(a,b);
    }
    double area(){
        return a*b;
    }
}
class triangle extends figure{
    triangle(int a, int b){
        super(a,b);
    }
    double area(){
        return 0.5*a*b;
    }
}
class square extends figure{
    square(int a){
        super(a);
    }
    double area(){
        return a*a;
    }
}
public class FigureDemo {
    public static void main(String args[]){
        figure f;
        rectangle r = new rectangle(2, 5);
        triangle t = new triangle(2, 4);
        square s = new square(9);
        f=r;
        System.out.println("Rectangle area: "+ f.area());
        f = t;
        System.out.println("Triangle area: "+ f.area());
        f=s;
        System.out.println("Square area: "+ f.area());
    }
}
