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
void TraverseStack(Pstack stack, void(*pfun)(int *data));
void ClearStack(Pstack stack);
void InitStack(Pstack stack);
void ShowStack(Pstack stack);
void GetStackLength(Pstack stack);
static char GetChoice(void);
static void TwiceItem(int *data);
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
            case 'c': TraverseStack(&stack, TwiceItem);
                break;
            case 'd': ShowStack(&stack);
                break;
            case 'e': GetStackLength(&stack);
                break;
            default: puts("The error choice!");
                break;
        }
    }
    puts("The stack content:");
    ShowStack(&stack);
    ClearStack(&stack);
    puts("The done~");

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
    if (stack->top == stack->buttom)
    {
        return true;
    }
    else
    {
        return false;
    }
    //return (stack->top)==(stack->buttom) ? true:false;
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
    EATLINE;
    pnew->data = value;
    pnew->pnext = stack->top;
    stack->top = pnew;
    printf("push %d into the stack successfully!\n", value);
    return true;
}

bool PopStack(Pstack stack)
{
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return false;
    }

    Pnode temp;
    int data;
    temp = stack->top;
    data = temp->data;
    stack->top = temp->pnext;
    free(temp);
    temp = NULL;
    printf("pop %d from stack successfully!\n", data);

    return true;
}

void ClearStack(Pstack stack)
{  
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return;
    }
    else
    {
        Pnode temp;
        while (stack->top != stack->buttom)
        {
            temp = stack->top->pnext;
            free(stack->top);
            stack->top = temp;
        }
        free(stack->top);
        stack->top = NULL;
        stack->buttom = NULL;
        puts("clear stack successfully!");
    }
}

void TraverseStack(Pstack stack, void(*pfun)(int *data))
{
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return;
    }
    Pnode previousTop = stack->top;
    while ((stack->top) != (stack->buttom))
    {
        (*pfun)(&(stack->top->data));
        stack->top = stack->top->pnext;
    }
    stack->top = previousTop;
}

void GetStackLength(Pstack stack)
{
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return;
    }
    int count = 0;
    Pnode previousTop = stack->top;
    while ((stack->top) != (stack->buttom))
    {
        count++;
        stack->top = stack->top->pnext;
    }
    printf("The stack length:%d \n", count);
    stack->top = previousTop;
}

void ShowStack(Pstack stack)
{
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return;
    }
    Pnode previousPoint =  stack->top; //保存初次栈头部指针的位置
    while ((stack->top) != (stack->buttom))
    {
        printf("%d ", stack->top->data);
        stack->top = stack->top->pnext;
    }
    putchar('\n');
    /** 使指针回到原来的位置 **/
    stack->top = previousPoint;
}

static void TwiceItem(int *data)
{
    *data = (*data)*2;
}

static char GetChoice(void)
{
    char ch;
    puts("\nEnter the choice:");
    puts("a)puch stack          b)pop stack");
    puts("c)traverse stack      d)show stack");
    puts("e)get stack length    q)quit");
    while ((ch = getchar()) != '\n')
    {
        EATLINE;
        if (strchr("abcdeq", ch) == NULL)
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

