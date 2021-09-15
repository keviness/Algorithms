/*** binary insertion sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10

void BInsertSort(int *arr);
void ShowArray(int *arr);

int main(void)
{
    int arr[SIZE] = {-8, 1, 3, 5, 2, -2, 7, 6, -10, -5};

    puts("The array:");
    ShowArray(arr);
    BInsertSort(arr);
    puts("The array after calling binary sort:");
    ShowArray(arr);

    return 0;
}

void BInsertSort(int *arr)
{
    int i, j, m, value, low, high;
    for (i=1; i<SIZE; i++)
    {
        low = 0;
        high = i-1;
        if (arr[i] < arr[i-1])
        {
            value = arr[i];
            while (low <= high)
            {
                m = (low+high)/2;
                if (arr[m]>value) 
                    high = m-1;
                else 
                    low = m+1;
            }
            for (j=i-1; j>=high+1; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = value; //arr[high+1] = value;
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