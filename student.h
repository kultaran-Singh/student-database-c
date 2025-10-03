#ifndef STUDENT_H
#define STUDENT_H
#include "dynarr.h"

struct Student{
    int id;
    char name[50];
    float score;
};

void addStudent(dynamic_Array* container);
void updateStudent(dynamic_Array* container);
void displayAll(dynamic_Array* container);
int searchById(dynamic_Array* container);
void deleteStudent(dynamic_Array* container);
void waitForEnter(char str[]);

#endif