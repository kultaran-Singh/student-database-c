#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"
#include "dynarr.h"
#include "database.h"

int main(){

    bool isRunning = true;
    int choice = 0;
    
    dynamic_Array* students; //Creating a dynamic array
    
    initArray(&students); //Initialization

    
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
        printf("7. Save Database\n");
        printf("8. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                addStudent(students);
                break;
            case 2:
                updateStudent(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                displayAll(students);
                break;
            case 5:
                searchById(students);
                waitForEnter("Press enter to go back to menu.");
                break;
            case 6:
                printf("\e[1;1H\e[2J");

                //Loads a database from specified csv file in the same directory
                printf("Enter the name of the database to open:\n");
                char databaseName[50];
                scanf("%s", &databaseName);
                sprintf(databaseName, "%s.csv", databaseName);
                FILE *fp = fopen(databaseName, "r+");
                loadDatabase(students, fp);
                break;
            
            case 7:
                //saveDatabase(students, fp);
                break;
            case 8:
                isRunning = false; 
                if(fp)
                    fclose(fp);
                break;
            default:
                printf("Enter a valid value.\n");
                break;
        }
    }
    return 0;
}