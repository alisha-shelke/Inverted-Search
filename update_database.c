#include "inverted_Search.h"
/*
 * Function : update_database
 * Description : Adds a new file to the existing inverted search
 *               database and updates the word information.
 */
int update_database(Wlist *head[], Flist **f_head)
{
    FILE *fptr;
    char filename[FNAME_SIZE];
    int index;
    char word[WORD_SIZE];

    printf("Enter the file name to update database: ");
    scanf("%14s", filename);

    /* Check whether file already exists in file list */
    Flist *temp = *f_head;

    while(temp != NULL)
    {
        if(strcmp(temp->file_name, filename) == 0)
        {
            printf("File %s is already present in database\n", filename);
            return FAILURE;
        }

        temp = temp->link;
    }

    /* Check whether file is available */
    fptr = fopen(filename, "r");

    if(fptr == NULL)
    {
        printf("File %s is not available\n", filename);
        return FAILURE;
    }

    /* Create new file node */
    Flist *new = malloc(sizeof(Flist));

    if(new == NULL)
    {
        fclose(fptr);
        return FAILURE;
    }

    strcpy(new->file_name, filename);
    new->link = NULL;

    /* Add new file to file list */
    if(*f_head == NULL)
    {
        *f_head = new;
    }
    else
    {
        temp = *f_head;

        while(temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new;
    }

    /*
     * Read the new file and add its
     * words to the existing database
     */
    while(fscanf(fptr, "%14s", word) == 1)
    {
        int flag = 1;

        /* Find hash index */
        index = tolower(word[0]) % 97;

        /* Check valid range */
        if(!(index >= 0 && index <= 25))
        {
            index = 26;
        }

        /* Search word in the hash table */
        if(head[index] != NULL)
        {
            Wlist *w_temp = head[index];

            while(w_temp != NULL)
            {
                if(strcmp(w_temp->word, word) == 0)
                {
                    update_word_count(&w_temp, filename);

                    flag = 0;
                    break;
                }

                w_temp = w_temp->link;
            }
        }

        /* If word is new, insert it */
        if(flag == 1)
        {
            extern char *file_name;
            file_name = filename;

            insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);

    printf("Database updated successfully with file %s\n", filename);

    return SUCCESS;
}