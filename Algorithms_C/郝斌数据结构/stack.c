/*** stack ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define EATLINE while(getchar() != '\n')continue
typedef struct node
{
    int data;
    struct node *pnext;
}NODE, * Pnode;

typedef struct stack
{
    Pnode top;
    Pnode buttom;
}STACK, * Pstack;

bool StackIsEmpty(Pstack stack);
bool PushStack(Pstack stack);
bool PopStack(Pstack stack);
void TraverseStack(Pstack stack);
void ClearStack(Pstack stack);
void InitStack(Pstack stack);
void ShowStack(Pstack stack);
static char GetChoice(void);

int main(void)
{
    char choice;
    STACK stack;
    InitStack(&stack);

    while ((choice = GetChoice()) != 'q')
    {
        switch(choice)
        {
            case 'a': PushStack(&stack);
                break;
            case 'b': PopStack(&stack);
                break;
            case 'c': TraverseStack(&stack);
                break;
            case 'd': ShowStack(&stack);
                break;
            default: puts("The error choice!");
        }
    }
    puts("The stack content:");
    ShowStack(&stack);
    ClearStack(&stack);

    return 0;
}

void InitStack(Pstack stack)
{
    stack->top = (Pnode)malloc(sizeof(NODE));
    if (stack->top == NULL)
    {
        puts("Error in locate the memory!");
        exit(EXIT_FAILURE);
    }
    stack->buttom = stack->top;
    stack->top->pnext = NULL;
}

bool StackIsEmpty(Pstack stack)
{
    return (stack->top)==(stack->buttom) ? true:false;
}

bool PushStack(Pstack stack)
{
    int value;
    Pnode pnew = (Pnode)malloc(sizeof(NODE));
    if (pnew == NULL)
    {
        puts("Error in locating memory!");
        return false;
    }
    puts("Enter the data you want to save:");
    while (scanf("%d", &value) != 1)
    {
        EATLINE;
        puts("Error value you input, try again:");
    }
    pnew->data = value;
    pnew->pnext = stack->top;
    stack->top = pnew;
    
    return true;
}

bool PopStack(Pstack stack)
{
    Pnode temp;
    int data;
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return false;
    }
    
    temp = stack->top;
    temp = temp->data;
    stack->top = temp->pnext;
    free(temp);
    temp = NULL;
    printf("pop %d from stack\n", data);

    return true;
}

static char GetChoice(void)
{
    char ch;
    puts("\nEnter the choice:");
    puts("a)puch stack          b)pop stack");
    puts("c)traverse stack      d)show stack");
    puts("q)quit");
    while ((ch = getchar()) != '\n')
    {
        EATLINE;
        if (strchr("abcde", ch) == NULL)
        {
            printf("%c is not a right choice, try again:\n", ch);
        }
        else
        {
            break;
        }
    }
    if (ch == '\n')
        ch = 'q';

    return ch;
}

