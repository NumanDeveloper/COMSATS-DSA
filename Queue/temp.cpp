#include <stdio.h>
#define MAX_SIZE 20

int queue[MAX_SIZE], front = -1, back = -1;

void enQueue(int x){
    if (front == -1)
        front = 0;
    queue[++back] = x;
}

void deQueue(){
    front++;
}


int main(){
    enQueue(33);
    deQueue();
    return 0;
}

