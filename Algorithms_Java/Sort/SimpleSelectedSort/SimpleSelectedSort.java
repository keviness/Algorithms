/**Simple Selected Sort
 * @author keviness
 * @version 2020/12/6
*/

import java.util.*;

public class SimpleSelectedSort {
    public static void main(String[] aregs)
    {
        double[] array = new double[]{12, 23, 3.4, -12.3, 6.7, 7.8};
        System.out.println("The source array:");
        show(array);
        sort(array);
        System.out.println("The sorted array:");
        show(array);
    }

    public static void sort(double[] array)
    {
        int i, j;
        for (i=0; i<array.length; i++)
        {
            int min;
            for (min=i,j=i+1; j<array.length; j++)
            {
                if (array[min] > array[j])
                {
                    min = j;
                }
            }
            if (min != i)
            {
                double temp = array[min];
                array[min] = array[i];
                array[i] = temp;
            }
        }
    }

    public static void show(double[] array)
    {
        for (double e : array)
        {
            System.out.printf("%4.2f ", e);
        }
        System.out.println('\n');
    }

}
