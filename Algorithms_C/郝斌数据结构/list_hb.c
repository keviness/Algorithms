/*** 郝斌数据结构：链表 ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define EATLINE while(getchar() != '\n')continue
typedef struct node
{
    int data;
    struct node *pnext;
}List, *Plist;

Plist CrateList(void);
bool ListIsEmpty(Plist plst);
bool AppendItem(Plist plst);
bool TraverseList(Plist plst, void(*pfun)(Plist plst));
bool InsertItem(Plist plst);
int ListLength(Plist plst);
int DeleteItem(Plist plst);
void SortList(Plist plst);
void ShowList(Plist plst);
void ClearList(Plist plst);

static void PrintItem(Plist plst);
static char GetChoice(void);

int main(void)
{
    char choice;
    Plist lst = CrateList();
    while ((choice = getChoice()) != 'q')
    {
        switch (choice)
        {
        case 'a': AppendItem(&lst);
            break;
        case 't': TraverseList(&lst, PrintItem);
            break;
        case 'i': InsertItem(&lst);
            break;
        case 'd': DeleteItem(&lst);
            break;
        case 's': SortList(&lst);
            break;
        case 'e': ShowList(&lst);
            break;
        case 'l': printf("The list length:%d \n", ListLength(&lst));
            break;
        default: puts("The error choice!");
            break;
        }
    }
    puts("The list content:");
    ShowList(&lst);
    ClearList(&lst);

    return 0;
}

Plist CrateList(void)
{
    int count, item;
    Plist phead, pnew, pprevious;
    puts("How many items do you want:");
    scanf("%d", &count);
    EATLINE;
    phead = (Plist)malloc(sizeof(List));
    pprevious = phead;
    pprevious->pnext = NULL;
    for (int i=0; i<count; i++)
    {
        pnew = (Plist)malloc(sizeof(List));
        if (pnew == NULL)
        {
            puts("Locate mmemory error!");
            exit(EXIT_FAILURE);
        }
        printf("Enter the %d data:", i);
        scanf("%d", &item);
        EATLINE;
        pnew->pnext = NULL;
        pprevious->pnext = pnew;
        pprevious = pnew;
    }
    return phead;
}

bool ListIsEmpty(Plist phead)
{
    return (phead->pnext==NULL) ? true:false;
}

bool AppendItem(Plist phead)
{
    Plist pnew;
    Plist p = phead;
    while (p->pnext != NULL)
    {
        p = p->pnext;
    }
    pnew = (Plist)malloc(sizeof(List));
    if (pnew == NULL)
    {
        puts("Locate memory error!");
        return false;
    }
    pnew->pnext = NULL;
    p->pnext = pnew;

    return true;
}

int ListLength(Plist phead)
{
    int count = 0;
    Plist p = phead->pnext;
    while (p != NULL)
    {
        p = p->pnext;
        count++;
    }
    return count;
}

bool TraverseList(Plist phead, void(*pfun)(Plist plst))
{
    Plist p = phead->pnext;
    if (ListIsEmpty(phead))
    {
        puts("The List is empty！");
        return false;
    }
    while (p != NULL)
    {
        (*pfun)(p);
        p = p->pnext;
    }
    return true;
}

bool InsertItem(Plist phead)
{
    int pos, data;
    int i = 0;
    Plist p = phead;
    Plist pnew;
    puts("Enter the index you want to insert:");
    scanf("%d", &pos);
    EATLINE;
    
    while (i<pos-1 && p!=NULL)
    {
        p = p->pnext;
        i++;
    }
    if (i>pos-1 && p==NULL)
    {
        puts("The pos input error!");
        return false;
    }
    pnew = (Plist)malloc(sizeof(List));
    if (pnew == NULL)
    {
        puts("Can\'t locate the memory!");
        return false;
    }
    puts("Enter the data you want to save:");
    scanf("%d", &data);
    EATLINE;
    pnew->data = data;
    
    pnew->pnext = p->pnext;
    p->pnext = pnew;

    return true;
}

int DeleteItem(Plist phead)
{
    int pos, data, i, value;
    Plist pnew, p, q;
    p = phead;
    puts("Enter the pos you want to delete:");
    scanf("%d", &pos);
    EATLINE;
    i = 0;
    while (i<pos-1 && p->pnext!=NULL)
    {
        p = p->pnext;
        i++;
    }
    if (i>pos-1 || p->pnext==NULL)
    {
        puts("The pos input error!");
        exit(EXIT_FAILURE);
    }
    q = p->pnext;
    value = q->data;
    p->pnext = q->pnext;
    free(q);
    q = NULL;

    return value;
}

void ClearList(Plist phead)
{
    Plist p = phead;
    while (p != NULL)
    {
        phead = p->pnext;
        free(p);
        p = phead;
    }
}

void ShowList(Plist phead)
{
    Plist p = phead->pnext;
    if (p = NULL)
    {
        puts("The list is empty!");
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->pnext;
    }
}

static char GetChoice(void)
{
    char ch;
    puts("Enter the choice:");
    puts("a)Append item       t)Traverse list");
    puts("i)Insert item       d)Delete item");
    puts("s)Sort item         e)Shoe list");
    puts("l)List length       q)Quit");
    while ((ch = getchar()) != '\n')
    {
        EATLINE;
        if (strchr("atidselq", ch) == NULL)
        {
            puts("The error choice you input!try again:");
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

static void PrintItem(Plist plst)
{
    printf("%d ", plst->data);
}