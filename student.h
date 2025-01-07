#ifndef STUDENT_H
#define STUDENT_H


struct Student { 
char studentID[20];
char lastName[20];
char firstName[20];
int A1Grade;
int A2Grade;
int A3Grade; 
int midtermGrade;
int examGrade;
float total;
};

struct GradeThresholds {
    float A;
    float B;
    float C;
    float D;
};


#endif
