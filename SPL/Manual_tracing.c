// Program to calculate factorial of a number using while loop
#include <stdio.h>
int main()
{
    int i, a, b, n;
    n = 5;
    a = 1;
    b = 1;
    i = 1;

   while( i <= n)
    {
        a = a * i;
        b++;
        i++;
    }
    printf("Factorial = %d\n",a);

    return 0;
}
