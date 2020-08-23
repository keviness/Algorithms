/*** Binary Sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10
int BinarySort(int *arr, int value, int length);

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
    printf("The value in %d index \n", BinarySort(arr, value, SIZE));

    return 0;
}

int BinarySort(int *arr, int value, int length)
{
    int middle, low, high;
    low = 0; 
    high = length-1;
    while (low <= high)
    {
        middle = (low+high)/2;
        if (arr[middle] < value)
        {
            low = middle+1;
        }
        if (arr[middle] > value)
        {
            high = middle-1;
        }
        if (arr[middle] == value)
            return middle;
    }
    return -1;
}