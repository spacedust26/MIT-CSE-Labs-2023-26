import com.course.structure.buildinglab7;
import com.course.structure.houselab7;
import com.course.structure.schoollab7;
public class BuildingDemolab7 {
    public static void main(String [] args){
        buildinglab7 b = new buildinglab7(5, 3);
        b.display();
        schoollab7 s = new schoollab7(8, 9, 20, "elementary");
        s.display();
        houselab7 h = new houselab7(8, 2, 4, 3);
        h.display();

    }
}