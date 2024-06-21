// Implements a sorted list of numbers using a linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            list = n;
        }

        // If number belongs at beginning of list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n; 
        }

        // If number belongs later in list
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}

// Implements a list of numbers using a linked list
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            // This node is the whole list
            list = n;
        }

        // If list has numbers already
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}*/

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

//manual method - stack
int main()
{
    node* head = NULL;
    head = malloc(sizeof(node));
    head->data = 50;
    head->link = NULL;

    node* n = malloc(sizeof(node));
    n->data = 49;
    n->link = NULL;
    head->link = n;

    n = malloc(sizeof(node));
    n->data = 48;
    n->link = NULL;
    head->link->link = n;

    node *tmp = head;
    while(tmp!=NULL){
        printf("%d", tmp->data);
        tmp = tmp->link;
    }

    tmp = head;
    while(tmp!=NULL){
        node *tmplink = tmp->link;
        free(tmp);
        tmp = tmplink;
    }
    return 0;
}*/

/* automatic method - stack
int main(int argc, char* argv[])
{
    node *head = NULL;
    for(int i = 1; i<argc; i++)
    {
        int data = atoi(argv[i]);

        node *n = malloc(sizeof(struct node));
        if(n==NULL)
        {
            return 1;
        }
        n->data = data;
        n->link = NULL;

        n->link = head;
        head = n;
    }

    node *tmp = head;
    while(tmp!=NULL){
        printf("%d", tmp->data);
        tmp = tmp->link;
    }

    tmp = head;
    while(tmp!=NULL){
        node *tmplink = tmp->link;
        free(tmp);
        tmp = tmplink;
    }
    return 0;
}*/