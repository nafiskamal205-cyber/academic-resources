// Program to generate Fibonacci series using array.
#include <stdio.h>
int main()
{
    int a[50],i, n;

    printf("How many numbers you want to enter?: ");
    scanf("%d",&n);

    a[0] = 0;
    a[1] = 1;

    for(i=2; i<n; i++)
    {
        a[i] = a[i-1] + a[i-2]; // Fibonacci series formula
    }
     printf("\n");

    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;

}
