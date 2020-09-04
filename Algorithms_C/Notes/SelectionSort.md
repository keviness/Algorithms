### 选择排序
>Selection Sort
#### （一）简单选择排序
>Simple Selection Sort
##### 基本思想
>* 在要排序的一组数中，选出最小（或者最大）的一个数与第1个位置的数交换；然后在剩下的数当中再找最小（或者最大）的与第2个位置的数交换，依次类推，直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止。
##### 代码实现
~~~c
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
~~~
#### （二）堆排序
>Heap Sort
##### 基本思想
>* 堆的定义如下：具有n个元素的序列（k1,k2,...,kn),当且仅当满足ai>=a2i+1,ai>=a2i或者ai<=a2i+1,ai<=a2i时称之为堆。
>* 可以将堆看做是一个完全二叉树。并且，每个结点的值都大于等于其左右孩子结点的值，称为大顶堆；或者每个结点的值都小于等于其左右孩子结点的值，称为小顶堆。
>* 将待排序列表构造成一个最大堆，作为初始无序堆（即初始无序列表）
>* 将堆顶元素（最大值）与堆尾元素互换
>* 将该堆（无序区）尺寸缩小1，并对缩小后的堆重新调整为最大堆形式
>* 重复上述步骤，直至堆（无序区）的尺寸变为1，此时排序完成
##### 代码实现
~~~c
void heapify(int *tree, int n, int i)
{
    if (i >= n)
    {
        return;
    }
    int c1 = i*2 + 1;
    int c2 = i*2 + 2;
    int max = i;
    if (c1<n && tree[c1]>tree[max])
        max = c1;
    if (c2<n && tree[c2]>tree[max])
        max = c2;
    if (max != i)
    {
        swap(tree, i, max);
        heapify(tree, n, max);
    }
}

void buildHeap(int *tree, int n)
{
    int last_node = n-1;
    int last_node_parent = (last_node-1)/2; 
    for (int i=last_node_parent; i>=0; i--)
    {
        heapify(tree, n, i);
    }
}

void heapSort(int *tree, int n)
{
    buildHeap(tree, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(tree, i, 0);
        heapify(tree, i, 0);
    }
}

void swap(int *tree, int i, int j)
{
    int temp = tree[i];
    tree[i] = tree[j];
    tree[j] = temp;
}
~~~