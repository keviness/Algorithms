## 线性表：链表实现（链式存储实现）

### 一，概念及示意图
* 线性表顺序存储示意图
![线性表顺序存储示意图](./img/queue1.png)

### 二，实现代码
#### （一）数据形式
~~~java
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
~~~
#### （二）初始化
~~~java
public int length;
    private Node head;

    public Link()
    {
        this.length = 0;
        head = new Node("", 0);
    }
}
~~~
#### （三）检测为空或已满
~~~java
private boolean isEmpty()
    {
        return head.next == null;
    }
~~~
#### （四）追加操作
~~~java
public void append(Node target)
    {
        Node temp = head;

        while (temp.next != null)
        {
            temp = temp.next;
        }
        temp.next = target;
        this.length++;

        System.out.println("Append successfully");
    } 
~~~
#### （五）插入操作
~~~java
public boolean insert(Node target, int pos)
    {
        if (pos<1 || pos>length)
        {
            System.out.println("The pos is error!");
            return false;
        }

        Node temp = head;
        int i = 0;
        while (i<pos-1 && temp.next!= null)
        {
            temp = temp.next;
            i++;
        }
        if (i>pos-1 && temp.next==null)
        {
            System.out.println("The pos is wrong!");
            return false;
        }
        
        target.next = temp.next;
        temp.next = target;
        this.length++;

        System.out.println("Insert successfully!");
        return true;
    }

~~~
#### （六）删除元素
~~~c
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
        this.length--;

        System.out.println("Delete successfully!");
    }
~~~
