//Remove Dublicate In A Unsorted List
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

void Remove_Dublicate(struct Node **head)
{
    struct Node *prev = NULL, *curr = *head, *temp = NULL;
    while(curr != NULL && curr->next != NULL)
    {
        prev = curr;
        temp = curr->next;
        while(temp != NULL)
        {
            if(curr->data == temp->data)
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
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
    printf("NULL\n\n");
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
    Remove_Dublicate(&head);
    printf("Updated Linked list:--------------\n");
    display(&head);
}