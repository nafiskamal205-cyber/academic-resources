// Program to calculate the sum of numbers from 0 to n
#include <stdio.h>
int  main()
{
    int n,sum=0;
    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i=0; i<=n; i++) // Loop to calculate the sum of numbers from 0 to n
    {
        sum = sum + i;  // Add the current number to the sum
    }
    printf("Sum = %d\n", sum);
    return 0;
}
