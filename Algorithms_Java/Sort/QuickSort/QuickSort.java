/**Quick Sort
* @author keviness
* @version 2020/12/10
*/

import java.util.*;

public class QuickSort
{
    public static void main(String[] args)
    {
        double[] array = {-12, 3.4, 5.7, 9, 23, -0.3, 1.4};
        System.out.println("The source array:");
        show(array);
        System.out.println("The sorted array:");
        sort(array, 0, array.length-1);
        show(array);
    }

    public static void sort(double[] array, int low, int high)
    {
        int pos;
        if (low < high)
        {
            pos = findPos(array, low, high);
            sort(array, pos+1, high);    //the order can be changed!
            sort(array, low, pos-1);
        }
    }

    public static int findPos(double[] array, int low, int high)
    {
        double value = array[low];

        while (low < high)     //the order can't be changed!
        {
            while (low<high && value<=array[high])
            {
                high--;
            }
            array[low] = array[high];

            while (low<high && value>=array[low])
            {
                low++;
            }
            array[high] = array[low];
        }
        array[low] = value;

        return low;
    }

    public static void show(double[] array)
    {
        for (int i=0; i<array.length; i++)
        {
            System.out.printf("%4.2g ", array[i]);
        }
        System.out.printf("\n");
    }
}