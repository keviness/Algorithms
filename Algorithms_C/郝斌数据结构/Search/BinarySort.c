/*** Binary Sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10
int BinarySearch(int *arr, int value, int length);
//int BinarySort(int *arr, int value, int low, int high);

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
    while(getchar() != '\n') 
        continue;
    printf("The value: %d is in %d index \n", value, BinarySearch(arr, value, SIZE));

    return 0;
}

int BinarySearch(int *a, int value, int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    int result;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==value)
            result = mid;
        if(a[mid]>value)
            high = mid-1;
        if(a[mid]<value)
            low = mid+1;
    }
    if (low > high)
        result = -1;
    return result;
}

/*** 非递归版本 ***/

/*** 递归实现 ***/
/*
int BinarySort(int *arr, int value, int low, int high)
{
    if (low > high)
        return -1;
    int middle = (low+high)/2;
    if (arr[middle] == value)
        return middle;
    if (arr[middle] > value)
        return BinarySort(arr, value, low, high-1);
    if (arr[middle] < value)
        return BinarySort(arr, value, middle+1, high);
}
*/