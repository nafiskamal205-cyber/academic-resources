// Program to print pattern of 0s and 1s at even and odd rows
#include <stdio.h>
int main()
{
    int n, row, col;

    printf("Enter N: ");
    scanf("%d",&n);

    for(row=1; row<=n; row++)
    {
        for(col=1; col<=row; col++)
        {
            printf("%d ",row%2); // Print 0 for even row numbers and 1 for odd row numbers
        }
        printf("\n");
    }
    return 0;
}
