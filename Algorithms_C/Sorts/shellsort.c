/*** shell's sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10

void shellSort(int *arr, int incresement);
void showArray(int *arr);

int main(void)
{
    int array[SIZE] = {-1, 2, 3, -5, 12, -9, 4, -90, 23, 11};
    int incresement[3] = {5, 3, 1};
    puts("The array:");
    showArray(array);
    puts("The array after calling shell sort:");
    for (int i=0; i<3; i++)
    {
        shellSort(array, incresement[i]);
    }
    showArray(array);

    return 0;
}

void shellSort(int *arr, int incresement)
{
    int i, j;
    /*
    for (i=incresement+1; i<SIZE; i++)
    {
        if (arr[i] < arr[i-incresement])
        {
            arr[0] = arr[i];
            for (j=i-incresement; j>0&&arr[j]>arr[0]; j=j-incresement)
            {
                arr[j+incresement] = arr[j];
            }
            arr[j+incresement] = arr[0];
        }
    }
    */
    for (i=incresement; i<SIZE; i++)
    {
        if (arr[i] < arr[i-incresement])
        {
            int value = arr[i];
            for (j=i-incresement; j>=0&&arr[j]>value; j=j-incresement)
            {
                arr[j+incresement] = arr[j];
            }
            arr[j+incresement] = value;
        }
    }
}

void showArray(int *arr)
{
    for (int i=0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}