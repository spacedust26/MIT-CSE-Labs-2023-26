import java.util.Scanner;
class InvalidDayException extends Exception{
    InvalidDayException(){
        super("Invalid day entered.");
    }
}
class InavlidMonthException extends Exception{
    InavlidMonthException(){
        super("Invalid month entered.");
    }
}
class CurrentDate{
    int day;
    int month;
    int year;
    CurrentDate(int day, int month, int year){
        this.day = day;
        this.month = month;
        this.year = year;
    }
    void CreateDate() throws InvalidDayException, InavlidMonthException{
        if(month<=0 || month>12) throw new InavlidMonthException();
        if(day<=0 || day>31) throw new InvalidDayException();
        if(month==2 && (day==30 || day ==31)) throw new InvalidDayException();
        if(month ==4 || month ==6 || month==9 || month==11){
            if(day==31) throw new InvalidDayException();
        }
        else System.out.println("Current date: "+day+"/"+month+"/"+year);
    }
}
class DateDemo{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        try{
            System.out.println("Enter day, month and year: ");
            int day = sc.nextInt();
            int month = sc.nextInt();
            int year = sc.nextInt();
            CurrentDate cd = new CurrentDate(day, month, year);
            cd.CreateDate();
        }
        catch(InvalidDayException e){
            System.out.println(e);
        }
        catch(InavlidMonthException e){
            System.out.println(e);
        }
        sc.close();
    }
}