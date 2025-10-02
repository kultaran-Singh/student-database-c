#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"
#include "dynarr.h"

int main(){

    bool isRunning = true;
    int choice = 0;

    dynamic_Array* students;
    
    initArray(&students);

    
    while(isRunning){
        printf("\e[1;1H\e[2J");
        printf("┌────────────────────────────────────┐\n");
        printf("|      Student Database Manager      |\n");
        printf("└────────────────────────────────────┘\n");

        printf("Enter the function you wish to perform:\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Display All Students\n");
        printf("5. Search Student By ID\n");
        printf("6. Load Existing Database\n");
        printf("7. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                addStudent(students);
                break;
            case 2:
                //updateStudent(students);
                break;
            case 3:
                //deleteStudent(students);
                break;
            case 4:
                displayAll(students);
                break;
            case 5:
                searchById(students);
                break;
            case 6:
                //Loads a database from specified csv file in the same directory
                loadDatabase(students);
                break;

            case 7:
                isRunning = false; 
                break;
            default:
                printf("Enter a valid value.\n");
                break;
        }
    }
    return 0;
}