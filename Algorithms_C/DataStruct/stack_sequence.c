/*** stack sequeuce ***/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 10
#define EATLINE while(getchar() != '\n')continue
typedef struct stack
{
    int *pint;
    int top;
}STACK;

bool InitializeStack(STACK *pstack);
bool StackIsEmpty(STACK *pstack);
bool StackIsFull(STACK *pstack);
bool PushStack(STACK *pstack);
bool PopStack(STACK *pstack);
void ClearStack(STACK *pstack);
void ShowStack(STACK *pstack);
static char GetChoice(void);

int main(void)
{
    char choice;
    STACK stack;
    InitializeStack(&stack);

    while ((choice = GetChoice()) != 'q')
    {
        switch (choice)
        {
            case 'a': PushStack(&stack);
                break;
            case 'b': PopStack(&stack);
                break;
            case 'c': ShowStack(&stack);
                break;
            default: puts("The error in this program!");
        }
    }
    puts("The stack content:");
    ShowStack(&stack);
    ClearStack(&stack);

    return 0;
}

bool InitializeStack(STACK *pstack)
{
    pstack->pint = (int *)malloc(sizeof(int) * SIZE);
    if (pstack->pint == NULL)
    {
        puts("Can\'t locate memory!");
        return false;
    }
    pstack->top = -1;

    return true;
}

bool StackIsEmpty(STACK *pstack)
{
    return (pstack->top == -1)? true:false;
}

bool StackIsFull(STACK *pstack)
{
    return (pstack->top == SIZE)? true:false;
}

bool PushStack(STACK *pstack)
{
    if (StackIsFull(pstack))
    {
        puts("The stack is full!");
        return false;
    }
    int data, ch;
    puts("Enter the data you want to push:");
    while (scanf("%d", &data) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a number! try again:");
    }
    EATLINE;

    (pstack->top)++;
    (pstack->pint)[pstack->top] = data;

    return true;
}

bool PopStack(STACK *pstack)
{
    if (StackIsEmpty(pstack))
    {
        puts("The stack is empty!");
        return false;
    }
    int data;
    data = (pstack->pint)[pstack->top];
    (pstack->top)--;
    printf("The poped data is:%d \n", data);

    return true;
}

void ShowStack(STACK *pstack)
{
    if (StackIsEmpty(pstack))
    {
        puts("The stack is empty!");
        return;
    }
    int save = pstack->top;
    for (int i=0; i<=save; i++)
    {
        printf("%d ", (pstack->pint)[i]);
    }
    putchar('\n');
}

void ClearStack(STACK *pstack)
{
    free(pstack->pint);
    puts("Clear stack successfully!");
}

static char GetChoice(void)
{
    char ch;
    puts("Enter the choice:");
    puts("a)push stack        b)pop stack");
    puts("c)show stack        q)quit");

    while ((ch = getchar()) != '\n')
    {
        EATLINE;
        if (strchr("abcq", ch) == NULL)
        {
            printf("%c is not in a,b,c,q. try again:");
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