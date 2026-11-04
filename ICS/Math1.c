// Program to demonstrate the use of log10 and sin functions from the math library
#include <stdio.h>
#include <math.h>

int main()
{
    double x, result, result2;

    printf("For log10(x) and sin(x) functions\n Enter a value for x: ");
    scanf("%lf", &x);

    result = log10(x);  // Calculate the base-10 logarithm of x
    result2 = sin(x);  // Calculate the sine of x

    printf("log10(%lf) = %lf\n", x, result);
    printf("sin(%lf) = %lf\n", x, result2);

    return 0;
}
