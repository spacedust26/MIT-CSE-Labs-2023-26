//create a student record with name, rollno, marks of 3 subjects. Compute the average of marks for 3 students and display the names of the students in ascending order of their average marks
#include<stdio.h>
typedef struct{
  char name[20];
  int rollno;
  float m1,m2,m3;
}student;

int main(){
  student s[3];
  for(int i = 0 ; i < 3 ; i++){
    printf("Enter student %d records:\n", i+1);
    printf("Enter student name: ");
    scanf("%s",s[i].name);
    printf("Enter roll number: ");
    scanf("%d",&s[i].rollno);
    printf("Enter marks of 3 subjects: ");
    scanf("%f %f %f",&s[i].m1, &s[i].m2, &s[i].m3);
  }
  float avg[3];
  for(int i = 0 ; i < 3 ; i++){
    avg[i] = (s[i].m1 + s[i].m2 + s[i].m3)/3;
    printf("Average of student %d: %.2f\n", i+1, avg[i]);
  }
  for(int i = 0; i < 2 ; i++){
    for(int j = 0; j < 3 - i - 1 ; j++){
      if(avg[j] > avg[j+1]){
        student temp = s[j];
        s[j] = s[j+1];
        s[j+1] = temp;
        float tempAvg = avg[j];
        avg[j] = avg[j + 1];
        avg[j + 1] = tempAvg;
      }
    }
  }
  printf("Printing names in ascending order: \n");
  for(int i = 0; i < 3 ; i++){
    printf("%s ",s[i].name);
  }

}