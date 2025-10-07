// Reverse List
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

struct Node *Position(struct Node **head, int n)
{
    struct Node *slow = *head, *fast = *head;
    for(int i = 0; i < n; i++)
    {
        if(fast == NULL) return *head;
        fast = fast->next;
    }
    if(fast == NULL)
    {
        return *head;
    }
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

struct Node *Rotate_List(struct Node **head, int k)
{
    if(*head == NULL || (*head)->next == NULL) return *head;
    int c = 0;
    struct Node *temp = *head;
    while(temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    k = k%c;
    struct Node *slow = Position(head, k);
    temp = slow->next;
    slow->next = NULL;
    struct Node *t1 = temp;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *head;
    return t1;
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
    int num, value, n;
    printf("Enter Number of Elements: ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &value);
        Insert_Node(&head, value);
    }
    printf("Enter Nth Number: ");
    scanf("%d", &n);
    printf("Linked List:-----------\n");
    display(&head);
    head = Rotate_List(&head, n);
    printf("Updated List:-----------\n");
    display(&head);
}