#include <stdio.h>
int main()
{
      int num1;
      float num2;
      double num3;
      char ch;
      printf("Enter an integer: \n");
      printf("Enter a floating point number: \n");
      printf("Enter a double precision number:\n ");
      printf("Enter a character:\n ");
      scanf("%d", &num1);
      scanf("%f", &num2);
      scanf("%lf", &num3);
      scanf(" %c", &ch);
      printf("You entered:%d\n", num1);
      printf("You entered:%f\n", num2);
      printf("You entered:%lf\n", num3);
      printf("You entered:%c\n", ch);
      return 0;
}
