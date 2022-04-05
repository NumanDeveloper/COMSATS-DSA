#include <iostream>
using namespace std;

#define MAX_SIZE 10
int size=0;

struct stack
{
    int arr[MAX_SIZE];
    int top = -1;
};
typedef struct stack st;

void createEmptyStack(st *s){
    s->top = -1;
}
int isEmpty(st *s){
    if (s->top == -1) return 1; else return 0;
}
int isFull(st *s){
    if (s->top == MAX_SIZE-1) return 1; else return 0;
}
void printStack(st *s){
    if(isEmpty(s)){
        cout<<"Stack is Empty !!\n";
        return;
    } 
    else{
        cout<<"Stack: ";
        for (int i = 0; i < size; i++)
        {
            cout<<s->arr[i]<<" | ";
        }
        cout<<endl;
    }
}

void push(st *s, int x){
    if(isFull(s)){
        cout<<"ERROR: Stack Overflow!\n";
        return;
    }
    else{
        s->arr[++s->top] = x;
        size++;
    }
}

void pop(st *s){
    if(isEmpty(s)){
        cout<<"ERROR: Stack Underflow !!\n";
        return;
    }
    else{
        cout<<"Item popped: "<<s->arr[s->top]<<endl;
        s->top--;
        size--;
    }
}
int main(){
    st *s = (st *)malloc(sizeof(st));

    createEmptyStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    // cout<<isEmpty(s);
    // cout<<isFull(s);
    printStack(s);
    pop(s);
    pop(s);
    printStack(s);
    
    return 0;
}