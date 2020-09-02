/*** heap-sort ***/
#include <stdio.h>
#include <string.h>
#define SIZE 10

void heapSort(int *tree, int n);
void heapify(int *tree, int n, int j);
void swap(int *tree, int i, int j);
void buildHeap(int *tree, int n);
void showHeap(int *tree);

int main(void)
{
    int tree[SIZE] = {1, -2, 3, -4, -12, 23, 8, 34, 9, -56};
    puts("The tree:");
    showHeap(tree);
    puts("The tree after calling heap sort:");
    heapSort(tree, SIZE);
    showHeap(tree);

    return 0;
}

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

void showHeap(int *tree)
{
    for (int i=0; i<SIZE; i++)
    {
        printf("%d ", tree[i]);
    }
    putchar('\n');
}