#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
void display(struct stack *ptr);
int isEmpty(struct stack *ptr);
int isFull(struct stack *ptr);
void push(struct stack *ptr, int val);
void pop(struct stack *ptr);

int main()
{
    system("cls");
    // make a pointer to the stack of type struct stack having size equal to stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1; // initially, stack is empty
    // creating dynamic array
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    push(sp, 43);
    push(sp, 76);
    push(sp, 23);
    push(sp, 55);
    pop(sp);
    return 0;
}
void display(struct stack *ptr)
{
    // we'll store top index in temp to restrict updation of top index
    int temp = ptr->top;
    printf("Stack: ");
    for (int j = 0; j < temp + 1; j++)
        printf("%d ", ptr->arr[j]);

    printf("\n");
}
int isEmpty(struct stack *ptr)
{
    return (ptr->top == -1) ? 1 : 0;
}

int isFull(struct stack *ptr)
{
    // if our top has reached last index
    return (ptr->top == ptr->size - 1) ? 1 : 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
        printf("Stack Overflow! Cannot push %d to the stack.\n", val);
    else
    {
        // first increment/update top, then insert value
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("%d pushed to the stack.\n", val);
    }
    display(ptr);
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
        printf("Error: Stack Underflow! Can't pop from stack.\n");
    else
    {
        printf("%d popped from the stack.\n", ptr->arr[ptr->top]);
        ptr->top--;
        display(ptr);
    }
}