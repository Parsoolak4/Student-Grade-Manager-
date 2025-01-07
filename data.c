
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

extern struct Student students[20];


float getTotal(struct Student a);
void readData(){
    FILE *fptr;
    fptr = fopen("Students.txt", "r");
    char myString[100];
    char *token;


    int i = 0; 
    while(fgets(myString,100,fptr)){
    struct Student s1;
    token = strtok(myString, "|");
    strncpy(s1.studentID, token, sizeof(s1.studentID) - 1);

    token = strtok(NULL, "|");
    strncpy(s1.lastName, token, sizeof(s1.lastName) - 1);

    token = strtok(NULL, "|");
    strncpy(s1.firstName, token, sizeof(s1.firstName) - 1);

    token = strtok(NULL, "|");
    s1.A1Grade = atoi(token);

    token = strtok(NULL, "|");
    s1.A2Grade = atoi(token);

    token = strtok(NULL, "|");
    s1.A3Grade = atoi(token);

    token = strtok(NULL, "|");
    s1.midtermGrade = atoi(token);

    token = strtok(NULL, "|");
    s1.examGrade = atoi(token);

    s1.total = getTotal(s1);
    students[i]=s1;
    i+=1;
    printf("\n");
    }
    fclose(fptr);
}
