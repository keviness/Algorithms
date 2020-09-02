/*** circular linked list ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define EATLINE while(getchar() !='\n')continue

typedef struct node
{
    int data;
    struct node *pnext;
}Node, * Pnode;

typedef struct CircularList
{
    Pnode rear;
}List, * Plist;

bool InitCircularList();
