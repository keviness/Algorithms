/**Insert Search
* @author keviess
* @version 2020/12/14
*/

import java.util.*;

public class InsertSearch
{
    public static void main(String[] args)
    {
        int[] array = {2, 3, 4, 6, 9, 1, 12};
        int index = insertSearch(array, 6, array.length);
        System.out.printf("The element at %d in this array\n", index);
    }

    /*** 非递归版本 ***/
    public static int insertSearch(int[] arr, int value, int n)
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

    public static void show(int[] array)
    {
        for (int i=0; i<array.length; i++)
        {
            System.out.printf("%d ", array[i]);
        }
        System.out.printf("\n");
    }
    
    /*** 递归实现 ***/
    /*
    public static int InsertSort(int[] arr, int value, int low, int high)
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
}