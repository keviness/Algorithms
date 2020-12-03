
## 队列：链式存储实现

### 二，实现代码

#### （一）结点形式
~~~java
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
~~~

#### （二）初始化
~~~java
public int length;
public int count;
public ArrayList(int length)
{
    this.length = length;
    public Node[] array = new Node[this.length];
}
~~~

#### （三）检测为空/满
~~~java
public boolean isEmpty()
{
    return this.count == 0? true:false;
}
public boolean isFull()
{
    return this.count == this.length? true:false;
}
~~~

#### （四）获取元素
~~~java
public int get(int index)
    {
        if (this.isEmpty())
        {
            System.out.println("The array is empty!");
            return -1;
        }
        return this.array[index-1].data;
    }
~~~

#### （五）修改元素
~~~java
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
~~~

#### （六）末尾追加元素
~~~java
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
~~~
#### （七）插入元素
~~~java
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
~~~
#### （八）删除元素
~~~java
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
~~~
#### （九）打印元素
~~~java
public void show()
    {
        System.out.println("The array elements:");
        for (int i=0; i<this.count; i++)
        {
            System.out.println(i+1 + ": "+ array[i]);
        }
    }
~~~