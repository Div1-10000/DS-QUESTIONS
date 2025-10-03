//Reverse Without Recursion
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

struct Node *Reverse(struct Node **head)
{
    struct Node *prev =NULL, *curr = *head, *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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

    head = Reverse(&head);

    printf("Reverse Linked list:--------------\n");
    display(&head);
}