/**stack sequence
 * @author keviness
 * @version 2020/12/1
*/
import java.util.*;

public class stackSequence
{
    public static void main(String[] args)
    {
        Stack stack = new Stack(5);
        Node a1 = new Node("kevin", 87);
        Node a2 = new Node("Lucy", 78);
        Node a3 = new Node("Nancy", 89);
        Node a4 = new Node("Bob", 90);
        Node a5 = new Node("Chair", 100);
        stack.push(a1);
        stack.push(a2);
        stack.push(a3);
        stack.push(a4);
        stack.push(a5);
        stack.show();
        Node value1 = stack.pop();
        Node value2 = stack.pop();
        System.out.println("Value1:"+value1+"\nvalue2:"+value2);
        stack.show();
    }
}

class Node
{
    public int data;
    public String name;

    public Node(String name, int data)
    {
        this.name = name;
        this.data = data;
    }

    public String toString()
    {
        return "name:"+this.name+" data:"+this.data;
    }
}

class Stack 
{
    public Node[] stack;
    public int top;
    public int length;
    public Stack(int length)
    {
        stack = new Node[length];
        this.top = -1;
        this.length = length;
    }
    
    public boolean isEmpty()
    {
        return this.top == -1;
    }

    public boolean isFull()
    {
        return this.top == this.length;
    }

    public Node get(int index)
    {
        if (index<1 || index>this.length)
        {
            System.out.println("The index error!");
            return null;
        }
        return stack[index-1];
    }

    public void push(Node target)
    {
        if (this.isFull())
        {
            System.out.println("The stack is full!");
            return;
        }
        this.top++;
        stack[this.top] = target;
        
        System.out.println("The push into the stack successfully!");
    }

    public Node pop()
    {
        if (this.isEmpty())
        {
            System.out.println("The stack is empty!");
            return null;
        }
        Node temp = stack[this.top];
        this.top--;
        System.out.println("Pop successfully!");;
        return temp;
    }

    public void show()
    {
        if (isEmpty())
        {
            System.out.println("The stack is empty!");
            return;
        }
        for (int i=this.top; i>=0; i--)
        {
            System.out.println(this.stack[i]);
        }
    }
}