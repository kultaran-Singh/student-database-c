#ifndef DATABASE_H
#define DATABASE_H

FILE* createDatabase(dynamic_Array* container);
FILE* loadDatabase(dynamic_Array* container);
void saveDatabase(dynamic_Array* container, FILE* fp);
void deleteDatabase();


#endif