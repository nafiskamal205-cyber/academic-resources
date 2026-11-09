// Program to find the square of a number using function
#include <stdio.h>

int square(int a); // Function prototype

int square(int a) // Function definition
{
    return a * a; // Return square of a
}

int main() // main function
{
    int num;
    printf("Enter any integer number: ");
    scanf("%d", &num);

    int result = square(num); // Function call to calculate the square of the number
    printf("The square of %d is: %d\n", num, result);
}
