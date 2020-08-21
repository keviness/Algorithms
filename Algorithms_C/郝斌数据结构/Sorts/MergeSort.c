/*** Merge Sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10

void Merge(int *arr, int left, int middle, int right);
void MergeSort(int *arr, int left, int right);
void ShowArray(int *arr);

int main(void)
{
    int arr[SIZE] = {1, -2, 3, -78, 9, 12, -3, 14, 34, 15};
    puts("The array:");
    ShowArray(arr);
    puts("The array after calling merge sort:");
    MergeSort(arr, 0, SIZE-1);
    ShowArray(arr);

    return 0;
}

void Merge(int *arr, int left, int middle, int right)
{
    int left_size = middle-left;
    int right_size = right-middle+1;
    //printf("left size:%d\n", left_size);
    //printf("right size:%d\n", right_size);
    int left_arr[left_size];
    int right_arr[right_size];
    int i, j, k;
    for (i=left; i<middle; i++)
    {
        left_arr[i-left] = arr[i];
    }
    for (j=middle; j<=right; j++)
    {
        right_arr[j-middle] = arr[j];
    }
    
    //对两个子数组元素进行合并
    i=0; j=0; k=left;
    while (i<left_size && j<right_size)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
    }
    //将剩余数据填入源数组中
    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void MergeSort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    else
    {
        int middle = (left+right)/2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle+1, right);
        Merge(arr, left, middle+1, right);
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