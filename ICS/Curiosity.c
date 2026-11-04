#include <stdio.h>
int main()
{
      int num1;
      float num2;
      double num3;
      char ch;
      printf("Enter an integer: ");
      scanf("%d", &num1);
      printf("Enter a floating point number: ");
      scanf("%f", &num2);
      printf("Enter a double precision number: ");
      scanf("%lf", &num3);
      printf("Enter a character: ");
      scanf(" %c", &ch);
      printf("You entered:%d\n", num1);
      printf("You entered:%f\n", num2);
      printf("You entered:%lf\n", num3);
      printf("You entered:%c\n", ch);
      return 0;
}
