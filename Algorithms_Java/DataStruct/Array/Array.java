/**Data Struct: Array
*@author keviness
*@version 2020/11/27
*/

import java.util.*;

public class Array
{
    public static void main(String[] args)
    {
        ArrayList personList = new ArrayList(5);
        Node a1 = new Node(12);
        Node a2 = new Node(13);
        System.out.println(a1);
        System.out.println(a2);
        System.out.println(personList.length);
        personList.append(a1);
        //personList.append(a2);
        //personList.show();
    }
}

class Node
{
    public int data;

    public Node(int data)
    {
        this.data = data;
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
    
    public ArrayList(int length)
    {
        this.length = length;
    }
    public Node[] array = new Node[this.length];
    
    public boolean isEmpty()
    {
        return this.count == 0;
    }

    public int get(int index)
    {
        if (this.isEmpty())
        {
            System.out.println("The array is empty!");
            return -1;
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
        if (isEmpty())
        {
            this.array[count] = element;
            return;
        }
        this.array[this.count-1] = element;
        this.count++;
    }

    public void insert(int index, Node value)
    {
        if (this.isEmpty())
        {
            this.array[0] = value;
        }
        else if(index<1 && index>count+1)
        {
            System.out.println("The error index!");
            return;
        }
        else
        {
            int i = 0;
            for (i=this.count; i>=index; i--)
            {
                this.array[i+1] = this.array[i];
            }
            this.array[i-1] = value;
            this.count++;
        }
    } 

    public void show()
    {
        for (int i=0; i<this.count; i++)
        {
            System.out.println(array[i]);
        }
    }
}

