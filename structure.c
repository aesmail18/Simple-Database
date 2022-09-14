#include <stdlib.h>
#include <string.h>
#include "structure.h"

                    //Create pointer of struct size.
Database* Head_Node = NULL ;

                    //Create pointer of struct size.
Database* Previous_Node = NULL ;

                    //To count how many nodes is recorded in the database.
uint8 link_key = 0;


//=========================================================================================================================================================================================================


/*
                   Add new entry to the database.
*/
uint8 SDB_AddEntry(uint8 student_ID,uint8 student_year,uint8* course_ID,uint8* course_grade)
{

                    //To count the node in the database.
    link_key++;

                    //Loop.
    uint8 i;

                    //Create pointer of struct size.
        Database* Last_Node;

                    //Allocate a space to hold struct in the Heap.
        Database* Node = (Database*)malloc(1*sizeof(Database));

                    //Access the struct members.
        Node->student_ID = student_ID;
        Node->student_year = student_year;
        for(i = 0;i < 3;i++)
        {
            Node->course_ID[i] = course_ID[i];
            Node->course_grade[i] = course_grade[i];
        }

                    //Make last point to the same place as head.
        Last_Node = Head_Node;

                    //Assign the node number.
        Node->key = link_key;

                    //Case: first node added to the list.
        if(Head_Node == NULL && link_key == 1)
    {
        Head_Node = Node;                       //Assign the first node address to the head pointer.
        Previous_Node = Node;                   //Assign the first node address to the previous pointer.
        Head_Node->Next = NULL;                 //Make the head points to null.
        Previous_Node->Next = NULL;             //Make the previous points to null.
        printf("\n\tData has been recorded and it's the first record in the database.\n");
    }
    else
    {

                    //Case: database is not empty.
        while(Last_Node->Next != NULL)          //Check if the last node is reached.
        {
            Last_Node = Last_Node->Next;        //Make the last pointer points to the last node.
        }
        Last_Node->Next = Node;                 //Make the before last node points to the new add node.
        Node->Next = NULL;                      //Make the last node points to null.
        printf("\n\tData has been recorded at the end of the database.\n");
    }

}                   //End of the adding function.






/*
                   Delete an entry with the given ID.
*/
void SDB_DeleteEntry(uint8 student_ID)
{
                        /*
                        Cases:
                        1-Delete the first node in the database.
                        2-Delete the last node in the database.
                        3-Delete node in the middle of the database.
                        */

                    //To travel through the database.
    Database* current_node = Head_Node;
    Previous_Node = NULL;

                    //Check if the database has records.
    if(Head_Node != NULL)
    {

                    //Case 1: First node in the database.
        if(Head_Node->student_ID == student_ID && Head_Node->key == 1)
        {
            Database *temp;
            temp=Head_Node;                                                 //To save the node place.
            Head_Node=Head_Node->Next;                                      //Assign the head to the second node`s place.
            free(temp);                                                     //Delete first recorded node.
            printf("\n\tThe data deleted successfully.\n");
        }

                    //Case 3: Middle node in the database.
        else if(link_key > 0 && link_key < 10)
        {
            while(1)
            {
                Previous_Node=current_node;                                 //To save the node place.

                    //Check if the desired node is reached.
                if(current_node->student_ID != student_ID)
                {
                  printf("\n\tThe data is not recorded.\n");
                  break;
                }

                    //Check if the desired node is reached.
                else if(current_node->Next != NULL && current_node->Next->student_ID == student_ID)
                {

                    //To save the node place.
                    current_node=current_node->Next;
                    Previous_Node->Next=current_node->Next;
                    free(current_node);                                     //Delete desired recorded node.
                    printf("\n\tThe data deleted successfully.\n");
                    break;
                }
                current_node=current_node->Next;                            //Go to next node.
            }
        }

                    //Case 2: Last node in the database.
        else
        {

                    //Check if the end of the database is reached.
            if(current_node->Next == NULL)
            {
                Head_Node=NULL;                                             //Delete desired recorded node.
                printf("\n\tThe data deleted successfully.\n");
                return;


                    //Go to the last recorded node in the database.
            while(current_node->Next != NULL && link_key > 1 && link_key <= 10)
            {
                Previous_Node=current_node;
                current_node=current_node->Next;
            }
            Previous_Node->Next=NULL;                                       //Release the last node from the database.
            free(current_node);                                             //Delete the last recorded node.
            printf("\n\tThe data deleted successfully.\n");
            }
        }
    }
                    //check if their is on records in the database.
    else
    {
        printf("\n\tNo Record to be deleted, This data does not exist\n");
    }
}                   //End of the deleting function.





/*
                   Check if the database is full.
*/
uint8 isFull(void)
{
    if(SDB_GetUsedSize() == 10)
    {
        return TRUES;
    }
    else
    {
        return FALSES;
    }
}                   //End of the checking if it is full function.





/*
                   Get the number of entries in the database.
*/
uint8 SDB_GetUsedSize(void)
{
    uint8 length = 0;
    Database* current_node;
    current_node = Head_Node;
    while(current_node != NULL)
    {
        length++;
        current_node = current_node->Next;
    }
    return length;
}                   //End of the getting size function.





/*
                   Check if an entry is exist in the database.
*/
uint8 SDB_ReadEntry(uint8 student_ID,uint8 student_year,uint8* course_ID,uint8* course_grade)
{
    Database* current_node;
    current_node = Head_Node;

                    //Check if the list is empty
    if(Head_Node == NULL)
    {
        return FALSES;
    }

                    //Stop when you find the ID
    while(current_node->student_ID != student_ID
          && current_node->student_year != student_year
          && current_node->course_ID != course_ID
          && current_node->course_grade != course_grade)
    {
                    //you reached the end of the list and did not find the ID
        if(current_node->Next == NULL)
        {
            return FALSES;
        }
        else
        {
                    //Go to the next line
            current_node = current_node->Next;
        }
    }
    return TRUES;
}                   //End of the checking if an entry is exist function.





/*
                   Check if ID is exist in the database.
*/
uint8 SDB_IsIDExist(uint8 student_ID)
{
    Database* current_node;
    current_node = Head_Node;

                    //Check if the list is empty
    if(Head_Node == NULL)
    {
        return FALSES;
    }

                    //Stop when you find the ID
    while(current_node->student_ID != student_ID)
    {
                    //you reached the end of the list and did not find the ID
        if(current_node->Next == NULL)
        {
            return FALSES;
        }
        else
        {
                    //Go to the next line
            current_node = current_node->Next;
        }
    }
    return TRUES;
}                   //End of the checking if ID is exist function.






/*
                   Get the list of ID of Student.
*/
void SDB_GitIDList(void)             //This is printing function so their is no need for any Arguments.
{
                    //Assign the head to start from the beginning.
    Database* current = Head_Node;

                    //Check if the list is empty.
    if(Head_Node == NULL)
    {
        printf("\t\nThe Database is empty !!!\n");
    }

                    //Stop when reaches the last node of the database.
    while(current != NULL)
    {
        printf("\n\t[Record(The number of entry: %d,Student ID: %d)]",current->key,current->student_ID);

                    //Increment to the next node.
        current = current->Next;
    }
    printf("\n");
}                   //End of the printing function.
