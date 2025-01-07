#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

extern int studentCount;

extern struct GradeThresholds gradeThresholds; 

int compareBystudentID(const void* a, const void* b);
int compareByStudentName(const void* a, const void* b);
int compareByTotal(const void* a, const void* b);
int compareByExam(const void* a, const void* b);

float getTotal(struct Student a){
return (((float)a.A1Grade + (float)a.A2Grade + (float)a.A3Grade)/120)*25 + (float)a.midtermGrade + ((float)a.examGrade/40)*50;
}
char getGrade(float total) {
    if (total >= gradeThresholds.A) return 'A';
    if (total >= gradeThresholds.B) return 'B';
    if (total >= gradeThresholds.C) return 'C';
    if (total >= gradeThresholds.D) return 'D';
    return 'F';
}



void displaySpreadsheet(struct Student students[], int opt){
    if (opt == 1) {
    qsort (students, studentCount, sizeof(struct Student),compareBystudentID);
                  }
    else if (opt == 2){
    qsort (students, studentCount, sizeof(struct Student),compareByStudentName);
    }
    else if (opt == 3){
    qsort (students, studentCount, sizeof(struct Student),compareByExam);
    }
    else if (opt == 4){
    qsort (students, studentCount, sizeof(struct Student),compareByTotal);
    }

        
    printf("\nCOMP 348 GRADE SHEET\n");
    printf("%-6s %-10s %-10s %2s %2s %2s %-7s %-4s %-7s %-5s\n", 
        "ID", "Last", "First", "A1", "A2", "A3", "Midterm", "Exam", "Total", "Grade");
    printf("%-6s %-10s %-10s %2s %2s %2s %-7s %-4s %-7s %-5s\n", 
        "------", "----------", "----------", "--", "--", "--", "-------", "----", "-------", "-----");

    for (int i = 0; i < studentCount; i++) { // hard coded here
        // float total = getTotal(students[i]);
        char grade = getGrade(students[i].total);
        
        printf("%-6s %-10s %-10s %2d %2d %2d %-7d %-4d %7.2f %5c\n",
            students[i].studentID,
            students[i].lastName,
            students[i].firstName,
            students[i].A1Grade,
            students[i].A2Grade,
            students[i].A3Grade,
            students[i].midtermGrade,
            students[i].examGrade,
            students[i].total,
            grade);
    }
    
}

void updateLastName(struct Student students[]) {
        displaySpreadsheet(students, 1);  // Display the current spreadsheet
    char input;
    char targetID[20];
    char newLastName[20];
    int found = 0;
    
    printf("\nEnter the Student ID to update: ");
    scanf("%s", targetID);
    
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentID, targetID) == 0) {
            printf("Current last name: %s\n", students[i].lastName);
            printf("Enter new last name: ");
            scanf("%s", newLastName);
            
            strncpy(students[i].lastName, newLastName, sizeof(students[i].lastName) - 1);
            students[i].lastName[sizeof(students[i].lastName) - 1] = '\0';
            
            printf("Last name updated successfully.\n");
            found = 1;
            printf("Press 'c' or 'C' to continue \n");
            scanf("%s", &input);
            break;
        }
    }
    
    if (!found) {
        printf("Student ID not found.\n");
    }
}
void updateExamGrade(struct Student students[]) {
    displaySpreadsheet(students, 1);  // Display the current spreadsheet
    
    char input;
    char targetID[20];
    int newExamGrade;
    int found = 0;
    
    printf("\nEnter the Student ID to update exam grade: ");
    scanf("%s", targetID);
    
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentID, targetID) == 0) {
            printf("Current exam grade: %d\n", students[i].examGrade);
            printf("Enter new exam grade: ");
            scanf("%d", &newExamGrade);
            
            // Validate the new exam grade
            if (newExamGrade < 0 || newExamGrade > 40) {
                printf("Invalid exam grade. Must be between 0 and 40.\n");
                return;
            }
            
            students[i].examGrade = newExamGrade;
            students[i].total = getTotal(students[i]);  // Recalculate total
            
            printf("Exam grade updated successfully.\n");
            printf("New total: %.2f\n", students[i].total);
            printf("New grade: %c\n", getGrade(students[i].total));
            found = 1;
            printf("Press 'c' or 'C' to continue \n");
            scanf("%s", &input);

            break;
        }
    }
    
    if (!found) {
        printf("Student ID not found.\n");
    }
}

void deleteStudent(struct Student students[], char deleteStudentID[]) {

int i;
for(i=0; i<studentCount; i++){
    if(strcmp(students[i].studentID,deleteStudentID)==0){
        break;
    }
}
for (int j = i; j < studentCount-1; j++)
{
   students[j]=students[j+1];
}
studentCount--;
displaySpreadsheet(students, 1);

}



void gradeDistribution(struct Student students[]){
        int gradeDist[5] = {0}; 
        char grade;

        for (int i = 0; i < studentCount; i++) {
            grade = getGrade(getTotal(students[i]));
            switch (grade) {
                case 'A': gradeDist[0]++; break;
                case 'B': gradeDist[1]++; break;
                case 'C': gradeDist[2]++; break;
                case 'D': gradeDist[3]++; break;
                case 'F': gradeDist[4]++; break;
            }
        }

        printf("COMP 348 Grade Distribution\n");
        char grades[] = {'A', 'B', 'C', 'D', 'F'};
        for (int i = 0; i < 5; i++) {
            printf("%c: ",grades[i]);
            int stars = (gradeDist[i]);
            for (int j = 0; j < stars; j++) {
                printf("*");
            }
            printf("\n");
        }

}

void updateGradeMapping() {
    printf("\nCurrent Mapping:\n");
    printf("A: >= %.0f\n", gradeThresholds.A);
    printf("B: >= %.0f\n", gradeThresholds.B);
    printf("C: >= %.0f\n", gradeThresholds.C);
    printf("D: >= %.0f\n", gradeThresholds.D);
    printf("F: < %.0f\n", gradeThresholds.D);

    printf("\nEnter new A baseline: ");
    scanf("%f", &gradeThresholds.A);
    printf("Enter new B baseline: ");
    scanf("%f", &gradeThresholds.B);
    printf("Enter new C baseline: ");
    scanf("%f", &gradeThresholds.C);
    printf("Enter new D baseline: ");
    scanf("%f", &gradeThresholds.D);

    printf("\nNew Mapping:\n");
    printf("A: >= %.0f\n", gradeThresholds.A);
    printf("B: >= %.0f\n", gradeThresholds.B);
    printf("C: >= %.0f\n", gradeThresholds.C);
    printf("D: >= %.0f\n", gradeThresholds.D);
    printf("F: < %.0f\n", gradeThresholds.D);

    printf("\nPress 'c' or 'C' to continue ");
    char c;
    scanf(" %c", &c);  // Note the space before %c to consume any whitespace
}
