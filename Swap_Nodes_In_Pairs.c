// Swap_Nodes_In_Pairs
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

void Swap_Node(struct Node **head)
{
    if(*head == NULL || (*head)->next == NULL) return;
    struct Node *slow = *head;
    while(slow != NULL && slow->next != NULL)
    {
        int temp = slow->data;
        slow->data = slow->next->data;
        slow->next->data = temp;
        slow = slow->next->next;
    }
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
    printf("Enter Number of Elements: ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &value);
        Insert_Node(&head, value);
    }
    printf("Linked List:-----------\n");
    display(&head);
    Swap_Node(&head);
    printf("Updated List:-----------\n");
    display(&head);
}