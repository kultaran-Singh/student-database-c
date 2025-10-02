#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "dynarr.h"

void loadDatabase(dynamic_Array* container, FILE* fp){

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

}

/*void saveDatabase(dynamic_Array* container, FILE* fp){

    struct Student* array = container->array;
    for(int i = 0; i < container->size; i++){
        fprintf(fp, "%d,%s,%.2f\n", array[i].id, array[i].name, array[i].score);
    }

    printf("Database Saved Successfully.\nPress enter to go back to menu.");

    waitForEnter("Press enter to go back to menu.");
}
*/
