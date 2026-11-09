#include <stdio.h>

int myPower(int x, int y); // Function prototype

int main()
{
    int x,y;
    printf("Enter the value of x and y: ");
    scanf("%d %d",&x,&y);

    printf("Power: %d\n", myPower(x,y)); // Function call

}

int myPower(int x, int y) // Function definition
{
    int i, pow = 1;  // Variable to store the result of x raised to the power y
    for(i = 1; i <= y; i++) 
    {
        printf(" %d ",x); 
        pow = pow * x; 
    }
    return pow; 
}
