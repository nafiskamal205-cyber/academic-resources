// Program to print a pattern of alphabets in increasing order
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
            printf("%c ",row+64); // Print alphabets according to row numbers
        }
        printf("\n");
    }
    return 0;
}
