## 线性表：链表实现

### 一，概念及示意图
* 线性表顺序存储示意图
![线性表顺序存储示意图](./img/queue1.png)

### 二，实现代码
#### （一）数据形式
~~~c
typedef struct node
{
    int data;
    struct node *pnext;
}List, *Plist;
~~~
#### （二）初始化
~~~c
void InitArray(PQUEUE queue)
{
    for (int i=0; i<count; i++)
    {
        pnew = (Plist)malloc(sizeof(List));
        if (pnew == NULL)
        {
            puts("Locate mmemory error!");
            exit(EXIT_FAILURE);
        }
        printf("Enter the %d data:", i+1);
        scanf("%d", &item);
        EATLINE;
        pnew->data = item;
        pnew->pnext = NULL;
        pprevious->pnext = pnew;
        pprevious = pnew;
    }
    return phead;
}
~~~
#### （三）检测为空或已满
~~~c
bool ListIsEmpty(Plist phead)
{
    return (phead->pnext == NULL) ? true:false;
}
~~~
#### （四）追加操作
~~~c
bool AppendItem(Plist phead)
{
    Plist pnew;
    Plist p = phead;
    int item;
    while (p->pnext != NULL)
    {
        p = p->pnext;
    }
    pnew = (Plist)malloc(sizeof(List));
    if (pnew == NULL)
    {
        puts("Locate memory error!");
        return false;
    }
    puts("Enter the data you want to append:");
    scanf("%d", &item);
    EATLINE;
    pnew->data = item;
    pnew->pnext = NULL;
    p->pnext = pnew;

    printf("Enter the %d successfully!\n", item);
    return true;
}
~~~
#### （五）插入操作
~~~c
bool InsertItem(Plist phead)
{
    int pos, data;
    int i = 0;
    Plist p = phead;
    Plist pnew;
    puts("Enter the index you want to insert:");
    while ((scanf("%d", &pos) != 1) && pos<1)
    {
        EATLINE;
        puts("The error pos value, try again:");
    }
    EATLINE;
    while (i<pos-1 && p!=NULL)
    {
        p = p->pnext;
        i++;
    }
    if (i>pos-1 && p==NULL)
    {
        puts("The pos input error!");
        return false;
    }
    pnew = (Plist)malloc(sizeof(List));
    if (pnew == NULL)
    {
        puts("Can\'t locate the memory!");
        return false;
    }
    puts("Enter the data you want to save:");
    scanf("%d", &data);
    EATLINE;
    pnew->data = data;
    
    pnew->pnext = p->pnext;
    p->pnext = pnew;

    printf("successfully insert %d \n", data);
    return true;
}
~~~
#### （六）删除操作
~~~c
int DeleteItem(Plist phead)
{
    int pos, data, i, value;
    Plist pnew, p, q;
    p = phead;
    puts("Enter the pos you want to delete:");
    
    while ((scanf("%d", &pos) != 1) && pos<1)
    {
        EATLINE;
        puts("The error pos value, try again:");
    }
    EATLINE;
    i = 0;
    while (i<pos-1 && p->pnext!=NULL)
    {
        p = p->pnext;
        i++;
    }
    if (i>pos-1 || p->pnext==NULL)
    {
        puts("The pos input error!");
        exit(EXIT_FAILURE);
    }
    q = p->pnext;
    value = q->data;
    p->pnext = q->pnext;
    free(q);
    q = NULL;

    return value;
}
~~~
#### （七）遍历操作
~~~c
bool TraverseList(Plist phead, void(*pfun)(Plist plst))
{
    Plist p = phead->pnext;
    if (ListIsEmpty(phead))
    {
        puts("The List is empty！");
        return false;
    }
    while (p != NULL)
    {
        (*pfun)(p);
        p = p->pnext;
    }
    return true;
}
~~~
#### （八）获取长度
~~~c
int ListLength(Plist phead)
{
    int count = 0;
    Plist p = phead->pnext;
    while (p != NULL)
    {
        p = p->pnext;
        count++;
    }
    return count;
}
~~~
