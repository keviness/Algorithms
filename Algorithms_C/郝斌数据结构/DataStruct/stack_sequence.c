/*** stack sequeuce ***/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 10

typedef struct stack
{
    int *pint;
    int top;
}STACK;

void InitializeStack(STACK *pstack);
bool StackIsEmpty(STACK *pstack);
bool StackIsFull(STACK *pstack);
bool PushStack(STACK *pstack);
bool OutStack(STACK *pstack);
void ClearStack(STACK *pstack);
void ShowStack(STACK *pstack);

