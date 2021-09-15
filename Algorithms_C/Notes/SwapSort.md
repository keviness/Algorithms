### 交换排序
>Swap Sort
#### （一）冒泡排序
>Bubble Sort
##### 基本思想
>* 重复的遍历（走过）待排序的一组数字（通常是列表形式），依次比较两个相邻的元素（数字），若它们的顺序错误则将它们调换一下位置，直至没有元素再需要交换为止。
>* 每遍历一次列表，最大（或最小）的元素会经过交换一点点”浮“到列表的一端（顶端），所以形象的称这个算法为冒泡算法。
##### 代码实现
~~~c
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
~~~
#### （二）快速排序
>Quick Sort
##### 基本思想
>* 通过一趟排序将待排序列表分割成独立的两部分，其中一部分的所有元素都比另一部分小，然后再按此方法将独立的两部分分别继续重复进行此操作，这个过程我们可以通过递归实现，从而达到最终将整个列表排序的目的。
##### 代码实现
~~~c
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
~~~
