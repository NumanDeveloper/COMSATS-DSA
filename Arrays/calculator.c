#include <stdio.h>
#include <conio.h>

// functions prototypes
void showOperations(void);
void get_value(void);
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
        showOperations();
        printf("\nOperation: ");
        scanf("%d", &op);
        if (op == 5)
        {
            printf("Exiting...");
            break;
        }
        get_value();
        calculation(op);
    }
    return 0;
}
void showOperations(void)
{
    printf("\n***CALCULATOR***\nPick an operation\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit");
}

void get_value(void)
{
    printf("\nEnter 1st value: ");
    scanf("%d", &a);
    printf("Enter 2nd value: ");
    scanf("%d", &b);
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
        printf("Addition: %d\n", add(a, b));
        break;
    case 2:
        printf("Subtraction: %d\n", subtract(a, b));
        break;
    case 3:
        printf("Multiplication: %d\n", multiply(a, b));
        break;
    case 4:
        printf("Division: %d\n", divide(a, b));
        break;
    default:
        printf("Invalid Operator!\n");
        break;
    }
}