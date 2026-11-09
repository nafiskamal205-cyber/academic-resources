// Program to find sum of three numbers using function
#include <stdio.h>

void sum(int a, int b, int c) // Function prototype
{
    printf("The sum is: %d\n", a + b + c); // Function definition
}

int main()
{
    int a, b, c;

    printf("Enter the value of A, B, C: ");
    scanf("%d %d %d", &a, &b, &c);
    sum(a, b, c); // Function call
    return 0;

}
