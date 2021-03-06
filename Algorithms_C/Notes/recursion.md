## 递归（recursion）
### 一，定义
>递归：一个函数自己直接或间接调用自己
### 二，函数调用另一个函数时发生了什么？
* 主调函数运行被调函数之前：
>* 1.将实际参数，返回地址等信息传递给被调函数。
>* 2.为被调函数的局部变量（包括形参）分配存储空间。
>* 3.将控制权转移到被调函数的入口。
* 被调函数返回主调函数之前：
>* 1.保存被调函数的返回结果（若有返回值）。
>* 2.释放被调函数的存储空间。
>* 3.依照被调用函数返回的地址将控制权转移回主调函数。
* 注意：
>* 1.多个函数相互调用时，函数之间的信息传递和控制转移由栈来实现:
>* 2.在整个程序运行过程中，系统将程序运行所需要的数据空间安排在一个栈中。
>* 3.每调用一个函数，就在栈顶分配一个存储空间，对该调用的函数进行压栈操作。
>* 4.当函数执行结束返回时，就释放它的存储空间，进行出栈操作。
>* 5.因此，当前运行的函数永远在栈顶位置。
### 二，递归满足三个条件
* 1.递归必须得有一个明确的终止条件
* 2.该函数所处理的数据规模必须在递减
* 3.这个转化必须是可解的

### 三，循环和递归的关系：
* 理论上，所有的循环都可以转化成递归，但是用递归能解决的问题不一定能用循环解决。

### 四，循环和递归的比较
* 递归：易于理解，速度慢，存储空间大
* 循环：不易理解，速度快，存储空间小

### 五，常用递归示例

#### （一）计算1+2+3+...+n-1+n的和
~~~c
long sum_numbers(int num)
{
    if (num == 1)
        return 1;
    else
    {
        return sum_numbers(num-1) + num;
    }
}
~~~
#### （二）计算n的阶乘(N!)
~~~c
long multiply_numbers(int num)
{
    if (num == 1)
        return 1;
    else
        return multiply_numbers(num-1) * num;
}
~~~
#### （三）汉诺塔
![hannuo tower](./img/hannuoTower.jpg)
~~~c
void hannuo_tower(int num, char A, char B, char C)
{
    /*
	如果是一个盘子
		直接将A柱子上的盘子从A移到C
	否则
		先将A柱子上的n-1个盘子借助C移到B
		直接将A柱子上的盘子从A移到C
		最后将B柱子上的n-1个盘子借助A移到C
	*/
    if (num == 1)
        printf("move the %d pan from %c to %c \n", num, A, C);
    else
    {
        hannuo_tower(num-1, A, C, B);
        printf("move the %d pan from %c to %c \n", num, A, C);
        hannuo_tower(num-1, B, A, C);
    }
}
~~~
#### （四）斐波那契数列
~~~c
long fabo(int num)
{
    if (num == 2 || num==1)
        return 1;
    else
        return fabo(num-2) + fabo(num-1);
}
~~~

