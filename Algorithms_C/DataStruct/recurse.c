/*** recurse ***/
#include <stdio.h>
#include <string.h>

long sum_numbers(int n);
long multiply_numbers(int n);
void hannuo_tower(int n, char A, char B, char C);
long fabo(int num);

int main(void)
{
    int num;
    char ch, A, B, C;
    A = 'A';
    B = 'B';
    C = 'C';
    puts("How many numbers do you want to handle:");
    while (scanf("%d", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a valid input, try again:");
    }
    while (getchar() != '\n')
    {
        continue;
    }
    printf("The sum value:%ld \n", sum_numbers(num));
    
    puts("***************** multiply *****************");
    puts("How many numbers do you want to handle:");
    while (scanf("%d", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a valid input, try again:");
    }
    while (getchar() != '\n')
    {
        continue;
    }
    printf("The sum value:%ld \n", multiply_numbers(num));

    puts("****************HanNuo tower*******************");
    puts("How many pans do you want to move:");
    while (scanf("%d", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a valid input, try again:");
    }
    while (getchar() != '\n')
    {
        continue;
    }
    hannuo_tower(num, A, B, C);

    puts("***************** multiply *****************");
    puts("How many numbers do you want to handle:");
    while (scanf("%d", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not a valid input, try again:");
    }
    while (getchar() != '\n')
    {
        continue;
    }
    for (int i=1; i<num; i++)
    {
        printf("%d ", fabo(i));
        if (i%4 == 0)
            putchar('\n');
    }

    return 0;
}

long sum_numbers(int num)
{
    if (num == 1)
        return 1;
    else
    {
        return sum_numbers(num-1) + num;
    }
}

long multiply_numbers(int num)
{
    if (num == 1)
        return 1;
    else
        return multiply_numbers(num-1) * num;
}

void hannuo_tower(int num, char A, char B, char C)
{
    if (num == 1)
        printf("move the %d pan from %c to %c \n", num, A, C);
    else
    {
        hannuo_tower(num-1, A, C, B);
        printf("move the %d pan from %c to %c \n", num, A, C);
        hannuo_tower(num-1, B, A, C);
    }
}

long fabo(int num)
{
    if (num == 2 || num==1)
        return 1;
    else
        return fabo(num-2) + fabo(num-1);
}