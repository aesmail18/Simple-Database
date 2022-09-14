#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef unsigned int uint8;

typedef struct node
{
    uint8 key;

    uint8 student_ID;
    uint8 student_year;
    uint8 course_ID[3];
    uint8 course_grade[3];

    struct node* Next;
} Database;

enum {FALSES,TRUES};                                                                             //To make the code more readable.



/*
                                                Functions
*/

uint8 SDB_GetUsedSize(void);                                                                     //Check if the database is full.

uint8 isFull(void);                                                                              //Get the number of entries in the database.

uint8 SDB_AddEntry(uint8 student_ID,uint8 student_year,uint8* course_ID,uint8* course_grade);    //Add new entry to the database.

void SDB_DeleteEntry(uint8 student_ID);                                                          //Delete an entry with the given ID.

void SDB_GitIDList(void);                                                                        //Get the list of ID of Student.

uint8 SDB_IsIDExist(uint8 student_ID);                                                           //Check if ID is exist in the database.

uint8 SDB_ReadEntry(uint8 student_ID,uint8 student_year,uint8* course_ID,uint8* course_grade);   //Check if an entry is exist in the database.

#endif // STRUCTURE_H_INCLUDED
