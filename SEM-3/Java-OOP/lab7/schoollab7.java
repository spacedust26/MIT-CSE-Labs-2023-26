package com.course.structure;

import com.course.structure.buildinglab7;

public class schoollab7 extends buildinglab7{
    int classrooms;
    String gradeLevel;
    public schoollab7(double squareFootage, int stories, int classrooms, String gradeLevel){
        super(squareFootage,stories);
        this.classrooms=classrooms;
        this.gradeLevel= gradeLevel;
    }
    public void display(){
        super.display();
        System.out.println("Classrooms: " +classrooms);
        System.out.println("GradeLevel: "+ gradeLevel);
    }
}