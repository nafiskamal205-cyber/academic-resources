// Program to find and count multiples of 3 between 1 and a given upper limit
#include <stdio.h>

int isMultipleOf3(int x);  // Function prototype

int main()
{
    int i, n, count = 0;

    printf("Enter the upper limit: ");
    scanf("%d", &n);

    printf("Multiples of 3 between 1 and %d: ", n);

    for (i = 1; i <= n; i++)
    {
        if (isMultipleOf3(i) == 1)  // Check if i is a multiple of 3
        {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal number of multiples of 3: %d\n", count);

    return 0;
}

int isMultipleOf3(int x) // Function to check if a number is a multiple of 3
{
    if (x % 3 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
