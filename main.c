/*
 * ============================================================
 *                 INVERTED SEARCH PROJECT
 * ============================================================
 * Name : Alisha Shelke
 *
 * Description:
 * This project implements an Inverted Search using a hash table
 * and linked lists to efficiently store and search words from
 * multiple text files.
 *
 * Features:
 * 1. Create and Display Database
 * 2. Search for a Word
 * 3. Save Database to a File
 * 4. Update Database with New Files
 * ============================================================
 */

#include "inverted_Search.h"

/*
 * Function : main
 * Description : Controls the program flow and displays the menu
 *               for all inverted search operations.
 */

int main(int argc, char *argv[])
{
    int option;

    Wlist *head[27] = {NULL};

    system("clear");

    // Validation for CLA
    if(argc <= 1)
    {
        printf("Enter the valid number of arguments\n");
        printf("./insearch file1.txt file2.txt\n");
        return 0;
    }

    // Create the File linked list
    Flist *f_head = NULL;

    // Validation of file availability, duplicate, empty file
    file_validation_n_file_list(&f_head, argv);

    if(f_head == NULL)
    {
        printf("No files are added to the list\n");
        printf("Hence the process got terminated\n");
        return -1;
    }

    // Menu
    while(1)
    {
        printf("\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Save Database\n");
        printf("5. Update Database\n");
        printf("6. Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                create_database(f_head, head);
                printf("\nDatabase created successfully\n");
                break;

            case 2:
                display_database(head);
                break;

            case 3:
            {
                char word[WORD_SIZE];
                int index;

                printf("Enter the word to search : ");
                scanf("%14s", word);

                index = hash_function(word);

                search(head[index], word);

                break;
            }

            case 4:
                save_database(head);
                break;

            case 5:
                update_database(head, &f_head);
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Enter the valid option\n");
        }
    }

    return 0;
}