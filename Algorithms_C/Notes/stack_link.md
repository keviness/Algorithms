## 栈的链式存储实现

### 一，概念及示意图
* 栈的链式存储示意图
![栈链式存储示意图](./img/queue1.png)

### 二，实现代码
#### （一）数据形式
~~~c
typedef struct node
{
    int data;
    struct node *pnext;
}NODE, * Pnode;
typedef struct stack
{
    Pnode top;
    Pnode buttom;
}STACK, * Pstack;
~~~
#### （二）初始化
~~~c
void InitStack(Pstack stack)
{
    stack->top = (Pnode)malloc(sizeof(NODE));
    if (stack->top == NULL)
    {
        puts("Error in locate the memory!");
        exit(EXIT_FAILURE);
    }
    stack->buttom = stack->top;
    stack->top->pnext = NULL;
}
~~~
#### （三）检测为空
~~~c
bool StackIsEmpty(Pstack stack)
{
    if (stack->top == stack->buttom)
    {
        return true;
    }
    else
    {
        return false;
    }
    //return (stack->top)==(stack->buttom) ? true:false;
}
~~~
#### （四）压栈操作
~~~c
bool PushStack(Pstack stack)
{
    int value;
    Pnode pnew = (Pnode)malloc(sizeof(NODE));
    if (pnew == NULL)
    {
        puts("Error in locating memory!");
        return false;
    }
    puts("Enter the data you want to save:");
    while (scanf("%d", &value) != 1)
    {
        EATLINE;
        puts("Error value you input, try again:");
    }
    EATLINE;
    pnew->data = value;
    pnew->pnext = stack->top;
    stack->top = pnew;
    printf("push %d into the stack successfully!\n", value);
    return true;
}
~~~
#### （五）出栈操作
~~~c
bool PopStack(Pstack stack)
{
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return false;
    }

    Pnode temp;
    int data;
    temp = stack->top;
    data = temp->data;
    stack->top = temp->pnext;
    free(temp);
    temp = NULL;
    printf("pop %d from stack successfully!\n", data);

    return true;
}
~~~
#### （六）获取栈的长度
~~~c
void GetStackLength(Pstack stack)
{
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return;
    }
    int count = 0;
    Pnode previousTop = stack->top;
    while (previousTop != (stack->buttom))
    {
        count++;
        previousTop = previousTop->pnext;
    }
    printf("The stack length:%d \n", count);
}
~~~
#### （七）遍历操作
~~~c
void TraverseStack(Pstack stack, void(*pfun)(int *data))
{
    if (StackIsEmpty(stack))
    {
        puts("The stack is empty!");
        return;
    }
    Pnode previousTop = stack->top;
    while (previousTop != (stack->buttom))
    {
        (*pfun)(&(previousTop->data));
        previousTop = previousTop->pnext;
    }
}
~~~
