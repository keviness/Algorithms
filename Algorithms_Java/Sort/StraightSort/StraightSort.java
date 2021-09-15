/**Straight Sort
* @author keviness
* @version 2020/12/8
*/

import java.util.*;

public class StraightSort
{
    public static void main(String[] args)
    {
        double[] array = {12, 3, 4.5, 5.6, 3.6, -6.7, 9};
        System.out.printf("The source array: \n");
        show(array);
        System.out.printf("The sorted array: \n");
        //sort(array);
        sort1(array);
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
                for (j=i-1; j>=0&&array[j]>value; j--)
                {
                    array[j+1] = array[j];
                }
                array[j+1] = value;
            }
        }
    }

    public static void sort1(double[] array)
    {
        int i, j;
        for (i=2; i<array.length; i++)
        {
            if (array[i] < array[i-1])
            {
                array[0] = array[i];  //a[0] is a sentinel
                for (j=i-1; array[j]>array[0]; j--)
                {
                    array[j+1] = array[j];
                }
                array[j+1] = array[0];
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