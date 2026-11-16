#include "inverted_Search.h"

/*
 * Function : search
 * Description : Searches for a word in the inverted database
 *               and displays its file and word count details.
 */

int search(Wlist *head, char *word)
{
    Wlist *temp = head;
    Ltable *t_temp;

    // Traverse the word list
    while(temp != NULL)
    {
        // Check whether word is found
        if(strcmp(temp->word, word) == 0)
        {
            printf("\n--------------------------------------------------\n");
            printf("Word          : %s\n", temp->word);
            printf("File Count    : %d\n", temp->file_count);
            printf("--------------------------------------------------\n");

            // Traverse the link table
            t_temp = temp->Tlink;

            while(t_temp != NULL)
            {
                printf("File Name     : %s\n", t_temp->file_name);
                printf("Word Count    : %d\n", t_temp->word_count);
                printf("--------------------------------------------------\n");

                t_temp = t_temp->table_link;
            }

            return SUCCESS;
        }

        // Move to next word
        temp = temp->link;
    }

    printf("\nWord '%s' is not found in the database.\n", word);

    return FAILURE;
}