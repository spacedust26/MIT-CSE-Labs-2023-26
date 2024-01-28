class building{
    double squareFootage;
    int stories;
    building(double squareFootage, int stories){
        this.squareFootage=squareFootage;
        this.stories= stories;
    }
    void display(){
        System.out.println("Square Footage: " + squareFootage);
        System.out.println("Stories: "+ stories);
    }
}
class School extends building{
    int classrooms;
    String gradeLevel;
    School(double squareFootage, int stories, int classrooms, String gradeLevel){
        super(squareFootage,stories);
        this.classrooms=classrooms;
        this.gradeLevel= gradeLevel;
    }
    void display(){
        super.display();
        System.out.println("Classrooms: " +classrooms);
        System.out.println("GradeLevel: "+ gradeLevel);
    }
}
class House extends building{
    int bedrooms;
    int baths;
    House(double squareFootage, int stories, int bedrooms, int baths){
        super(squareFootage,stories);
        this.bedrooms=bedrooms;
        this.baths= baths;
    }
    void display(){
        super.display();
        System.out.println("Bedrooms: " +bedrooms);
        System.out.println("Baths: "+ baths);
    }
}
public class buildingDemo {
    public static void main(String [] args){
        building b = new building(5, 3);
        b.display();
        School s = new School(8, 9, 20, "elementary");
        s.display();
        House h = new House(8, 2, 4, 3);
        h.display();

    }
}
