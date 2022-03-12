#include <stdio.h>
#define MAX_SIZE 50

int queue[MAX_SIZE], front = -1, back = -1;

// Check if the queue is full
int is_full() {
  if ((front == back + 1) || (front == 0 && back == MAX_SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int is_empty() {
  if (front == -1) return 1;
  return 0;
}
void en_queue(int x){
    // check full condition
    if(is_full())
        printf("ERROR: Queue is full!\n");
    else{
        // when inserting first element
        if (front == -1)    
            front = 0;
        // if back becomes equal to MAX_SIZE, then modulo will work. otherwise back will simply be incremented
        back = (back + 1) % MAX_SIZE;
        queue[back] = x;
        printf("Inserted -> %d\n", queue[back]);
    }
}

void de_queue(){
    // check empty condition
    if(is_empty())
        printf("ERROR: Queue is empty!\n");
    else{
        printf("Deleted -> %d\n", queue[front]);

        if (front == back) {
            // Q has only one element, so we reset the 
            // queue after dequeing it. ?
            front = -1;
            back = -1;
        } 
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }   
}

void display(){
    if(is_empty())
        printf("Queue is empty!");
    else{
        printf("Front -> %d\n", front);
    printf("Queue: ");
    for (int i = front; i < back+1; i++)
    {
        printf("%d | ", queue[i]);
    }
        printf("\n");
        printf("Back -> %d\n", back);
    }
}
int main(){
    en_queue(1);
    en_queue(2);
    en_queue(3);
    display();
    de_queue();
    de_queue();
    display();
    en_queue(1);
    en_queue(2);
    en_queue(3);
    display();
    
    return 0;
}