/*** straight insertion sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10

void StraightInsertionSort(int *arr);
void ShowArray(int *arr);

int main(void)
{
    int array[SIZE] = {0, 1, -23, 4, 5, 7, -18, -112, 29, 34};
    puts("The array:");
    ShowArray(array);
    StraightInsertionSort(array);
    puts("The array after calling sort function:");
    ShowArray(array);

    return 0;
}

void StraightInsertionSort(int *arr)
{
    int i, j;
    /*
    for (i=2; i<SIZE; i++)
    {
        if (arr[i] < arr[i-1])
        {
            arr[0] = arr[i];  //设置数组首元素为哨兵
            for (j=i-1; arr[j]>arr[0]; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = arr[0];
        }
    }
    */
   for (i=1; i<SIZE; i++) //首元素从第二个开始
    {
        if (arr[i] < arr[i-1])
        {
            int value = arr[i];  //没有设置数组首元素为哨兵
            for (j=i-1; j>=0 && arr[j]>value; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = value;
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