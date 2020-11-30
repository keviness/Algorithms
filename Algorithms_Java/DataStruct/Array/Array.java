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
        //append
        System.out.println("--append--");
        personList.append(a1);
        personList.append(a2);
        personList.append(a4);
        personList.show();
        //insert
        System.out.println("--insert--");
        personList.insert(2, a3);
        personList.show();
        //get value
        int value = personList.get(2);
        System.out.println("get value:"+value);
        //modify
        System.out.println("--midify--");
        personList.modify(3, 18);
        personList.show();
        //delete
        System.out.println("--delete--");
        personList.delete(2);
        personList.show();
    }

    /*
        char choice;
        while ((choice=getChoice()) && choice!='E')
        {
            switch (choice)
            {
                case 'A': personList.append();  break;
                case 'B': personList.modify();
            }
        }
    */
    /*
    public char getChoice()
    {
        System.out.println("Enter the choice:");
        System.out.println("A)Append         B)Modify");
        System.out.println("C)Insert         D)Show");
        System.out.println("E)Quit");
        Scanner in = new Scanner(System.in);
        char choice = in.nextChar();
        while (choice<'A' || choice>'E')
        {
            System.out.println("The choice is error, try again:");
            choice = in.nextChar();
        }
        if (choice == '\n')
        {
            choice = 'E';
        }
        return choice;
    }
    */
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
        return this.array[index-1].data;
    }

    public void modify(int index, int value)
    {
        if (this.isEmpty())
        {
            System.out.println("The array is empty!");
            return;
        }
        this.array[index].data = value;
        System.out.printf("%d modified successfully! \n", index);
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
        if (this.isEmpty() || index==1)
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
            this.array[index-1] = value;
            this.count++;
            System.out.printf("%d inserted successfully! \n", index);
        }
    } 

    public void delete(int index)
    {
        if (this.isEmpty())
        {
            System.out.println("The array is empty!");
            return;
        }
        if (index<1 || index>this.count)
        {
            System.out.println("The index is error!");
            return;
        }
        for (int i=index; i<this.count; i++)
        {
            this.array[i-1] = this.array[i];
        }
        this.array[this.count-1] = null;
        this.count--;
        System.out.printf("%d deleted successfully! \n", index);
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

