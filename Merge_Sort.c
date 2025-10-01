//Merge_Short
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

struct Node *merge_sort(struct Node **l1, struct Node **l2)
{
    struct Node t1;
    struct Node *temp = &t1;
    t1.next = NULL;
    while(*l1 && *l2)
    {
        if((*l1)->data <= (*l2)->data)
        {
            temp->next = *l1;
            *l1 = (*l1)->next;
        }
        else
        {
            temp->next = *l2;
            *l2 = (*l2)->next;
        }
        temp = temp->next;
    }
    if(*l1 != NULL)
    {
        temp->next = *l1;
    }
    else
    {
        temp->next = *l2;
    }
    return t1.next;
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
    struct Node *head = NULL, *l1 = NULL, *l2 = NULL;
    int num, value;
    printf("Enter Number Of Elements in Linked List(1): ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &value);
        Insert_Node(&l1, value);
    }

    printf("Enter Number Of Elements in Linked List(2): ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &value);
        Insert_Node(&l2, value);
    }

    head = merge_sort(&l1, &l2);
    printf("Merged List:--------------\n");
    display(&head);
    l1 = NULL;
    l2 = NULL;
}