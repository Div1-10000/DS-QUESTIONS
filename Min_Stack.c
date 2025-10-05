// MIN STACK
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node
{
    int data;
    int min;
    struct Node *next;
};

struct Node *Create_Node(int value, int min_val)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->min = min_val;
    new_node->next = NULL;
    return new_node;
}

void Push(struct Node **top, int value)
{
    if(*top == NULL)
    {
        *top = Create_Node(value, value);
        return;
    }
    struct Node *new_node;
    int min_val = (value < (*top)->min)? value : (*top)->min;
    new_node = Create_Node(value, min_val);
    new_node->next = *top;
    *top = new_node;
}

void Pop(struct Node **top)
{
    if(*top == NULL)
    {
        printf("STACK UNDERFLOW CONDITION!!\n");
        return;
    }
    struct Node *temp = *top;
    printf("Deleted Element: %d", (*top)->data);
    *top = (*top)->next;
    free(temp);
}

int Peek(struct Node **top)
{
    if(*top == NULL) return INT_MIN;
    return (*top)->data;
}

int Get_min(struct Node **top)
{
    if(*top == NULL) return INT_MIN;
    return (*top)->min;
}

void Display(struct Node **top)
{
    if(*top == NULL)
    {
        printf("STACK IS EMPTY!!\n");
        return;
    }
    struct Node *temp = *top;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    struct Node *top = NULL;
    int choice, num, value;
    while(1)
    {
        printf("\nPRESS(1)>> PUSH\nPRESS(2)>> POP\nPRESS(3)>> DISPLAY\nPRESS(4)>> MINIMUM VALUE\n");
        printf("PRESS(5)>> PREEK ELEMENT\nPRESS(6)>> EXIT\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Number Of Element: ");
                scanf("%d", &num);
                for(int i = 0; i < num; i++)
                {
                    scanf("%d", &value);
                    Push(&top, value);
                }
            break;

            case 2:
                Pop(&top);
            break;

            case 3:
                Display(&top);
            break;

            case 4:
                printf("Minimum Value: %d", Get_min(&top));
            break;

            case 5:
                printf("Peek Value: %d", Peek(&top));
            break;

            case 6:
                printf("Exiting....\n");
                exit(0);
            break;

            default:
                printf("INVALID CHOICE\n");
        }
    }
}
