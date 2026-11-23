// Program to find the sum and average of an array.
#include<stdio.h>
int main()
{
    int a[100], i, n, sum = 0;
    float average;

    printf("How many numbers you want to enter?: ");
    scanf("%d",&n);

      if(n < 1 || n > 100)
    {
        printf("Invalid number of elements!\n");
        return 0;
    }

    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);

        sum = sum + a[i];
    }
        average = (float)sum/n;

        printf("Sum of the array is:%d\n", sum);

        printf("Average of the array is:%.2f\n", average);

        return 0;
}
