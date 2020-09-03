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
    Pnode front;
    Pnode rear;
}List, * Plist;

bool InitCircularList(Plist list);
bool ListIsEmpty(Plist list);
bool InsertList(Plist list);
bool DeleteList(Plist list);
bool AppendList(Plist list);
void ShowList(Plist list);
void ClearList(Plist list);
static char GetChoice(void);

int main(void)
{
    char choice;
    List list;
    InitCircularList(&list);
    while ((choice = GetChoice()) != 'q')
    {
        switch (choice)
        {
            case 'a': InsertList(&list);
                break;
            case 'b': DeleteList(&list);
                break;
            case 'c': AppendList(&list);
                break;
            case 'd': ShowList(&list);
                break;
            default: puts("The program is error!");
        }
    }
    puts("The list content:");
    ShowList(&list);
    ClearList(&list);

    return 0;
}

bool InitCircularList(Plist list)
{
    list->rear = (Pnode)malloc(sizeof(Node));
    if (list->rear == NULL)
    {
        puts("Can\'t locate memory!");
        return false;
    }
    list->front = list->rear;
    list->rear->pnext = list->rear;
}

bool ListIsEmpty(Plist list)
{
    return (list->rear->pnext == list->front)? true:false;
}

bool AppendList(Plist list)
{
    
    Pnode newNode = (Pnode)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        puts("Can\'t locate the memory!");
        return false;
    }
    int data, ch;
    puts("Enter the data you want to append:");
    while (scanf("%d", &data) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a number! try again:");
    }
    
    newNode->data = data;
    newNode->pnext = list->rear->pnext;
    list->rear->pnext = newNode;
    list->rear = newNode;

    return false;
}

bool InsertList(Plist list)
{
    Pnode newNode = (Pnode)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        puts("Can\'t locate the memory!");
        return false;
    }
    int data, ch;
    puts("Enter the data you want to append:");
    while (scanf("%d", &data) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a number! try again:");
    }
    
    newNode->data = data;
    newNode->pnext = list->rear->pnext;
    list->rear->pnext = newNode;
    list->rear = newNode;

    return false;
}
