/*** Insert Sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10
int InsertSearch(int *arr, int value, int length);
//int InsertSort(int *arr, int value, int low, int high);

int main(void)
{
    int arr[SIZE] = {-23, -3, 1, 2, 10, 13, 25, 28, 45}; //数组必须有序
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
    while (getchar() != '\n')continue;
    printf("The value: %d is in %d index \n", value, InsertSearch(arr, value, SIZE));

    return 0;
}

/*** 非递归版本 ***/
int InsertSearch(int *arr, int value, int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;

    while(low <= high)
    {
        //自适应获取应该取得的索引
        mid = low + ((value-arr[low])/(arr[high]-arr[low]))*(high-low);
        printf("low:%d\n", low);
        printf("high:%d\n", high);
        printf("middle:%d\n", mid);
        if(arr[mid] == value)
            return mid;
        if(arr[mid] > value)
            high = mid-1;
        if(arr[mid] < value)
            low = mid+1;
    }
    return -1;
}

/*** 递归实现 ***/
/*
int InsertSort(int *arr, int value, int low, int high)
{
    if (low > high)
        return -1;
    int middle = low + (value-arr[low])/(arr[high]-arr[low])*(high-low);
    if (arr[middle] == value)
        return middle;
    if (arr[middle] > value)
        return InsertSort(arr, value, low, high-1);
    if (arr[middle] < value)
        return InsertSort(arr, value, middle+1, high);
}
*/