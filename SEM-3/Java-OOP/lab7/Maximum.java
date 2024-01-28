package mypackages.p1;
public class Maximum{
    public static int maximum(int a, int b, int c){
        if(a>b && a>c) return a;
        else if(b>a && b> c) return b;
        else return c;
    }
    public static float maximum(float a, float b , float c){
        if(a>b && a>c) return a;
        else if(b>a && b> c) return b;
        else return c;
    }
    public static int maximum(int [] arr){
        int l = arr[0];
        for(int x : arr){
            if(x>l) l=x;
        }
        return l;
    }
    public static int maximum(int [][] arr){
        int l = arr[0][0];
        for(int one[] : arr){
            for(int x : one){
                if(x>l) l=x;
            }
        }
        return l;
    }
}