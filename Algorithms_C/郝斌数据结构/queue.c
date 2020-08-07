/*** queue ***/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define EATLINE while(getchar() != '\n')continue
#define SIZE 10
typedef struct Queue
{
    int *pbase;
    int front;
    int rear;
}QUEUE, * PQUEUE;

void InitQueue(PQUEUE queue);
bool QueueIsEmpty(PQUEUE queue);
bool QueueIsFull(PQUEUE queue);
bool EnterQueue(PQUEUE queue);
bool OutQueue(PQUEUE queue);
void TraverseQueue(PQUEUE queue, void(*pfun)(int *data));
void QueueLength(PQUEUE queue);
void ShowQueue(PQUEUE queue);
void ClearQueue(PQUEUE queue);
static char GetChoice(void);
static void TwiceQueue(int *pint);

int main(void)
{
    char choice;
    QUEUE queue;
    InitQueue(&queue);
    while ((choice = GetChoice()) != 'q')
    {
        switch (choice)
        {
        case 'a': EnterQueue(&queue);
            break;
        case 'b': OutQueue(&queue);
            break;
        case 'c': ShowQueue(&queue);
            break;
        case 'd': QueueLength(&queue);
            break;
        case 'e': TraverseQueue(&queue, TwiceQueue);
            break;
        default: puts("The error choice input!");
            break;
        }
    }
    puts("The queue content:");
    ShowQueue(&queue);
    ClearQueue(&queue);
    
    puts("The done~");
    return 0;
}

void InitQueue(PQUEUE queue)
{
    queue->pbase = (int *)malloc(sizeof(int) * SIZE);
    if ((queue->pbase) == NULL)
    {
        puts("Error in locating the memory!");
        exit(EXIT_FAILURE);
    }
    queue->front = 0;
    queue->rear = 0;
}

bool QueueIsEmpty(PQUEUE queue)
{
    return ((queue->front) == (queue->rear))? true:false;
}

bool QueueIsFull(PQUEUE queue)
{
    return (((queue->rear)+1 % SIZE) == (queue->front)) ? true:false;
}

bool EnterQueue(PQUEUE queue)
{
    if (QueueIsFull(queue))
    {
        puts("The queue is full!");
        return false;
    }
    int data;
    char ch;
    puts("Enter the value you want to enter the queue:");
    while (scanf("%d", &data) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a valid input! try again:");
    }
    EATLINE;
    (queue->pbase)[queue->rear] = data;
    queue->rear = (queue->rear+1)%SIZE;

    return true;
}

bool OutQueue(PQUEUE queue)
{
    if (QueueIsEmpty(queue))
    {
        puts("The queue is empty!");
        return false;
    }
    int data;
    data = (queue->pbase)[queue->front];
    queue->front = (queue->front+1)%SIZE;
    printf("The out queue data:%d \n", data);

    return true;
}

void TraverseQueue(PQUEUE queue, void(*pfunc)(int *data))
{
    if (QueueIsEmpty(queue))
    {
        puts("The queue is empty!");
        return;
    }
    int i = queue->front;
    while (i != queue->rear)
    {
        (*pfunc)(&(queue->pbase[i]));
        i = (i+1)%SIZE;
    }
}

void ShowQueue(PQUEUE queue)
{
    if (QueueIsEmpty(queue))
    {
        puts("The queue is empty!");
        return;
    }
    int i = queue->front;
    while (i != queue->rear)
    {
        printf("%d ", (queue->pbase)[i]);
        i = (i+1)%SIZE;
    }
    putchar('\n');
}

void QueueLength(PQUEUE queue)
{
    int i = queue->front;
    int count = 0;
    while (i != queue->rear)
    {
        count++;
        i = (i+1)%SIZE;
    }
    printf("The queue length:%d \n", count);
}

void ClearQueue(PQUEUE queue)
{
    if (QueueIsEmpty(queue))
    {
        puts("The queue is empty!");
        return;
    }
    free(queue->pbase);
    puts("Clear queue successfully!");
}

static void TwiceQueue(int *data)
{
    *data = (*data) * 2;
}

static char GetChoice(void)
{
    char ch;
    puts("Enter the choice bellow:");
    puts("a)Enter queue        b)Out queue");
    puts("c)Show queue         d)Queue Length");
    puts("e)Traverse queue     q)Quit");

    while ((ch = getchar()) != '\n')
    {
        EATLINE;
        if (strchr("abcdeq", ch) == NULL)
        {
            puts("The error choice, try again:");
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