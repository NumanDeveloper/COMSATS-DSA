#include <iostream>
using namespace std;

#define MAX_SIZE 10
int size = 0;

struct Q{
    int arr[MAX_SIZE];
    int front;
    int rear;
};
typedef struct Q st;

void createEmptyQ(st *q){
    cout<<"Queue created successfully !!\n";
    q->front = q->rear = -1;
}
int isEmpty(st *q){
    if(q->front == -1)
        return 1;
    return 0;
}

int isFull(st *q){
    if(q->front == q->rear + 1 || (q->front == 0 && q->rear == MAX_SIZE-1))
        return 1;
    return 0;
}
void printQ(st *q){
    if(isEmpty(q))
        cout<<"Queue is empty !!\n";
    else{
        cout<<"Queue: ";
        for (int i = 0; i < size; i++)
            cout<<q->arr[i]<<" | ";
        cout<<endl;
    }
}

void enQ(st *q, int x){
    if(isFull(q)) cout<<"ERROR: Queue is full !!\n";
    else{
        size++;
        if(q->front == -1) q->front = 0;
        q->rear = (q->rear+1) % MAX_SIZE;
        q->arr[q->rear] = x;
        cout<<"EnQueued -> "<< q->arr[q->rear] <<endl;
    }
}

void deQ(st *q){
    if(isEmpty(q)) cout<<"ERROR: Queue is empty !!\n";
    else{
        cout<<"DeQueued -> "<< q->arr[q->front] <<endl;
        size--;

        if(q->front == q->rear) 
            // Reset Queue
            q->front = q->rear = -1;
        else   
            q->front = (q->front+1) % MAX_SIZE; // move front forward
    }
    
}
int main(){
    st *q = (st *)malloc(sizeof(st));

    createEmptyQ(q);
    printQ(q);
    enQ(q, 34);
    enQ(q, 34);
    enQ(q, 34);
    printQ(q);
    deQ(q);
    deQ(q);
    deQ(q);
    printQ(q);

    return 0;
}