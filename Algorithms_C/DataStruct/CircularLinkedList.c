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
    int length;
}List, * Plist;

bool InitCircularList(Plist list);
bool ListIsEmpty(Plist list);
bool InsertList(Plist list);
bool DeleteList(Plist list);
bool AppendList(Plist list);
void ShowList(Plist list);
void ClearList(Plist list);
static char GetChoice(void);
static void GetIntNumber(int *data);

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
    list->length == 0;
    list->rear->pnext = list->rear;
}

bool ListIsEmpty(Plist list)
{
    return (list->length == 0)? true:false;
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
    list->length = 0;

    return false;
}

bool InsertList(Plist list)
{
    Pnode head = list->rear->pnext;
    int i=0, pos;

    GetIntNumber(&pos);
    Pnode p = head->pnext;

    while (i<pos-1 && p!=head)
    {
        p = p->pnext;
        i++;
    }
    if (i>pos-1 || p==head)
    {
        puts("The pos input error!");
        return false;
    }

    Pnode newNode = (Pnode)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        puts("Can\'t locate the memory!");
        return false;
    }
    int data;
    GetIntNumber(&data);
    
    newNode->data = data;
    newNode->pnext = p->pnext;
    p->pnext = newNode;
    list->length++;

    return false;
}

bool DeleteList(Plist list)
{
    int pos, i=0;
    Pnode head = list->rear->pnext;
    GetIntNumber(&pos);
    Pnode p = head->pnext;
    while (i<pos-1 && p!=head)
    {
        p = p->pnext;
        i++;
    }
    if (i>pos-1 || p==head)
    {
        puts("The error pos!");
        return false;
    }
    int data;
    Pnode temp = p->pnext;
    data = temp->data;
    p->pnext = temp->pnext;
    free(temp);
    printf("Delete the %d successfully!", data);
    list->length--;

    return true;
}

void ShowList(Plist list)
{
    Pnode head = list->rear->pnext;
    Pnode p = head->pnext;
    while (p != head)
    {
        printf("%d ", p->data);
        p = p->pnext;
    }
    putchar('\n');
}

static void GetIntNumber(int *data)
{
    int ch;
    puts("Enter the data you want to append:");
    while (scanf("%d", data) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a number! try again:");
    }
    EATLINE;
}

static char getChoice(void)
{
    char ch;
    puts("Enter the choice:");
    puts("a)Append Item       g)Get Item");
    puts("i)Insert Item       d)Delete Item");
    puts("s)Show item         e)Sort Item");
    puts("q)quit");
    while ((ch = getchar()) != '\n')
    {
        while (getchar() != '\n')
            continue;
        if (strchr("agidesq", ch) == NULL)
        {
            puts("The error choice you input, try again:");
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