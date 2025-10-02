#ifndef DYNARR_H
#define DYNARR_H

typedef struct{
    size_t size;
    size_t capacity;
    struct Student* array;
} dynamic_Array;

void initArray(dynamic_Array** arr_ptr);
void insertElement(dynamic_Array* container, struct Student s1);
void mergeSort(struct Student* arr, int left, int right);
void merge(struct Student* arr, int left, int mid, int right);

#endif