/**Algorithms: Single link
*@author keviness
*@version 2020/11/25
*/

import java.util.*;

public class SingleLink
{
    public static void main(String[] args)
    {
        Node a1 = new Node("kevin", 100);
        Node a2 = new Node("Bob", 98);
        Node a3 = new Node("Lucy", 89);
        Node a4 = new Node("Nancy", 78);

        Link students = new Link();
        students.append(a1);
        students.append(a2);
        students.append(a3);
        students.append(a4);
        students.show();

        students.delete(a2);
        students.show();
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
        return "name:"+this.name+" "+"data:"+this.data;
    }
}

class Link
{
    private Node head = new Node("", 0);

    public void append(Node target)
    {
        
        Node temp = head;

        while (temp.next != null)
        {
            temp = temp.next;
        }
        temp.next = target;

        System.out.println("Append successfully");
    } 

    public void delete(Node target)
    {
        if (isEmpty())
        {
            System.out.println("The link is empty!");
            return;
        }

        Node temp = head;
        while (temp.next != target)
        {
            temp = temp.next;
        }
        temp.next = target.next;
        System.out.println("Delete successfully!");
    }

    private boolean isEmpty()
    {
        return head.next == null;
    }

    public void show()
    {
        Node temp = head.next;

        while (temp != null)
        {
            System.out.println(temp);
            temp = temp.next;
        }
    }
}
