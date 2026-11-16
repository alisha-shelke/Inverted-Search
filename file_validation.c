#include "inverted_Search.h"
/*
 * Function : file_validation_n_file_list
 * Description : Validates the input files and creates the
 *               file linked list.
 */
void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1; //executable file is excuded
    int empty;

    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);

        if(empty == FILE_NOTAVAILABLE)
        {
            printf("FIle %s is not avaialable\n", argv[i]);
            printf("Hence we are not adding that file into Linked List\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("Contents are empty\n");
            printf("Hence we are not adding that file into Linked List\n");
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head, argv[i]);

            if(ret_val == SUCCESS)
            {
                printf("Successfully added %s file into Linked List\n", argv[i]);
            }
            else if(ret_val == REPEATATION)
            {
                printf("File %s is repeated\n", argv[i]);
                printf("Hence we are not adding that file into Linked List\n");
            }
            else
            {
                printf("Something went wrong!!!!\n");
            }

            i++;
        }
    }
}


/*
 * Function : isFileEmpty
 * Description : Checks whether the given file is empty or not.
 */

int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");

    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }

    fseek(fptr, 0, SEEK_END);

    if(ftell(fptr) == 0)
    {
        fclose(fptr);
        return FILE_EMPTY;
    }

    fclose(fptr);

    return SUCCESS;
}

/*
 * Function : to_create_list_of_files
 * Description : Creates a new file node and adds it to the
 *               file linked list.
 */

int to_create_list_of_files(Flist **f_head, char *name)
{
    Flist *new;
    Flist *temp;

    //create new node
    new = malloc(sizeof(Flist));

    if(new == NULL)
    {
        return FAILURE;
    }

    //if list is empty
    if(*f_head == NULL)
    {
        strcpy(new->file_name, name);
        new->link = NULL;

        *f_head = new;

        return SUCCESS;
    }

    //check duplicate files
    temp = *f_head;

    while(temp != NULL)
    {
        if(strcmp(temp->file_name, name) == 0)
        {
            free(new);
            return REPEATATION;
        }

        temp = temp->link;
    }

    //go to last node
    temp = *f_head;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    //establish the link
    strcpy(new->file_name, name);
    new->link = NULL;

    temp->link = new;

    return SUCCESS;
}