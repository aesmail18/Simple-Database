

/*
 ========================================================================================================================================================
 Name        : SimpleDB.c
 Author      : Ahmed Esmail
 Copyright   : @aEsmail18
 Description : Simple database project using c programming
 ==================================================================================
 Project specifications:-
 Create a database module "SimpleDB" that holds the following parameters:
  * student_ID;
  * student_year;
  * course1_ID;
  * course1_grade;
  * course2_ID;
  * course2_grade;
  * course3_ID;
  * course3_grade;

 Note: The maximum size of the database is 10 entries and the code could be modified to accept more records.

 The following interfaces should be provided:
  * uint8 SDB_GetUsedSize(void)                                                                      -> Check if the database is full.

  * uint8 isFull(void)                                                                               -> Get the number of entries in the database.

  * uint8 SDB_AddEntry(uint8 student_ID,uint8 student_year,uint8* course_ID,uint8* course_grade)     -> Add new entry to the database.

  * void SDB_DeleteEntry(uint8 student_ID)                                                           -> Delete an entry with the given ID.

  * void SDB_GitIDList(void)                                                                         -> Get the list of ID of Student.

  * uint8 SDB_IsIDExist(uint8 student_ID)                                                            -> Check if ID is exist in the database.

  * uint8 SDB_ReadEntry(uint8 student_ID,uint8 student_year,uint8* course_ID,uint8* course_grade)    -> Check if an entry is exist in the database.

 ========================================================================================================================================================
*/

#include"structure.h"
uint8 recordCounts =0;

uint8 main()
{
    uint8 OpNum,student_ID,student_year,course_ID[3],course_grade[3],i,j;
    printf("\n\n\t****************************   Hello There!   ********************************\n\n");
    printf("\n\t1- Add entry.\n\t2- Delete entry.\n\t3- Check if the database is full.\n\t4- Get the used size of the database.\n\t5- Check for matching.\n\t6- Check if ID exists.\n\t7- Git ID list.\n\t8- Exit.\n\n\n\tPlease enter the operation number: ");
    scanf("%d",&OpNum);

                    //if the user enter wrong number
    if(OpNum <=0 || OpNum >=9)
    {
        printf("\n\tPlease enter valid number!!");
       // main();
       return 0;
    }

                    //if the user want to exit
    else if(OpNum==8)
    {
        printf("\n\n\t*****     See you soon!     *****\n\n");
        return 0;
    }

                    //if the user enter right number
    else
    {
        switch(OpNum)
        {

                    //Add entry
        case 1:
            {
                recordCounts++;
                if(recordCounts>10)
                {
                    printf("\n\tSorry the database is full!\n");
                }
                else
                {
                    printf("\n\tYou are in adding entry mode.\n");
                    printf("\tPlease enter student ID: ");
                    scanf(" %d",&student_ID);
                    printf("\tPlease enter student year: ");
                    scanf(" %d",&student_year);
                    j =1;
                    for(i = 0;i < 3;i++)
                    {
                        printf("\tPlease enter course_%d ID: ",j);
                        scanf(" %d",&course_ID[i]);
                        printf("\tPlease enter course_%d grade: ",j);
                        scanf(" %d",&course_grade[i]);
                        ++j;
                    }
                    SDB_AddEntry(student_ID,student_year,course_ID,course_grade);
                    }

            }
            main();
            break;

                    //Delete entry
        case 2:
            {
                printf("\n\tYou are in deleting record mode.\n");
                printf("\tPlease enter student ID: ");
                scanf(" %d",&student_ID);
                SDB_DeleteEntry(student_ID);
            }
            main();
            break;

                    //Check if the database is full
        case 3:
            printf("\n\tYou are in checking if the database is full mode.\n");
            if(isFull()== TRUES)
            {
              printf("\n\tThe database is full.\n");
            }
            else
            {
              printf("\n\tThe database is not full.\n");
            }
            main();
            break;

                    //Get the used size of the database
        case 4:
            printf("\n\tYou are in getting used size mode.\n");
            uint8 length = SDB_GetUsedSize();
            if(length == 0)
            {
                printf("\n\tThe database is empty.\n");
                printf("\tThe used size of the database is: %d\n",length);

            }
            else if(length == 10)
            {
                printf("\n\tThe database is full.\n");
                printf("\tThe used size of the database is: %d\n",length);
            }
            else if(length > 0 || length < 10)
            {
               printf("\n\tThe used size of the database is: %d\n",length);
            }
            main();
            break;  //End of getting used size mode -> It is working properly, well done.

                    //Check for matching
        case 5:
            {
                printf("\n\tYou are in checking for match mode.\n");
                printf("\tPlease enter student ID: ");
                scanf(" %d",&student_ID);
                printf("\tPlease enter student year: ");
                scanf(" %d",&student_year);
                j =1;
                for(i = 0;i < 3;i++)
                {
                    printf("\tPlease enter course_%d ID: ",j);
                    scanf(" %d",&course_ID[i]);
                    printf("\tPlease enter course_%d grade: ",j);
                    scanf(" %d",&course_grade[i]);
                    ++j;
                }
                uint8 returns = SDB_ReadEntry(student_ID,student_year,course_ID,course_grade);
                if(returns == TRUES)
                {
                    printf("\n\tTheir is a match, data is recorded.\n");
                }
                else
                {
                   printf("\n\tTheir is no match, data is not recorded.\n");
                }
            }
            main();
            break;

                    //Check if ID exists
        case 6:
            {
                printf("\n\tYou are in checking if ID exists mode.\n");
                printf("\n\tPlease enter student ID: ");
                scanf(" %d",&student_ID);
                uint8 exsit = SDB_IsIDExist(student_ID);
                if(exsit == TRUES)
                {
                    printf("\n\tThis ID exists in the database.\n");
                }
                else
                {
                   printf("\n\tThis ID dose not exist in the database.\n");
                }
            }

            main();
            break;//End of checking if ID exists mode

                    //Get ID list
        case 7:
            printf("\n\tYou are in getting ID list mode.\n");
            SDB_GitIDList();
            main();
            break;
        }
    }

}
