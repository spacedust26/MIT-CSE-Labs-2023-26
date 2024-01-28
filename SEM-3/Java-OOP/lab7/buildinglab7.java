package com.course.structure;
public class buildinglab7{
    double squareFootage;
    int stories;
    public buildinglab7(double squareFootage, int stories){
        this.squareFootage=squareFootage;
        this.stories= stories;
    }
    public void display(){
        System.out.println("Square Footage: " + squareFootage);
        System.out.println("Stories: "+ stories);
    }
}