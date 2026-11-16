#include "inverted_Search.h"
/*
 * Function : save_database
 * Description : Saves the inverted search database into a
 *               database file for future use.
 */
int save_database(Wlist *head[])
{
    char filename[FNAME_SIZE];
    FILE *databasefile;
    int i;

    printf("Enter the database file name: ");
   scanf("%14s", filename);

    databasefile = fopen(filename, "w");

    if(databasefile == NULL)
    {
        printf("Unable to create database file\n");
        return FAILURE;
    }

    for(i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            write_databasefile(head[i], &databasefile, i);
        }
    }

    fclose(databasefile);

    printf("Database saved successfully\n");

    return SUCCESS;
}
/*
 * Function : write_databasefile
 * Description : Writes the word and its file details into
 *               the database file.
 */

void write_databasefile(Wlist *head, FILE **databasefile, int index)
{
    Wlist *temp = head;
    Ltable *t_temp;

    while(temp != NULL)
    {
        fprintf(*databasefile, "#%d;%s;%d;",
                index,
                temp->word,
                temp->file_count);

        t_temp = temp->Tlink;

        while(t_temp != NULL)
        {
            fprintf(*databasefile, "%s;%d;",
                    t_temp->file_name,
                    t_temp->word_count);

            t_temp = t_temp->table_link;
        }

        fprintf(*databasefile, "#\n");

        temp = temp->link;
    }
}