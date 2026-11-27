// Program to print a pattern of numbers in increasing and decreasing order
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
            printf("%d ",row);
        }
        printf("\n");
    }

   for(row=n-1; row>=1; row--)  // Loop for decreasing pattern
    {
        for(col=1; col<=row; col++)
        {
            printf("%d ",row); // Print the current row number instead of column number
        }
        printf("\n");
    }
    return 0;
}
