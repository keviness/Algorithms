/** Binnary Sort
* @author keviness
* @version 2020/12/6
*/

import java.util.*;

public class BinarySort
{
    public static void main(String[] args)
    {
        double[] array = {-1.23, 2.3, 3.4, -5.6, 2, 6, 7.8};
        System.out.println("The source array:");
        show(array);
        System.out.println("The sorted array:");
        sort(array);
        show(array);
    }

    public static void sort(double[] array)
    {
        int i, j;
        for (i=1; i<array.length; i++)
        {
            if (array[i] < array[i-1])
            {
                double value = array[i];
                int low = 0;
                int high = i-1;
                int mid;
                while (low <= high)
                {
                    mid = (low+high)/2;
                    if (array[mid] > value)
                    {
                        high = mid-1;
                    }
                    else
                    {
                        low = mid+1;
                    }
                }
                for (j=i-1; j>=high+1; j--)
                {
                    array[j+1] = array[j];
                }
                array[j+1] = value;
            }
        }
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
