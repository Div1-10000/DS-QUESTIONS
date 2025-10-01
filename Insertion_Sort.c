//Insertion_Sort
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newnode(int value)
{
    struct Node *new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void Insert_Node(struct Node **head, int value)
{
    struct Node *new_node = newnode(value);
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

struct Node *Sorting(struct Node *sorted, struct Node *new_node)
{
    if(sorted == NULL || sorted->data >= new_node->data)
    {
        new_node->next = sorted;
        sorted = new_node;
    }
    else
    {
        struct Node *curr = sorted;
        while(curr->next != NULL && curr->next->data >= new_node->data)
        {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
    return sorted;
}

struct Node *Insertion_Sort(struct Node **head)
{
    struct Node *sorted = NULL;
    struct Node *curr = *head;
    while(curr != NULL)
    {
        struct Node *next = curr->next;
        curr->next = NULL;
        sorted = Sorting(sorted, curr);
        curr = next;
    }
    return sorted;
}

void display(struct Node **head)
{
    if(*head == NULL)
    {
        printf("Linked List Is Empty!!\n");
        return;
    }
    struct Node *temp = *head;
    while(temp != NULL)
    {
        printf("%d - > ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    struct Node *head = NULL;
    int num, value;
    printf("Enter Number Of Elements In A Linked List: ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &value);
        Insert_Node(&head, value);
    }

    head = Insertion_Sort(&head);

    printf("Shorted List:------------\n");
    display(&head);
}