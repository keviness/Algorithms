### 归并排序
>Merge Sort
##### 基本思想
>* 是将两个（或两个以上）有序表合并成一个新的有序表，即把待排序序列分为若干个子序列，每个子序列是有序的。然后再把有序子序列合并为整体有序序列。
##### 代码实现
~~~c
void Merge(int *arr, int left, int middle, int right)
{
    int left_size = middle-left;
    int right_size = right-middle+1;
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
~~~