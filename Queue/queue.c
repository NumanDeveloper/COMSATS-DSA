#include <stdio.h>
#define MAX_SIZE 20

int queue[MAX_SIZE], front = -1, back = -1;

void en_queue(int);
void de_queue();
void display();
int is_full();
int is_empty();
int main(){
    en_queue(34);
    en_queue(55);
    en_queue(55);
    display();
    de_queue();
    de_queue();
    de_queue();

    // en_queue(2);
    // en_queue(4);
    // en_queue(5);

    display();

    return 0;
}

int is_full(){
    if (back == MAX_SIZE-1) return 1;
    else return 0;
}
int is_empty(){
    if (front == -1) return 1;
    else return 0;
}
void en_queue(int x){
    // check full condition
    if(is_full())
        printf("ERROR: Queue is full !!\n");
    else{
        // when inserting first element
        if (front == -1)
            front = 0;
        queue[++back] = x;
        printf("Inserted -> %d\n", queue[back]);
    }
}

void de_queue(){
    if (is_empty())
        printf("\nERROR: Queue is Empty !!\n");
    else {
        printf("Deleted -> %d\n", queue[front]);
        front++;
        if (front > back)
            // when all elements have been removed, reset the queue
            front = back = -1;
    }
}

void display(){
    if (front == -1)
        printf("Queue has currently no elements !!\n");
    else{
    printf("Queue: ");
    for (int i = front; i <= back; i++)
        printf("%d | ", queue[i]);
    printf("\n");
    }
}