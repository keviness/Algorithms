/*** queue ***/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define EATLINE while(getchar() != '\n')continue
#define SIZE 10
typedef struct queue
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
void TraverseQueue(PQUEUE queue);
void QueueLength(PQUEUE queue);
void ShowQueue(PQUEUE queue);
void ClarQueue(PQUEUE queue);
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
        case 'e': TraverseQueue(&queue);
            break;
        default: puts("The error choice input!");
            break;
        }
    }
    puts("The queue content:");
    ShowQueue(&queue);
    ClarQueue(&queue);
    
    puts("The done~");
    return 0;
}

void InitQueue(PQUEUE queue)
{
    queue->pbase = (PQUEUE)malloc(sizeof(QUEUE)*SIZE);
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
    return (queue->front == queue->rear)? true:false;
}

bool QueueIsFull(PQUEUE queue)
{
    return ((queue->rear+1)%SIZE == queue->front)? true:false;
}

bool EnterQueue(PQUEUE queue)
{
    if (QueueIsFull)
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
    if (QueueIsEmpty)
    {
        puts("The queue is empty!");
        return false;
    }
    int data;
    data = (queue->pbase)[queue->front];
    queue->front = (queue->front+1)%SIZE;

    return true;
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