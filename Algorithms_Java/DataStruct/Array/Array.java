/**Data Struct: Array
*@author keviness
*@version 2020/11/27
*/

import java.util.*;

public class Array
{
    public static void main(String[] args)
    {
        ArrayList person = new ArrayList(5);

    }
}

class Node
{
    private int data;
    public Node(int data)
    {
        this.data = data
    }

    public String toString()
    {
        return "The data:"+this.data;
    }
}

class ArrayList
{
    public int length;
    public int count;
    public Node[] array = new Node[length];
    
    public ArrayList(int length)
    {
        this.length = length;
    }
    
    public boolean isEmpty()
    {
        return this.length == 0;
    }

    public int get(int index)
    {
        if (this.isEmpty())
        {
            System.out.println("The array is empty!");
            return;
        }
        return this.array[index].data;
    }

    public void modify(int index, int value)
    {
        if (this.isEmpty())
        {
            System.out.println("The array is empty!");
            return;
        }
        this.array[index].data = value;
    }

    public void append(Node element)
    {
        array[length-1] = element;
    }

    public void insert(int index, Node value)
    {
        if (this.isEmpty())
        {
            this.array[0] = value;
        }
        else if(index<1 && index>length+1)
        {
            System.out.println("The error index!");
            return;
        }
        else
        {
            for (int i=this.count; i>=index; i--)
            {
                this.array[i+1] = this.array[i];
            }
            this.array[i-1] = value;
        }
    } 
}

