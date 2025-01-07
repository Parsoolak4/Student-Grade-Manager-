#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


struct GradeThresholds gradeThresholds = {80, 70, 60, 50};  // Default values

float getTotal(struct Student a);
char getGrade(float total);
int compareBystudentID(const void* a, const void* b);
int compareByStudentName(const void* a, const void* b);
int compareByTotal(const void* a, const void* b);
int compareByExam(const void* a, const void* b);
void displaySpreadsheet(struct Student students[], int opt);
void updateLastName(struct Student students[]);
void gradeDistribution(struct Student students[]);
void updateExamGrade(struct Student students[]);
void updateGradeMapping();
void deleteStudent(struct Student students[], char deleteStudentID[]);
void readData();

struct Student students[20];
int studentCount=10;



int main (int argc, int argv[] ) {
readData();
int option;
int opt=1;
char studentId[5];

while (1){
printf("Spreadsheet Menu \n");
printf("------------------ \n");
printf("1. Display Spreadsheet \n");
printf("2. Display Histogram \n");
printf("3. Set sort column \n");
printf("4. Update Last Name \n");
printf("5. Update Exam Grade \n");
printf("6. Update Grade Mapping \n");
printf("7. Delete Student \n");
printf("8. Exit \n");
printf("\n");

printf("Selection: \n");

scanf("%d", &option);
char command;
switch (option) {
  case 1:{
    displaySpreadsheet(students,opt);
     printf("\nPress 'c' or 'C' to continue \n");
    scanf("%s", &command );
  } break;
  case 2:
    {
    gradeDistribution(students); //hard coded
    printf("\nPress 'c' or 'C' to continue \n");
    scanf("%s", &command );
    }
    break;
  case 3:
    {
    printf("Column Options: \n" );
    printf("--------------- \n" );
    printf("1. Student ID \n" );
    printf("2. Last Name \n" );
    printf("3. Exam \n" );
    printf("4. Total  \n" );
    printf("\n");
    scanf("%d", &opt);
    printf("\n");
    printf("Sort Column: %d\n", opt);
    printf("Sort column updated");

    printf("\nPress 'c' or 'C' to continue \n");
    scanf("%s", &command );


    }
    break;
  case 4:
  {
  updateLastName(students); //hardcoded 
  printf("Press 'c' or 'C' to continue");
  getchar();  // Consume newline
  getchar(); 
  }
    break;
  case 5:
    updateExamGrade(students);
    

    break;
  case 6:
updateGradeMapping();
    break;
  case 7:{
    printf("Enter Student ID: ");
    scanf("%s",studentId);
    deleteStudent(students,studentId);
  printf("\nPress 'c' or 'C' to continue ");
  getchar();  // Consume newline
  getchar(); 
  }
    break;
  case 8:
    
    printf("Goodbye and have a great day");
    break;
    }

    system("clear");

}



}