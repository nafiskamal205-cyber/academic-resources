// Program to find sum of two numbers using function
#include <stdio.h>

int sum(int a, int b); // Function prototype
int main()
{
    int  a, b, s;

    printf("Enter A, B: ");
    scanf("%d %d", &a, &b);

    printf("Sum:%d\n", sum(a,b)); // Function call

}
int sum(int a, int b) // Function definition
{
    return a + b; // Return sum of a and b
}
