/*** Array ***/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 10
#define EATLINE while(getchar()!='\n')continue
typedef struct array
{
    int count;
    int length;
    int *pint;
}Array;

void InitializeArray(Array *parr);
int GetItem(const Array *parr);
bool ArrayIsFull(const Array *parr);
bool ArrayIsEmpty(const Array *parr);
bool AppendItem(Array *parr);
bool InsertItem(Array *parr);
int DeleteItem(Array *parr);
void ClearArray(Array *parr);
void ShowItem(const Array *parr);

static char getChoice(void);

int main(void)
{
    char choice;
    Array arr;
    InitializeArray(&arr);
    while ((choice = getChoice()) != 'q')
    {
        switch (choice)
        {
        case 'a': AppendItem(&arr);
            break;
        case 'g': printf("Get the element:%d\n", GetItem(&arr));
            break;
        case 'i': InsertItem(&arr);
            break;
        case 'd': printf("Delete %d \n", DeleteItem(&arr));
            break;
        case 's': ShowItem(&arr);
            break;
        default: puts("The choice input error!");
        }
    }
    puts("The array elements:");
    ShowItem(&arr);
    ClearArray(&arr);
    puts("The Done~");
    
    return 0;
}

void InitializeArray(Array *parr)
{
    parr->count = 0;
    parr->length = MAXSIZE;
    parr->pint = (int *)malloc(sizeof(int)*(parr->length));
    if ((parr->pint) == NULL)
    {
        puts("Can\'t locate the memory!");
        exit(EXIT_FAILURE);
    }
}

bool ArrayIsFull(const Array *parr)
{
    return (parr->count)==(parr->length)? true:false;
}

bool ArrayIsEmpty(const Array *parr)
{
    return (parr->count) == 0? true:false;
}

int GetItem(const Array *parr)
{
    int pos;
    int result;
    if (ArrayIsEmpty(parr))
    {
        puts("The Array is empty!");
        exit(EXIT_FAILURE);
    }
    puts("Enter the index of element you want to get:");
    scanf("%d", &pos);
    EATLINE;
    result = (parr->pint)[pos];

    return result;
}

bool AppendItem(Array *parr)
{
    int item;
    if (ArrayIsFull(parr))
    {
        puts("The array is full!");
        return false;
    }
    puts("Enter the item you want to append:");
    scanf("%d", &item);
    EATLINE;
    (parr->pint)[parr->count] = item;
    (parr->count)++;
    return true;
}

bool InsertItem(Array *parr)
{
    int pos;
    int item;
    if (ArrayIsFull(parr))
    {
        puts("The array is full!");
        return false;
    }
    puts("Enter the index you want to insert:");
    scanf("%d", &pos);
    EATLINE;
    if (pos<1 || pos>(parr->count)+1)
    {
        puts("Error pos!");
        return false;
    }
    puts("Enter the item you want to insert:");
    scanf("%d", &item);
    EATLINE;

    for (int i=(parr->count-1); i>=(pos-1); i--)
    {
        (parr->pint)[i+1] = (parr->pint)[i];
    }
    (parr->pint)[pos-1] = item;
    (parr->count)++;

    return true;
}

int DeleteItem(Array *parr)
{
    int pos;
    int item;
    if (ArrayIsEmpty(parr))
    {
        puts("The array is empty!");
        return false;
    }
    puts("Enter the index of the item you want to delete:");
    scanf("%d", &pos);
    EATLINE;
    if (pos<1 || pos>(parr->count))
    {
        puts("The index out of range!");
        return false;
    }
    item = (parr->pint)[pos-1];
    for (int i=pos; i<(parr->count); i++)
    {
        (parr->pint)[i-1] = (parr->pint)[i];
    }
    parr->count--;
    return item;
}

void ClearArray(Array *parr)
{
    free(parr->pint);
}

void ShowItem(const Array *parr)
{
    if (ArrayIsEmpty(parr))
    {
        puts("The Array is empty!");
    }
    else
    {
        for (int i=0; i<(parr->count); i++)
        {
            printf("%d ", (parr->pint)[i]);
        }
        putchar('\n');
    }
}

static char getChoice(void)
{
    char ch;
    puts("Enter the choice:");
    puts("a)Append Item       g)Get Item");
    puts("i)Insert Item       d)Delete Item");
    puts("s)Show item         q)quit");
    while ((ch = getchar()) != '\n')
    {
        while (getchar() != '\n')
            continue;
        if (strchr("agidsq", ch) == NULL)
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
