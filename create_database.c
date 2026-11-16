#include "inverted_Search.h"

/*
 * Function : create_database
 * Description : Reads data from all input files and creates
 *               the inverted search database.
 */

char *file_name;

void create_database(Flist *f_head, Wlist *head[])
{
    while(f_head)
    {
        // read each file one after the other
        read_datafile(f_head, head, f_head->file_name);

        // move the file head to next node
        f_head = f_head->link;
    }
}


/*
 * Function : read_datafile
 * Description : Reads words from the input file and adds them
 *               to the inverted search database.
 */

Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    (void)file;

    FILE *fptr = fopen(filename, "r");

    // validation for open
    if(fptr == NULL)
    {
        return NULL;
    }

    file_name = filename;

    char word[WORD_SIZE];

    while(fscanf(fptr, "%14s", word) == 1)
    {
        int flag = 1;

        // find the index
        int index = tolower(word[0]) % 97;

        // check for the true range
        if(!(index >= 0 && index <= 25))
        {
            index = 26;
        }

        // check whether index is empty or not
        if(head[index] != NULL)
        {
            Wlist *temp = head[index];

            while(temp)
            {
                // check whether word is already present
                if(strcmp(temp->word, word) == 0)
                {
                    update_word_count(&temp, filename);

                    flag = 0;
                    break;
                }

                // move to next word
                temp = temp->link;
            }
        }

        // if word is not present, create new node
        if(flag == 1)
        {
            insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);

    return NULL;
}


/*
 * Function : update_word_count
 * Description : Updates the word count when a word is found
 *               in the same or another input file.
 */

int update_word_count(Wlist **head, char *filename)
{
    Ltable *temp = (*head)->Tlink;

    // traverse the link table
    while(temp)
    {
        // if same file is found
        if(strcmp(temp->file_name, filename) == 0)
        {
            // increment word count
            temp->word_count++;

            return SUCCESS;
        }

        // move to next file
        if(temp->table_link == NULL)
        {
            break;
        }

        temp = temp->table_link;
    }

    // word is present in different file
    (*head)->file_count++;

    // create new link table node
    Ltable *new = malloc(sizeof(Ltable));

    if(new == NULL)
    {
        return FAILURE;
    }

    // update the fields
    new->word_count = 1;
    strcpy(new->file_name, filename);
    new->table_link = NULL;

    // link new node to last node
    temp->table_link = new;

    return SUCCESS;
}