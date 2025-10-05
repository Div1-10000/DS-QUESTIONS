//Mathematical Calculation Addition
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

struct Node *Operation(struct Node **l1, struct Node **l2)
{
    struct Node *res = NULL;
    struct Node **list_ptr = &res;
    int carry = 0;
    while(*l1 != NULL || *l2 != NULL || carry)
    {
        int sum = carry;
        if(*l1)
        {
            sum += (*l1)->data;
            (*l1) = (*l1)->next;
        }
        if(*l2)
        {
            sum += (*l2)->data;
            (*l2) = (*l2)->next;
        }
        carry = sum/10;
        *list_ptr = newnode(sum%10);
        list_ptr = &((*list_ptr)->next);
    }
    return res;
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
    head = Operation(&l1, &l2);
    printf("Addition Of List:--------------\n");
    display(&head);
}