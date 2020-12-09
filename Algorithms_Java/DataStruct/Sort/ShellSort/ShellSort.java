/**Shell Sort
* @author keviness
* @version 2020/12/9
*/

import java.util.*;

public class ShellSort
{
    public static void main(String[] args)
    {
        double[] array = {-2.3, 12.3, 2.4, 6.4, -7.8, 1.45};
        System.out.println("The source array:");
        show(array);
        System.out.println("The sorted array:");
        int[] increasement = {5, 3, 1};
        for (int e : increasement)
        {
            sort(array, e);
        }
        show(array);
    }

    public static void sort(double[] array, int increasement)
    {
        int i, j;
        for (i=increasement; i<array.length; i++)
        {
            if (array[i-increasement] > array[i])
            {
                double value = array[i];
                for (j=i-increasement; j>=0 && value<array[j]; j=j-increasement)
                {
                    array[j+increasement] = array[j];
                }
                array[j+increasement] = value;
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