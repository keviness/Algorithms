/**
 * @author keviness
 * @version 2020/12/2
*/

import java.util.*;

public class QueueLink 
{
    public static void main(String[] args)
    {
        Queue queue = new Queue();
        Node a1 = new Node("Kevin", 12);
        Node a2 = new Node("Lucy", 23);
        Node a3 = new Node("Nancy", 24);
        queue.inQueue(a1);
        queue.inQueue(a2);
        queue.inQueue(a3);
        queue.show();
        queue.enQueue();
        queue.show();
    }
}

class Node
{
    private int data;
    private String name;
    public Node next;

    public Node(String name, int data)
    {
        this.name = name;
        this.data = data;
    }

    public String toString()
    {
        return "The name:"+this.name+" The data:"+this.data;
    }
}

class Queue
{
    public Node front;
    public Node rear;
    public int length;

    public Queue()
    {
        this.front = new Node(null, 0);
        this.rear = this.front;
        this.length = 0;
    }

    public boolean isEmpty()
    {
        return this.rear == this.front;
    }

    public void inQueue(Node target)
    {
        this.rear.next = target;
        this.rear = target;
        this.length++;
    }

    public Node enQueue()
    {
        if (this.isEmpty())
        {
            System.out.println("The queue is empty!");
            return null;
        }
        Node temp = this.front.next;
        System.out.println("The enqueue node:"+temp);
        this.front.next = temp.next;
        if (temp == this.rear)
        {
            this.rear = this.front;
        }

        return temp;
    }

    public void show()
    {
        if (this.isEmpty())
        {
            System.out.println("The queue is empty!");
            return;
        }
        Node temp = this.front.next;
        while (temp != null)
        {
            System.out.println(temp);
            temp = temp.next;
        }
    }
}