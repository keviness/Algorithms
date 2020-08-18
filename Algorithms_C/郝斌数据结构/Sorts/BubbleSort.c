/*** bubble sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10

void BubbleSort(int *arr);
void ShowArray(int *arr);

int main(void)
{
    int arr[SIZE] = {1, 2, -12, -4, 3, 5, 11, 23, 12, -6};
    puts("The arrary:");
    ShowArray(arr);
    puts("The array after calling bubble sort:");
    BubbleSort(arr);
    ShowArray(arr);

    return 0;
}

void BubbleSort(int *arr)
{
    int i, j, temp, flag;
    for (i=0; i<SIZE-1; i++)
    {
        flag = 0;
        for (j=0; j<SIZE-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void ShowArray(int *arr)
{
    for (int i=0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}