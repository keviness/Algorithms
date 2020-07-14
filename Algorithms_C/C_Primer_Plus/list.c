#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TITLE 20
typedef struct book {
    char title[TITLE];
    double value;
    struct book * next; //此时book结构指针只可用原名不可用别名
                        //（node别名尚未定义）
}node;
char *s_gets(char *str, int num);

int main(void)
{
    node *head = NULL;
    node *previous, *current;
    char input[TITLE];
    puts("Enter the book title:");
    while (s_gets(input, TITLE) && input[0]!='\0')
    {
        current = (node *)malloc(sizeof(node));
        if (head == NULL)
        {
            head = current;
        }
        else
        {
            previous->next = current;
        }
        strcpy(current->title, input);
        puts("Enter the book value:");
        scanf("%lf", &current->value);
        while (getchar() != '\n')
        {
            continue;
        }
        current->next = NULL;
        puts("Enter the next book title:");
        previous = current;
    }
    if (head == NULL)
        puts("The list is empty!");
    else
        puts("The list content:");

    current = head;
    while (current != NULL)
    {
        printf("The title:%s \n", current->title);
        printf("The book value:%lf \n", current->value);
        current = current->next;
    }
    
    //释放内存:当前节点释放之后，下一个地址的指针液会被释放。需要head进行储存。
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    }
    puts("The done~");

    return 0;
}
char * s_gets(char *str, int num)
{
    char *ptr;
    ptr = fgets(str, num, stdin);
    if (ptr)
    {
        while (*str!='\0' && *str!='\n')
        {
            str++;
        }
        if (*str == '\n')
        {
            *str = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ptr;
}