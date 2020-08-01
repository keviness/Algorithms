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
bool TraverseList(Plist plst);
bool InsertItem(Plist plst);
int ListLength(Plist plst);
int DeleteItem(Plist plst);
void SortList(Plist plst);
void ShowList(Plist plst);
void ClearList(Plist plst);

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
        case 't': TraverseList(&lst);
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
    Plist p = phead->pnext;
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