// Simple Calculator for calculating two numbers
#include <stdio.h>
int main()
{
    double num1,num2;
    char op;

    printf("enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    printf("enter an operator (+,-,*,/): ");
    scanf(" %c", &op);

    switch(op)
    {
        case '+':

            printf("%.2lf + %.2lf = %.2lf\n",num1,num2,num1+num2);
            break;

        case '-':
            printf("%.2lf - %.2lf = %.2lf\n",num1,num2,num1-num2);
            break;

        case '*':
            printf("%.2lf * %.2lf = %.2lf\n",num1,num2,num1*num2);
            break;

        case '/':
            if(num2!=0)
                printf("%.2lf / %.2lf = %.2lf\n",num1,num2,num1/num2);
            else
                printf("Error! Division by zero.");
            break;

        default:
            printf("Error! operator is not correct");
    }
    return 0;
}
