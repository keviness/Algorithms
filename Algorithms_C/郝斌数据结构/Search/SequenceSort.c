/*** sequence sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10
int SequenceSort(int *arr, int value);

int main(void)
{
    int arr[SIZE] = {1, -2, -23, 23, 12, 10, -34, 25, 12};
    int value;
    char ch;
    puts("Enter the value you want to search:");
    while (scanf("%d", &value) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a number! try again:");
    }
    while(getchar() != '\n') continue;
    printf("The value in %d index \n", SequenceSort(arr, value));

    return 0;
}

int SequenceSort(int *arr, int value)
{
    for (int i=0; i<SIZE; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}