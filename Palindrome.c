//Palindrome
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

struct Node *Reverse(struct Node *head)
{
    struct Node *prev =NULL, *curr = head, *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool Palindrome(struct Node **head)
{
    if(*head == NULL || (*head)->next == NULL) return true;
    struct Node *slow = *head, *fast = *head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node *second_half = Reverse(slow->next);
    bool palindrome = true;

    struct Node *p1 = *head, *p2 = second_half;
    while(p2 != NULL)
    {
        if(p1->data != p2->data)
        {
            palindrome = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    second_half = Reverse(second_half);
    return palindrome;
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
    printf("Linked list:--------------\n");
    display(&head);

    if(Palindrome(&head))
    {
        printf("PALINDROME\n");
    }
    else
    {
        printf("NOT PALINDROME\n");
    }
}