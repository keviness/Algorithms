/**Queue Sequence
* @author keviness
* @version 2020/12/4
*/

import java.util.*;

public class QueueSequence
{
    public static void main(String[] args)
    {
        Queue queue = new Queue(6);
        Node a1 = new Node("kevin", 12);
        Node a2 = new Node("Lucy", 13);
        Node a3 = new Node("Bob", 23);
        queue.EnQueue(a1);
        queue.EnQueue(a2);
        queue.EnQueue(a3);
        queue.show();
        queue.DeQueue();
        queue.show();
        queue.DeQueue();
        queue.show();
        queue.show();
    }
}

class Node
{
    private int data;
    private String name;
    
    public Node(String name, int data)
    {
        this.name = name;
        this.data = data;
    }

    public String toString()
    {
        return "The name:"+this.name+" the data:"+this.data;
    }
}

class Queue
{
    public int length;
    public int count;
    public int front;
    public int rear;
    public Node[] queue;
    public Queue(int length)
    {
        this.length = length;
        queue = new Node[this.length];
        this.front = 0;
        this.rear = 0;
    }

    public boolean isEmpty()
    {
        return this.front == this.rear;
    }

    public boolean isFull()
    {
        return (this.rear+1)%this.length == this.front;
    }

    public void EnQueue(Node target)
    {
        if (this.isFull())
        {
            System.out.println("The queue is full!");
            return;
        }
        this.queue[this.rear] = target;
        this.rear = (this.rear+1)%this.length;
    }

    public Node DeQueue()
    {
        if (this.isEmpty())
        {
            System.out.println("The queue is empty!");
            return null;
        }
        Node temp = this.queue[this.front];
        this.front = (this.front+1)%this.length;

        return temp;
    }

    public void show()
    {
        if (this.isEmpty())
        {
            System.out.println("The queue is empty!");
            return;
        }
        int i = this.front;
        while (i != this.rear)
        {
            System.out.println(this.queue[i]);
            i = (i+1)%this.length;
        }
    }
}