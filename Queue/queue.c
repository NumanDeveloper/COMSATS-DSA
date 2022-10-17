#include <stdio.h>
#define MAX_SIZE 20

int queue[MAX_SIZE], front = -1, back = -1;

void enQ(int);
void deQ();
void display();
int isFull();
int isEmpty();
int main()
{
    enQ(34);
    enQ(55);
    enQ(55);
    display();
    deQ();
    deQ();
    deQ();

    // enQ(2);
    // enQ(4);
    // enQ(5);

    display();

    return 0;
}

int isFull()
{
    if (back == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
void enQ(int x)
{
    // check full condition
    if (isFull())
        printf("ERROR: Queue is full !!\n");
    else
    {
        // when inserting first element
        if (front == -1)
            front = 0;
        queue[++back] = x;
        printf("Inserted -> %d\n", queue[back]);
    }
}

void deQ()
{
    if (isEmpty())
        printf("\nERROR: Queue is Empty !!\n");
    else
    {
        printf("Deleted -> %d\n", queue[front]);
        front++;
        if (front > back)
            // when all elements have been removed, reset the queue
            front = back = -1;
    }
}

void display()
{
    if (front == -1)
        printf("Queue has currently no elements !!\n");
    else
    {
        printf("Queue: ");
        for (int i = front; i <= back; i++)
            printf("%d | ", queue[i]);
        printf("\n");
    }
}