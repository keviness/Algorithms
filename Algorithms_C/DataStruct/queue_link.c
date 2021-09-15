/*** queue link ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define EATLINE while(getchar()!='\n')continue
typedef struct node
{
    int data;
    struct node *pnext;
}Node, * Pnode;

typedef struct queue
{
    Pnode front;
    Pnode rear;
}Queue, * Pqueue;

void InitQueue(Pqueue queue);
bool QueueIsEmpty(Pqueue queue);
bool EnQueue(Pqueue queue);
bool DeQueue(Pqueue queue);
int QueueLength(Pqueue queue);
void ShowQueue(Pqueue queue);
void ClearQueue(Pqueue queue);
static char GetChoice(void);

int main(void)
{
    char choice;
    Queue queue;
    InitQueue(&queue);

    while ((choice = GetChoice()) != 'q')
    {
        switch (choice)
        {
            case 'a': EnQueue(&queue);
                break;
            case 'b': DeQueue(&queue);
                break;
            case 'c': ShowQueue(&queue);
                break;
            case 'd': QueueLength(&queue);
                break;
            default: puts("The program is in error!");
        }
    }
    puts("The Queue content:");
    ShowQueue(&queue);
    ClearQueue(&queue);

    return 0;
}

void InitQueue(Pqueue queue)
{
    queue->front = (Pnode)malloc(sizeof(Node));
    if (queue->front == NULL)
    {
        puts("Can\'t locate the memory!");
        exit(EXIT_FAILURE);
    }
    queue->rear = queue->front;
}

bool QueueIsEmpty(Pqueue queue)
{
    return (queue->front == queue->rear)? true:false;
}

bool EnQueue(Pqueue queue)
{
    int data, ch;
    puts("Enter the data you want to enqueue:");
    while (scanf("%d", &data) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a number! try again:");
    }
    EATLINE;
    Pnode newNode = (Pnode)malloc(sizeof(Node));
    newNode->data = data;
    newNode->pnext = NULL; 
    queue->rear->pnext = newNode;
    queue->rear = newNode;
    printf("Enter the %d successfully! \n", data);

    return true;
}

bool DeQueue(Pqueue queue)
{
    if (QueueIsEmpty(queue))
    {
        puts("The queue is empty!");
        return false;
    }
    int data;
    Pnode temp = queue->front->pnext;
    data = temp->data;
    queue->front->pnext = temp->pnext;
    
    if (temp == queue->rear)
    {
        queue->rear = queue->front;
    }
    free(temp);
    printf("Delete %d from the queue successfully!\n", data);

    return true;
}

void ShowQueue(Pqueue queue)
{
    if (QueueIsEmpty(queue))
    {
        puts("The queue is empty!");
        return;
    }
    Pnode start = queue->front->pnext;
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->pnext;
    }
    putchar('\n');
}

int QueueLength(Pqueue queue)
{
    int count = 0;
    if (QueueIsEmpty(queue))
    {
        puts("The queue is empty!");
        count = 0;
    }
    Pnode start = queue->front->pnext;
    
    while (start != NULL)
    {
        count++;
        start = start->pnext;
    }
    printf("The queue length:%d \n", count);
}

void ClearQueue(Pqueue queue)
{
    if (QueueIsEmpty(queue))
    {
        puts("The queue is empty!");
        return;
    }
    Pnode temp = queue->front;
    while (temp != NULL)
    {
        queue->front = queue->front->pnext;
        free(temp);
        temp = queue->front;
    }
    puts("clear the queue successfully!");
}

static char GetChoice(void)
{
    char ch;
    puts("Enter the choice:");
    puts("a)Enqueue        b)Dequeue");
    puts("c)show queue     d)Queue Length");     
    puts("q)quit");

    while ((ch = getchar()) != '\n')
    {
        EATLINE;
        if (strchr("abcdq", ch) == NULL)
        {
            printf("%c is not in a,b,c,q. try again:");
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