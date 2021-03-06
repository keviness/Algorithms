## 栈的顺序存储实现

### 一，概念及示意图
* 栈的顺序存储示意图
![栈顺序存储示意图](./img/stack_sequence.png)

### 二，实现代码
#### （一）数据形式
~~~c
typedef struct stack
{
    int *pint;
    int top;
}STACK;
~~~
#### （二）初始化
~~~c
bool InitializeStack(STACK *pstack)
{
    pstack->pint = (int *)malloc(sizeof(int) * SIZE);
    if (pstack->pint == NULL)
    {
        puts("Can\'t locate memory!");
        return false;
    }
    pstack->top = -1;

    return true;
}
~~~
#### （三）检测为空或为满
~~~c
bool StackIsEmpty(STACK *pstack)
{
    return (pstack->top == -1)? true:false;
}

bool StackIsFull(STACK *pstack)
{
    return (pstack->top == SIZE)? true:false;
}
~~~
#### （四）压栈操作
~~~c
bool PushStack(STACK *pstack)
{
    if (StackIsFull(pstack))
    {
        puts("The stack is full!");
        return false;
    }
    int data, ch;
    puts("Enter the data you want to push:");
    while (scanf("%d", &data) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        puts(" is not a number! try again:");
    }
    EATLINE;

    (pstack->top)++;
    (pstack->pint)[pstack->top] = data;

    return true;
}
~~~
#### （五）出栈操作
~~~c
bool PopStack(STACK *pstack)
{
    if (StackIsEmpty(pstack))
    {
        puts("The stack is empty!");
        return false;
    }
    int data;
    data = (pstack->pint)[pstack->top];
    (pstack->top)--;
    printf("The poped data is:%d \n", data);

    return true;
}
~~~
