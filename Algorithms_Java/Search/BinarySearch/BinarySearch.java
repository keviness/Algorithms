/**Binary Search
 * @author keviness
 * @version 2020/12/13
*/

import java.util.*;

public class BinarySearch {
    
    public static void main(String[] args)
    {
        double[] array = {-1.2, 2.3, 3.4, 4.5, 7.8, 9.7};
        int index = binarySearch(array, 4.5);
        System.out.printf("Find the target at %d in this array \n", index);
    }

    public static int binarySearch(double[] array, double target)
    {
        int low, high, middle;
        low = 0;
        high = array.length-1;
        while (low <= high)
        {
            middle = (low + high)/2;
            if (array[middle] == target)
            {
                return middle;
            }
            else if (array[middle] < target)
            {
                low = middle+1;
            }
            else if (array[middle] > target)
            {
                high = middle-1;
            }
        }
        System.out.println("The target can\'t be find in this array!'");

        return -1;
    }
}
