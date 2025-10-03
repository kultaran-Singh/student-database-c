#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "dynarr.h"

FILE* loadDatabase(dynamic_Array* container){

    printf("\e[1;1H\e[2J");

    //Loads a database from specified csv file in the same directory
    printf("Enter the name of the database to open:\n");
    char databaseName[50];
    scanf("%s", &databaseName);
    sprintf(databaseName, "%s.csv", databaseName);
    FILE *fp;
    fp = fopen(databaseName, "r+");

    if(!fp){
        printf("Database Not Found.\n");
        waitForEnter("Press enter to go back to menu.");
        return NULL;
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
    printf("Database loaded successfully.\n");
    waitForEnter("Press enter to go back to menu.");
    return fp;
}

void saveDatabase(dynamic_Array* container, FILE* fp){

    struct Student* array = container->array;
    for(int i = 0; i < container->size; i++){
        fprintf(fp, "%d,%s,%.2f\n", array[i].id, array[i].name, array[i].score);
    }
    printf("\e[1;1H\e[2J");
    printf("Database Saved Successfully.\n");

    waitForEnter("Press enter to go back to menu.");
}

FILE* createDatabase(){
    FILE* fp;
    printf("Enter the name to assign to the database: ");
    char name[25];
    scanf("%s", &name);
    sprintf(name, "%s.csv", name);

    //Checking if the file already exists 
    if(fp = fopen(name, "r")){
        printf("\e[1;1H\e[2J");
        printf("Unable to create database: File already exists.\n");
        waitForEnter("Press enter to go back to menu.");
        fclose(fp);
        return NULL;
    }
    fp = fopen(name, "w+");
    return fp;
    
}

void deleteDatabase(){

    char databaseName[50];

    printf("\e[1;1H\e[2J");
    printf("Enter the name of the database to delete:\n");
    scanf("%s", &databaseName);
    sprintf(databaseName, "%s.csv", databaseName);
    printf("Are you sure you want to delete %s?\n", databaseName);
    waitForEnter("Press enter to confirm\n");

    remove(databaseName);
    printf("Database Deleted.\n");
    waitForEnter("Press enter to go back to menu.");
    return;
}