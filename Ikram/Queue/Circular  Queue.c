#include<stdio.h>
#include<stdlib.h>
#define max 3
struct circular{
    char queue[max];
    int rear;
    int front;
}abc;
void Insertion_at_Rear(char value);
char Deletion_from_Front();
int main(){
    abc.front=-1;
    abc.rear=-1;
    int num,i;
    char a,b;
    for(;;){
        printf("\n1.Insert at Rear\n2.Delete from Front\n3.Display\n4.Exit\n");
        scanf("%d",&num);
        switch(num){
            case 1:{
                printf("Enter the value:\t");
                fflush(stdin);
                scanf("%c",&a);
                Insertion_at_Rear(a);
                break;
            }
            case 2:{
                b=Deletion_from_Front();

                if(b!=(int)b)
                    printf("Value deleted from Front= %c \n",b);
                break;
            }
            case 3:{
                printf("Array \n\n %s",abc.queue);
                break;
            }
            case 4:{
                exit(0);
                break;
            }
        }
    }
}
void Insertion_at_Rear(char value){
    if((abc.front==0 && abc.rear==max-1) || (abc.front == abc.rear+1)){
        printf("Queue Overflow");
        return;
    }

    if(abc.front==-1 && abc.rear==-1){
        abc.front=0;
        abc.rear=0;
    }
    else if(abc.rear== max-1 && abc.front != 0){
        abc.rear=0;
    }
    else{
        abc.rear++;
    }
    abc.queue[abc.rear]=value;
}
char Deletion_from_Front(){
    char value;
    if(abc.front==-1 && abc.rear==-1){
        printf("Queue Underflow\n");
        return '-1';
    }
    value=abc.queue[abc.front];

    if(abc.front==abc.rear){
        abc.front=-1;
        abc.rear=-1;
    }
    else if(abc.front == max-1){
        abc.front=0;
    }
    else{
        abc.front++;
    }
    return value;
}
