/*** simple select sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10

void SimpleSelectSort(int *arr);
void ShowArray(int *arr);

int main(void)
{
    int arr[SIZE] = {23, 12, 34, -23, 5, 6, 8, 1, -4, -6};
    puts("The array:");
    ShowArray(arr);
    puts("The array after calling simple sort:");
    SimpleSelectSort(arr);
    ShowArray(arr);

    return 0;
}

void SimpleSelectSort(int *arr)
{
    int i, j, min, temp;
    for (i=0; i<SIZE-1; i++)
    {
        min = i;
        for (j=i+1; j<SIZE; j++)
        {
            if (arr[min]>arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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