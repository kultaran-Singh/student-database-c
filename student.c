#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "dynarr.h"

void waitForEnter(char str[]){
    printf("%s", str);
    // Waiting for the user to press enter
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    getchar();
}
void addStudent(dynamic_Array* container){

    printf("\e[1;1H\e[2J"); // This is a regex used to clear the screen, it is used throughout the program
    struct Student s1;

    //Gets the data of the student
    printf("Enter the name of the student:\n");
    scanf("%s", &s1.name);
    printf("Enter the ID of the student:\n");
    scanf("%d", &s1.id);
    printf("Enter the score of the student:\n");
    scanf("%f", &s1.score);
    
    insertElement(container,s1);
}

void displayAll(dynamic_Array* container){

    printf("\e[1;1H\e[2J"); 
    printf("ID\t    Name\t\t Score\n");
    printf("----------------------------------------\n");

    struct Student *temp = container->array;

    // Iterates and prints all the array elements to the console
    for(int i = 0; i < container->size; i++){
        printf("%d\t %s\t\t %.2f\n", temp[i].id, temp[i].name, temp[i].score);
    }

    waitForEnter("Press enter to go back to menu.");
    
}

int searchById(dynamic_Array* container){

    printf("\e[1;1H\e[2J");

    struct Student* array = container->array;
    //Sorting the array for efficient searching
    mergeSort(array, 0, container->size-1);

    //Getting the ID to search for
    int key;
    printf("Enter the ID of the student:\n");
    scanf("%d", &key);

    //Using Binary Search to search for the key
    int left = 0;
    int right = container->size - 1;
    bool isFound;
    while(left <= right){

        int mid = left + (right - left)/2;
        if(array[mid].id == key){
            printf("Search Results:\n%d\t %s\t\t %.2f\n", array[mid].id, array[mid].name, array[mid].score);
            isFound = true;

            return array[mid].id;
        }
        if (array[mid].id < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if(isFound == false){
        printf("No student with given ID.\n");
    }

}

void deleteStudent(dynamic_Array* container){
    int toDelete = searchById(container);
    struct Student* array = container->array;
    waitForEnter("Press enter to confirm deletion.");
    for(int i = toDelete - 1; i < container->size; i++){
        array[i] = array[i + 1];
    }
    container->size--;
    return;
}