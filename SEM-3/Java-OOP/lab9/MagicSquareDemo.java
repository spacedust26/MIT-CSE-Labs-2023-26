import java.util.Scanner;
class MagicSquare implements Runnable{
    int [][]square;
    Thread t;
    int ti;
    int []Rowsum;
    int []Columnsum;
    int pds;
    int sds;
    boolean isUnique;
    MagicSquare(int [][]square,int ti){
        this.square= square;
        this.ti = ti;
        t = new Thread(this,"Thread"+ ti);
        Rowsum = new int [square.length];
        Columnsum = new int [square.length];
        pds=0;
        sds=0;  
        isUnique= true;
        t.start();
    }
    public void run(){
        switch(ti){
            case 0: {//uniqueness
                int k=0;
                int []unique = new int[square.length*square.length];
                for(int i=0;i<square.length;i++){
                    for(int j=0;j<square.length;j++){
                        unique[k++] = square[i][j];
                    }
                }
                for(int i=0;i<k-1;i++){
                    for(int j=i+1;j<k;j++){
                        if(unique[i]==unique[j]){
                            isUnique=false;
                            break;
                        }
                    }
                }
                break;
            }
            case 1:{//rowsum
                for(int i=0;i<square.length;i++){
                    Rowsum[i]=0;
                    for(int j=0;j<square.length;j++){
                       Rowsum[i]+= square[i][j];
                    }
                    System.out.println("Rowsum"+i+ " : " +Rowsum[i]);
                }
                break;
            }
            case 2: { //columnsum
                for(int i=0;i<square.length;i++){
                    Columnsum[i]=0;
                    for(int j=0;j<square.length;j++){
                       Columnsum[i]+= square[j][i];
                    }
                    System.out.println("Columnsum"+i+ " : " +Columnsum[i]);
                }
                break;
            }
            case 3: { //diagonal sum
                 for(int i=0;i<square.length;i++){
                    pds += square[i][i];
                }
                System.out.println("Principal diagonal sum: "+ pds);
                break;
            }
            case 4:{
                 for(int i=0;i<square.length;i++){
                    for(int j = square.length-1; j >=0; j--){
                        sds += square[i][j];
                        break;
                    }
                }
                System.out.println("Secondary diagonal sum: "+ sds);
                break;
            }
            default : break;
        }
    }

}
public class MagicSquareDemo {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter square dimensions: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        if(m!=n){
            System.out.println("The dimensions entered do not qualify for a magic square.");
            System.exit(0);
        }
        int [][]square = new int [n][n];
        System.out.println("Enter the square elements: ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                square[i][j]= sc.nextInt();
            }
        }
        MagicSquare []ms = new MagicSquare[5]; 
        for(int i=0;i<5;i++){
           ms[i] = new MagicSquare(square,i);
        }
        for(int i=0;i<5;i++){
            try{ms[i].t.join();}
            catch(InterruptedException e){System.out.println(e);}
        }
        boolean Rowsame = true;
        boolean Columnsame = true;
        for(int i=0;i<square.length-1;i++){
            for(int j=i+1;j<square.length;j++){
                if(ms[1].Rowsum[i]!=ms[1].Rowsum[j]){
                    Rowsame = false;
                    break;
                }
            }
        }
        for(int i=0;i<square.length-1;i++){
            for(int j=i+1;j<square.length;j++){
                if(ms[2].Columnsum[i]!=ms[2].Columnsum[j]){
                   Columnsame = false;
                    break;
                }
            }
        }
        if(ms[0].isUnique && Columnsame && Rowsame){
            if((ms[1].Rowsum[0]== ms[2].Columnsum[0]) && (ms[1].Rowsum[0]==ms[3].pds) && (ms[1].Rowsum[0]==ms[4].sds)){
                System.out.println("Magic Square");
            }
            else{
                System.out.println("Not a Magic square");
            }
        }
        else{
            System.out.println("Not a Magic square");
        }
    }
}
