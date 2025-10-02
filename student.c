#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "dynarr.h"

void addStudent(dynamic_Array* container){

    printf("\e[1;1H\e[2J"); // This is a regex used to clear the screen
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

    printf("Press enter to go back to menu.");

    // Waiting for the user to press enter
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    getchar();
    
}

void searchById(dynamic_Array* container){

    printf("\e[1;1H\e[2J");

    struct Student* array = container->array;
    //Sorting the array for efficient searching
    mergeSort(array, 0, container->size-1);

    //Getting the ID to search for
    int key;
    printf("Enter the ID:\n");
    scanf("%d", &key);

    int left = 0;
    int right = container->size - 1;
    bool isFound;
    while(left <= right){

        int mid = left + (right - left)/2;
        if(array[mid].id == key){
            printf("Search Results:\n%d\t %s\t\t %.2f\n", array[mid].id, array[mid].name, array[mid].score);
            isFound = true;
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
    printf("Press enter to go back to menu.\n");
    // Waiting for the user to press enter
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    getchar();
    return;
}

void loadDatabase(dynamic_Array* container){

    printf("\e[1;1H\e[2J");

    printf("Enter the name of the database to open:\n");
    char databaseName[50];
    scanf("%s", &databaseName);
    sprintf(databaseName, "%s.csv", databaseName);
    FILE *fp = fopen(databaseName, "r+");

    if(!fp){
        printf("Database Not Found\n");
        return;
    }

    char buff[40];
    struct Student temp;

    while(fgets(buff, 40, fp)){
        
        int count = 1;
        char *element;
        char *str = strdup(buff);
        char *restElement = str;

        while((element = strtok_r(restElement, ",", &restElement))){
            
            switch(count){
                case 1:
                    temp.id = atoi(element);
                    break;
                case 2:
                    sprintf(temp.name, element);
                    break;
                case 3:
                    temp.score = atof(element);
                    break;
            }
            count++;
            
        }

        insertElement(container, temp);
        
    }
    fclose(fp);

}

void saveDatabase(dynamic_Array* container){
    
}
