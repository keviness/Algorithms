/** Heap Sort
* @author keviness
* @version 2020/12/12
*/

import java.util.*;

public class HeapSort
{
    public static void main(String[] args)
    {
        int[] array = {1, 2, 3, 45, -12, 46, -23};
        System.out.println("The source array:");
        show(array);
        System.out.println("The sorted array:");
        heapSort(array, array.length);
        show(array);
    }

    public static void heapSort(int[] tree, int n)
    {
        buildHeap(tree, n);
        for (int i=n-1; i>=0; i--)
        {
            swap(tree, i, 0);
            heapify(tree, i, 0);
        }
    }

    public static void heapify(int[] tree, int n, int i)
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

    public static void buildHeap(int[] tree, int n)
    {
        int last_node = n-1;
        int last_node_parent = (last_node-1)/2; 
        for (int i=last_node_parent; i>=0; i--)
        {
            heapify(tree, n, i);
        }
    }

    public static void swap(int[] tree, int i, int j)
    {
        int temp = tree[i];
        tree[i] = tree[j];
        tree[j] = temp;
    }

    public static void show(int[] tree)
    {
        for (int i=0; i<tree.length; i++)
        {
            System.out.printf("%d ", tree[i]);
        }
        System.out.printf("\n");
    }
}