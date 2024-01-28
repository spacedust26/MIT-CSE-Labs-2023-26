package com.course.structure;

import com.course.structure.buildinglab7;

public class houselab7 extends buildinglab7{
    int bedrooms;
    int baths;
    public houselab7(double squareFootage, int stories, int bedrooms, int baths){
        super(squareFootage,stories);
        this.bedrooms=bedrooms;
        this.baths= baths;
    }
    public void display(){
        super.display();
        System.out.println("Bedrooms: " +bedrooms);
        System.out.println("Baths: "+ baths);
    }
}