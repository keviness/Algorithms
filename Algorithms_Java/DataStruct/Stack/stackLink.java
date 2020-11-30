/**stack by java
 *@author keviness
 *@version 2020/11/30
*/
import java.util.*;

public class stackLink {
    public static void main(String[] args)
    {
        /*
        Stack stack = new Stack();
        char choice = getChoice();
        while ( choice!='D')
        {
            switch (choice)
            {
                case 'A': stack.push(); break;
                case 'B': stack.pop(); break;
                case 'C': stack.show(); break;
                default: System.out.println("The choice is error!");
            }
        }
        */
        Stack stack = new Stack();
        Node a1 = new Node("kevin", 20);
        Node a2 = new Node("Lucy", 30);
        Node a3 = new Node("Bob", 40);
        //push in stack
        System.out.println("--Push in stack--");
        stack.push(a1);
        stack.push(a2);
        stack.push(a3);
        stack.show();
        System.out.println("The stack length:"+stack.length);
        //Pop from stack
        System.out.println("--Pop from stack--");
        Node value = stack.pop();
        System.out.println("The pop Node:"+value);
        stack.show();
        Node value1 = stack.pop();
        System.out.println("The pop Node:"+value1);
        stack.show();
    } 
    /*
    public static char getChoice()   
    {
        char choice;
        Scanner in  = new Scanner(System.in);
        System.out.println("Enter the choice:");
        System.out.println("A)Push in stack         B)Pop from stack ");
        System.out.println("C)Show the stack        D)Quit");
        do{
            System.out.print("The choice is error!try again:");
        }while ((choice = in.nextChar()) && choice<'A' && choice>'D');
        if (choice == '\n')
        {
            choice = 'D';
        }
        return choice;
    }
    */
}

class Node
{
    private int data;
    private String name;
    public Node next;

    public Node(String name, int data)
    {
        this.data = data;
        this.name = name;
    }

    public String toString()
    {
        return "name:"+this.name+" data:"+this.data;
    }
}

class Stack
{
    public int length;
    public Node top;
    public Node bottom;
    
    public Stack()
    {
        this.top = new Node(null, 0);
        this.bottom = top;
        this.length = 0;
    }

    public boolean isEmpty()
    {
        return this.top==this.bottom? true:false;
    }

    public void push(Node target)
    {
        target.next = this.top;
        this.top = target;
        this.length++;
    }

    public Node pop()
    {
        Node temp = this.top;
        this.top = temp.next;
        this.length--;
        return temp;
    }

    public void show()
    {
        if (this.isEmpty())
        {
            System.out.println("The stack is empty!");
            return;
        }

        Node temp = this.top;
        while (temp != bottom)
        {
            System.out.println(temp);
            temp = temp.next;
        } 
        System.out.println("The stack deep:"+this.length);
    }
}
