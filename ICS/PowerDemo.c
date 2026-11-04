// Program to calculate the power of a number
#include <stdio.h>
#include <math.h>
int main()
{
      int x,y;
      printf("Enter the value of x: ");
      scanf("%d",&x);
      printf("Enter the value of y: ");
      scanf("%d",&y);

      double result = pow(x,y);  // Calculate x raised to the power of y

      printf("x^y = %lf\n",result);

      return 0;
}
