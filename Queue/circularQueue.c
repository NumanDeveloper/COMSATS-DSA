#include <stdio.h>
#define MAX_SIZE 20

int queue[MAX_SIZE], front = -1, back = -1;

void enQ(int);
void deQ();
void display();
int isFull();
int isEmpty();
// Check if the queue is full
int isFull()
{
    if ((front == back + 1) || (front == 0 && back == MAX_SIZE - 1))
        return 1;
    else
        return 0;
}

// Check if the queue is empty
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
        printf("ERROR: Queue is full!\n");
    else
    {
        // when inserting first element
        if (front == -1)
            front = 0;
        // if back becomes equal to MAX_SIZE, then modulo will work. otherwise back will simply be incremented
        back = (back + 1) % MAX_SIZE;
        queue[back] = x;
        printf("Inserted -> %d\n", queue[back]);
    }
}

void deQ()
{
    // check empty condition
    if (isEmpty())
        printf("ERROR: Queue is empty !!\n");
    else
    {
        printf("Deleted -> %d\n", queue[front]);

        if (front == back)
        {
            // Q has only one element, so we reset the
            // queue after dequeueing it. ?
            front = -1;
            back = -1;
        }
        else
            front = (front + 1) % MAX_SIZE;
    }
}

void display()
{
    if (isEmpty())
        printf("Queue currently has no elements to display !!\n");
    else
    {
        printf("Front Pointer -> %d\n", front);
        printf("Queue: ");
        for (int i = front; i < back + 1; i++)
            printf("%d | ", queue[i]);
        printf("\n");
        printf("Back Pointer -> %d\n", back);
        printf("\n");
    }
}
int main()
{
    enQ(1);
    enQ(2);
    enQ(3);
    display();
    deQ();
    deQ();
    deQ();
    display();

    return 0;
}