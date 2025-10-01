//Infix_To_Postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Stack
{
    char *stack;
    int top;
    int capacity;
};

struct Stack *Create_Stack(int size)
{
    struct Stack *s1;
    s1 = (struct Stack*)malloc(sizeof(struct Stack));
    s1->top = -1;
    s1->capacity = size;
    s1->stack = (char*)malloc(s1->capacity * sizeof(char));
    return s1;
}

int Empty(struct Stack *s1)
{
    return s1->top == -1;
}

void push(struct Stack *s1, int value)
{
    if(s1->top == s1->capacity-1) return;
    s1->stack[++s1->top] = value;
}

char pop(struct Stack *s1)
{
    if(Empty(s1)) return -1;
    return s1->stack[s1->top--];
}

char peek(struct Stack *s1)
{
    return s1->stack[s1->top];
}

int precedence(char op)
{
    switch(op)
    {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}

void Infix_To_Postfix(char *infix)
{
    int l = strlen(infix);
    struct Stack *s1 = Create_Stack(l);
    char postfix[50];
    int k = 0;
    for(int i = 0; i < l; i++)
    {
        char ch = infix[i];
        if(isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if(ch == '(')
        {
            push(s1, ch);
        }
        else if(ch == ')')
        {
            while(!Empty(s1) && peek(s1) != '(')
            {
                postfix[k++] = pop(s1);
            }
            pop(s1);
        }
        else
        {
            while(!Empty(s1) && precedence(peek(s1)) >= precedence(ch))
            {
                postfix[k++] = pop(s1);
            }
            push(s1, ch);
        }
    }
    while(!Empty(s1))
    {
        postfix[k++] = pop(s1);
    }
    postfix[k] = '\0';
    printf("%s", postfix);
    free(s1->stack);
    free(s1);
}

void main()
{
    char infix[50];
    printf("Enter Expression: ");
    scanf("%s", infix);
    Infix_To_Postfix(infix);
}