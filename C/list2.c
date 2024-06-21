#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

void add(struct node*, int);
void add_beg(struct node**, int);
void insert(struct node*, int, int);
void count(struct node*);
void print(struct node*);
void delete_beg(struct node**);
void delete(struct node**);
void delete_pos(struct node**, int);
void delete_list(struct node*);
struct node* reverse(struct node*);
void middle(struct node*);

int main()
{
    struct node* head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    add(head, 2);
    add_beg(&head, 0);
    add(head, 4);
    insert(head, 3, 4);
    count(head);
    print(head);
    printf("\n");
    head = reverse(head);
    print(head);
    head = reverse(head);
    printf("\n");
    middle(head);
    delete_beg(&head);
    delete(&head);
    delete_pos(&head, 2);
    printf("\n");
    print(head);
    printf("\n");
    delete_list(head);
    
    return 0;
}

void add(struct node* head, int data)
{
    struct node* ptr = head;
    struct node* create = malloc(sizeof(struct node));
    create->data = data;
    create->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = create;
}

void add_beg(struct node** head, int data)
{
    struct node* create = malloc(sizeof(struct node));
    create->data = data;
    create->link = *head;
    *head = create;
}

void insert(struct node* head, int data, int position)
{
    struct node* ptr = head;
    struct node* create = malloc(sizeof(struct node));
    create->data = data;
    create->link = NULL;
    int index = position-1, count = 1;
    while(count != index)
    {
        ptr = ptr->link;
        count++;
    }
    create->link = ptr->link;
    ptr->link = create;
}

void count(struct node* head)
{
    struct node* ptr = head;
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("%d\n", count);
}

void print(struct node* head)
{
    struct node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

void delete_beg(struct node** head)
{
    if(*head == NULL) printf("List already empty");
    else
    {
        struct node* temp = *head;
        *head = temp->link;
        free(temp);
        temp = NULL;
    }
}

void delete(struct node** head)
{
    struct node* temp = *head;
    if(*head == NULL) printf("List already empty");
    else if (temp->link == NULL)
    {
        free(*head);
        *head = NULL;

    }
    else
    {
        while(temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

void delete_pos(struct node** head, int position)
{
    struct node* ptr = *head; 
    struct node* ptr2 = *head;
    int count = 1;
    while(count != position)
    {
        ptr = ptr2;
        ptr2 = ptr2->link;
        count++;
    }
    ptr->link = ptr2->link;
    free(ptr2);
}

void delete_list(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    printf("List deleted");
}

struct node* reverse(struct node* head)
{
    struct node* ptr = NULL;
    struct node* ptr2 = NULL;
    while(head != NULL)
    {
        ptr2 = head->link;
        head->link = ptr;
        ptr = head;
        head = ptr2; 
    }
    head = ptr;
    return head;
}

void middle(struct node* head)
{
    struct node* ptr = head;
    int count = 0, mid = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    ptr = head;
    while(mid != count/2)
    {
        mid++;
        ptr = ptr->link;
    }
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}