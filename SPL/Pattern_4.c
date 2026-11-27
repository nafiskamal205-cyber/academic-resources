// Program to print pattern of 0s and 1s
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
            printf("%d ",col%2); // Print 0 for even column numbers and 1 for odd column numbers
        }
        printf("\n");
    }
    return 0;
}
