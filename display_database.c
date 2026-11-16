#include "inverted_Search.h"

/*
 * Function : display_database
 * Description : Displays the inverted search database in a
 *               tabular format with word and file details.
 */

void display_database(Wlist *head[])
{
    int i;
    Wlist *temp;
    Ltable *t_temp;

    printf("\n");
    printf("==========================================================================\n");
    printf("                         INVERTED SEARCH DATABASE\n");
    printf("==========================================================================\n");

    printf("%-7s %-15s %-12s %-20s %-12s\n",
           "Index", "Word", "File Count", "File Name", "Word Count");

    printf("--------------------------------------------------------------------------\n");

    for(i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            temp = head[i];

            while(temp != NULL)
            {
                t_temp = temp->Tlink;

                /* First file of the word */
                if(t_temp != NULL)
                {
                    printf("%-7d %-15s %-12d %-20s %-12d\n",
                           i,
                           temp->word,
                           temp->file_count,
                           t_temp->file_name,
                           t_temp->word_count);

                    t_temp = t_temp->table_link;
                }

                /* Remaining files */
                while(t_temp != NULL)
                {
                    printf("%-7s %-15s %-12s %-20s %-12d\n",
                           "",
                           "",
                           "",
                           t_temp->file_name,
                           t_temp->word_count);

                    t_temp = t_temp->table_link;
                }

                printf("--------------------------------------------------------------------------\n");

                temp = temp->link;
            }
        }
    }

    printf("==========================================================================\n");
}