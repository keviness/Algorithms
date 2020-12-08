/**Bubble Sort By Java
* @author keviness
* @version 2020/12/5
*/

import java.util.*;

public class BubbleSort
{
    public static void main(String[] args)
    {
        double[] array = {12.1, 3, 23, 4, 78.6, -12.34, 10.9};
        //Sort target = new Sort(array);
        System.out.println("---Source Array---");
        show(array);
        bubblesort(array);
        System.out.println("---After Bubble Sort---");
        show(array);
    }

    public static void bubblesort(double[] array)
    {
        for (int i=0; i<array.length-1; i++)
        {
            int flag = 0;
            for (int j=0; j<array.length-i-1; j++)
            {
                if (array[j]>array[j+1])
                {
                    double temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
    }

    public static void show(double[] array)
    {
        for (double element : array)
        {
            System.out.printf("%4.2g ", element);
        }
        System.out.printf("\n");
    }
}

/*
class Sort
{
    public double[] array;

    public Sort(double[] array)
    {
        this.array = array;
    }

    public static void bubblesort(double[] array)
    {
        for (int i=0; i<array.length-1; i++)
        {
            int flag = 0;
            for (int j=0; j<array.length-i-1; j++)
            {
                if (array[j]>array[j+1])
                {
                    double temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
    }

    public static void show(double[] array)
    {
        for (double element : array)
        {
            System.out.printf("%lf ", element);
        }
    }
}
*/