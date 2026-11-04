// Program to find the sum of the digits of a number

#include <stdio.h>

int main()
{
    int n, digit, sum = 0;

    scanf("%d", &n);
    if (n == 0)
    {
        printf("Sum of digits = 0");
    }
    else
    {
        while (n > 0)
        {
            digit = n % 10;  // get the last digit
            sum = sum + digit;  // add the digit to sum
            n = n / 10;  // remove the last digit
        }

        printf("Sum of digits = %d\n", sum);
    }

    return 0;
}
