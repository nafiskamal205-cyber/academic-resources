// Program to calculate the area of a triangle using a function
#include <stdio.h>

 float triangleArea(float b, float h);  // Function prototype

int main()
{
    float base, height;

    printf("Enter Base: ");
    scanf("%f",&base);

    printf("Enter Height: ");
    scanf("%f",&height);

    float area = triangleArea(base , height);  // Function call to calculate the area of the triangle
    printf("Area = %.2f\n",area);


}
    float triangleArea(float b, float h)  // Function definition
  {
    return 0.5 * b * h;  // Formula to calculate the area of a triangle
  }
