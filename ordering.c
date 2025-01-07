#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

extern int studentCount;

int compareBystudentID(const void* a, const void* b){
    if (strlen(((struct Student*)a)->studentID)!=4) return 1;
    if (strlen(((struct Student*)b)->studentID)!=4) return -1;

return atoi(((struct Student*)a)->studentID) - atoi(((struct Student*)b)->studentID);
}

int compareByStudentName(const void* a, const void* b) {
    // Compare the student names using strcmp
    return strcmp(((struct Student*)a)->lastName, ((struct Student*)b)->lastName);
}

int compareByTotal(const void* a, const void* b) {
    // Compare the total grade of students using strcmp
    return ((struct Student*)b)->total - (((struct Student*)a)->total);
}


int compareByExam(const void* a, const void* b) {
    // Compare the total grade of students using strcmp
    return ((struct Student*)b)->examGrade - (((struct Student*)a)->examGrade);
}