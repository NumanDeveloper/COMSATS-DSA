#include <stdio.h>
#define MAX_SIZE 50

int queue[MAX_SIZE], front = -1, back = -1;

void en_queue(int x){
    if(back == MAX_SIZE -1)
        printf("ERROR: Queue is full!\n");
    else{
        // when inserting first element
        if (front == -1)
            front = 0;
        queue[++back] = x;
        printf("Inserted -> %d\n", queue[back]);
    }
}

void de_queue(){
    if(front == back)
        printf("ERROR: Queue is empty!\n");
    else{
        printf("Deleted -> %d\n", queue[front]);
        front++;
    }
    // if front crosses back in case of deletion of all the elements
    if(front > back)
        front = back = -1;
}

void display(){
    printf("Queue: ");
    for (int i = front; i < back+1; i++)
    {
        printf("%d | ", queue[i]);
    }
}
int main(){
    en_queue(34);
    en_queue(34);
    en_queue(34);
    de_queue();
    de_queue();
    en_queue(2);
    en_queue(2);
    en_queue(2);
    display();
    return 0;
}