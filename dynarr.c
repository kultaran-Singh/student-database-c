#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "dynarr.h"

void initArray(dynamic_Array** arr_ptr){
    
    dynamic_Array* container;
    container = (dynamic_Array*)malloc(sizeof(dynamic_Array));
    if(!container){
        printf("Memory Allocation Failed");
        exit(0);
    }
    
    container->size = 0;
    container->capacity = 100;
    container->array = (struct Student*)malloc(sizeof(struct Student)*100);
    if(!container->array){
        printf("Memory Allocation Failed");
        exit(0);
    }
    *arr_ptr = container;
}

void insertElement(dynamic_Array* container, struct Student s1){
    // If array is full, doubles the capacity
    if(container->size == container->capacity){
        struct Student *temp = container->array;
        container->capacity <<= 1;
        container->array = realloc(container->array, container->capacity * sizeof(struct Student));
        if(!container->array) {
            printf("Out of Memory\n");
            container->array = temp;
            return;
        }
    }
    // Adding the student to the array
    container->array[container->size++] = s1;
}

void merge(struct Student* arr, int left, int mid, int right) {
    int i, j, k; // Indices
    int n1 = mid - left + 1; 
    int n2 = right - mid;

    // Create temporary arrays
    struct Student leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].id <= rightArr[j].id) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left-right]
void mergeSort(struct Student* arr, int left, int right) {
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}