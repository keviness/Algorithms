/**Sequence Sort by java
 * @author keviness
 * @version 2020/12/13
*/

public class SequenceSort {
    public static void main(String[] args)
    {
        double[] array = {12.3, 2.4, 3.4, -2.3, 5.6};
        int index = sequenceSort(array, 3.4);
        System.out.println("The element is at " + index);
    }

    public static int sequenceSort(double[] array, double target)
    {
        for (int i=0; i<array.length; i++)
        {
            if (target == array[i])
            {
                return i;
            }
        }
        System.out.println("Can\'t find the target in this array'");
        return -1;
    }
}
