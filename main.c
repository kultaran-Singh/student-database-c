#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"
#include "dynarr.h"
#include "database.h"

int main(){

    bool isRunning = true;
    bool databaseLoaded = false;
    int choice = 0;
    
    dynamic_Array* students; //Creating a dynamic array
    
    initArray(&students); //Initialization

    
    while(isRunning){
        printf("\e[1;1H\e[2J");
        printf("┌────────────────────────────────────┐\n");
        printf("|      Student Database Manager      |\n");
        printf("└────────────────────────────────────┘\n");

        printf("1. Create New Database        2. Save Database\n\n");
        printf("3. Load Existing Database     4.Exit\n\n");
        printf("Enter the function you wish to perform: ");
        

        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                //createDatabase(students);
                databaseLoaded = true;
                break;
            case 2:
                //saveDatabase(students);
                break;
            case 3:
                printf("\e[1;1H\e[2J");

                //Loads a database from specified csv file in the same directory
                printf("Enter the name of the database to open:\n");
                char databaseName[50];
                scanf("%s", &databaseName);
                sprintf(databaseName, "%s.csv", databaseName);
                FILE *fp = fopen(databaseName, "r+");
                loadDatabase(students, fp);

                databaseLoaded = true;
                break;
            case 4:
                isRunning = false; 
                databaseLoaded = false;
                if(fp)
                    fclose(fp);
                break;
            default:
                printf("Enter a valid value.\n");
                break;
        }

        while(databaseLoaded){
            printf("\e[1;1H\e[2J");
            printf("┌────────────────────────────────────┐\n");
            printf("|      Student Database Manager      |\n");
            printf("└────────────────────────────────────┘\n\n");

            printf("1. Add Student         2.Delete Student\n\n");
            printf("3. Update Student      4.Display All Students\n\n");
            printf("5. Search Student      6.Exit\n\n");

            printf("Enter the function you wish to perform: ");

            scanf("%d", &choice);

            switch(choice){
                case 1:
                    addStudent(students);
                    break;
                case 2:
                    deleteStudent(students);
                    break;
                case 3:
                    updateStudent(students);
                    break;
                case 4:
                    displayAll(students);
                    break;
                case 5:
                    searchById(students);
                    waitForEnter("Press enter to go back to menu.");
                    break;
                case 6:
                    //saveDatabase(students);
                    databaseLoaded = false;
                    break;
            }
        }
    }
    return 0;
}