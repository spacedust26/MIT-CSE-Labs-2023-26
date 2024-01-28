class Phone{
    String brand;
    int memCapacity;
    Phone(String brand, int memCapacity){
        this.brand = brand;
        this.memCapacity= memCapacity;
    }
    interface Callable{
        void makeAudioCall(String cellNum);
        void makeVideoCall(String cellNum);
    }
}
class BasicPhone extends Phone implements Phone.Callable{
    BasicPhone(String brand, int memCapacity){
        super(brand,memCapacity);
    }
    public void makeAudioCall(String cellNum){
        System.out.println("Making audio call from a basic cell to "+ cellNum);
    }
    public void makeVideoCall(String cellNum){
        System.out.println("Basic phones cannot make video calls.");
    }
}
class SmartPhone extends Phone implements Phone.Callable{
    SmartPhone(String brand, int memCapacity){
        super(brand,memCapacity);
    }
    public void makeAudioCall(String cellNum){
        System.out.println("Making audio call from a smart cell to "+ cellNum);
    }
    public void makeVideoCall(String cellNum){
        System.out.println("Making video call from a smart cell to "+ cellNum);
    }
}
public class PhoneDemo {
    public static void main(String [] args){
        BasicPhone bp = new BasicPhone("Apple", 256);
        SmartPhone sp = new SmartPhone("Samsung", 512);
        bp.makeAudioCall("9999999");
        bp.makeVideoCall("1233");
        sp.makeAudioCall("0000000");
        sp.makeVideoCall("7896");
    }
}
