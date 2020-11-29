/**Data Struct: Array
*@author keviness
*@version 2020/11/27
*/

import java.util.*;

public class Array
{
    public static void main(String[] args)
    {
        ArrayList personList = new ArrayList();
        Node a1 = new Node(12);
        Node a2 = new Node(13);
        Node a3 = new Node(16);
        Node a4 = new Node(20);

        System.out.println(a1);
        System.out.println(a2);
        System.out.println(personList.length);
        //(personList.array)[0] = a1;
        //personList.array[1] = a2;
        personList.append(a1);
        personList.append(a2);
        personList.append(a4);
        personList.show();
        personList.insert(2, a3);
        personList.show();
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
    public int length = 5;
    public int count;
    
    public Node[] array = new Node[this.length];
    
    public boolean isEmpty()
    {
        return this.count == 0? true:false;
    }

    public boolean isFull()
    {
        return this.count == this.length? true:false;
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
        if (this.isFull())
        {
            System.out.println("The array is full!");
            return;
        }
        this.array[this.count] = element;
        this.count++;
    }

    public void insert(int index, Node value)
    {
        if (this.isEmpty())
        {
            this.array[0] = value;
        }
        else if (this.isFull())
        {
            System.out.println("The array is full!");
            return;
        }
        else if(index<1 && index>count+1)
        {
            System.out.println("The error index!");
            return;
        }
        else
        {
            for (int i=this.count-1; i>=index-1; i--)
            {
                this.array[i+1] = this.array[i];
            }
            this.array[index] = value;
            this.count++;
        }
    } 

    public void show()
    {
        System.out.println("The array elements:");
        for (int i=0; i<this.count; i++)
        {
            System.out.println(i+1 + ": "+ array[i]);
        }
    }
}

