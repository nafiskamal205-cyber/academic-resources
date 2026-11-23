// Program to find the maximum and minimum number in an array.
#include <stdio.h>
int main()
{
    int n, i, num[100];

    printf("How many numbers you want to enter?: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
    }

    int min = num[0];
    int max = num[0];

    for(i=1; i<n; i++)
    {
        if(num[i] < min)
        {
            min = num[i];
        }

        if(num[i] > max)
        {
            max = num[i];
        }
    }
    printf("Minimum number in the array is:%d\n", min);
    printf("Maximum number in the array is:%d\n", max);

    return 0;

}
