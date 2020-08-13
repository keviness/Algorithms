/*** quick sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10
void quicksort(int *arr, int low, int high);
int findpos(int *arr, int low, int high);
void showarr(const int *arr);

int main(void)
{
    int arr[SIZE] = {-2, 1, 2, 3, 6, -7, 10, -9, -20, 20};
    showarr(arr);
    quicksort(arr, 0, 9);
    puts("\nThe arr content:");
    showarr(arr);

    return 0;
}

void quicksort(int *arr, int low, int high)
{
    int pos;
    if (low < high)
    {
        pos = findpos(arr, low, high);
        quicksort(arr, low, pos-1);
        quicksort(arr, pos+1, high);
    }
}

int findpos(int *arr, int low, int high)
{
    int value = arr[low];
    while (low < high)
    {
        while (low<high && arr[high]>=value)
        {
            high--;
        }
        arr[low] = arr[high];
        while (low<high && arr[low]<=value)
        {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = value;

    return low;
}

void showarr(const int *arr)
{
    for (int i=0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}