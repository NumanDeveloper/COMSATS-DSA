#include <stdio.h>
#include <conio.h>

// functions prototypes
void operations(void);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);
int calculation(int);

// global variables
int a, b, op;
int main()
{
    while (1)
    {
        printf("\nEnter values: \n");
        scanf("%d %d", &a, &b);
        operations();
        printf("\nOperation: ");
        scanf("%d", &op);
        calculation(op);
        // printf("Enter operation: ");
    }
    return 0;
}
void operations(void)
{
    printf("Pick an operation\n1.Add\n2.Subtract\n3.Multiply\n4.Divide");
}
int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}
int calculation(int op)
{
    switch (op)
    {
    case 1:
        printf("Addition: %d", add(a, b));
        break;
    case 2:
        printf("Subtraction: %d", subtract(a, b));
        break;
    case 3:
        printf("Multiplication: %d", multiply(a, b));
        break;
    case 4:
        printf("Division: %d", divide(a, b));
        break;
    default:
        printf("Invalid Operator!");
        break;
    }
}