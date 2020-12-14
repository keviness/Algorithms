/**Fibonacci Search
* @author keviness
* @version 2020/12/14
*/
import java.util.*;

public class FibonacciSearch
{
    public static void main(String[] args)
    {
        int[] array = {1, 2, 4, 5, -1, 34, 12};
        int index = FibonacciSearch(array, array.length, 4);
        System.out.printf("The element at %d in this array!\n", index);
    }

    public static void Fibonacci(int[] F)
    {
        F[0] = 0;
        F[1] = 1;
        for(int i=2; i<max_size; ++i)
            F[i] = F[i-1] + F[i-2];
    }
    
    /*定义斐波那契查找法*/  
    public static int FibonacciSearch(int[] a, int n, int key)  //a为要查找的数组,n为要查找的数组长度,key为要查找的关键字
    {
        int low = 0;
        int high = n-1;
        int F[max_size];
        Fibonacci(F);   //构造一个斐波那契数组F 

        int k = 0;
        while(n > F[k]-1) //计算n位于斐波那契数列的位置
            ++k;
    
        int temp[F[k]-1];//将数组a扩展到F[k]-1的长度
        memcpy(temp, a, n*sizeof(int));
    
        for(int i=n; i<F[k]-1; ++i)
            temp[i] = a[n-1];
    
        while(low <= high)
        {
            int mid = low + F[k-1] - 1;
            if(key < temp[mid])
            {
                high = mid - 1;
                k-=1;
            }
            else if(key > temp[mid])
            {
                low = mid + 1;
                k-=2;
            }
            else
            {
                if(mid < n)
                    return mid; //若相等则说明mid即为查找到的位置
                else
                    return n-1; //若mid>=n则说明是扩展的数值,返回n-1
            }
        }  
        return -1;
    }
}