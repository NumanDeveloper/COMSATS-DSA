#include<stdio.h>
#define max 10
struct circular{
    char queue[max];
    int rear;
    int front;
}abc;
void Insertion_at_Rear(char value);
char Deletion_from_Front();
void Insertion_at_Front(char value);
char Deletion_from_Rear();
void display();
int main(){
    abc.front=-1;
    abc.rear=-1;
    int num,i;
    char a,b;
    for(;;){
        printf("\n\n1. ______ Insert at Rear   ________\n2. ______ Delete from Front   ________\n3. ______ Insert at Front  ________\n4. ______ Delete from Rear   ________\n5. ______ Display________\n6. ______ Exit________\n");
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

            case 3:
                {
                printf("Enter the value:\t");
                fflush(stdin);
                scanf("%c",&a);
                Insertion_at_Front(a);
                break;

                }
            case 4:
                {
                b=Deletion_from_Rear();

                if(b!=(int)b)
                    printf("Value deleted from Rear= %c \n",b);
                break;

                }
            case 5:{
                display();
                break;
            }
            case 6:{
                exit(0);
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
     value=abc.queue[abc.front];
    if(abc.front==-1 && abc.rear==-1){
        printf("Queue Underflow\n");
        return '-1';
    }


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

void Insertion_at_Front(char value){
    if((abc.front==0 && abc.rear == max-1) || (abc.front==abc.rear+1)){
        printf("Queue Overflow");
        return;
    }

    if(abc.front==-1 && abc.rear==-1){
        abc.front=0;
        abc.rear=0;
    }
    else if(abc.rear!= max-1 && abc.front == 0){
        abc.front=max-1;
    }
    else{
        abc.front--;
    }
    abc.queue[abc.front]=value;
}

char Deletion_from_Rear(){
    char value;
    value=abc.queue[abc.rear];
    if(abc.front==-1 && abc.rear==-1){
        printf("Queue Underflow\n");
        return '-1';
    }


    if(abc.front==abc.rear){
        abc.front=-1;
        abc.rear=-1;
    }
    else if(abc.rear == 0 ){
        abc.rear=max-1;
    }
    else{
        abc.rear--;
    }
    return value;
}


void display()
{
    int i,j;
    if(abc.front==-1&&abc.rear==-1)
    {
        printf("Queue is empty\n");
    }
    if(abc.front>abc.rear)
    {
        for(i=0;i<=abc.rear;i++)
            printf("%c",abc.queue[i]);
        for(j=abc.front;j<=max-1;j++)
            printf("%c",abc.queue[j]);
        printf("\nrear is at %c\n",abc.queue[abc.rear]);
        printf("\n R = %d",abc.rear);
        printf("\nfront is at %c\n",abc.queue[abc.front]);
        printf("\n F = %d",abc.front);
    }
    else
    {
        for(i=abc.front;i<=abc.rear;i++)
        {
            printf("%c",abc.queue[i]);
        }
        printf("\nrear is at %c\n",abc.queue[abc.rear]);
              printf("\n R = %d",abc.rear);
        printf("\nfront is at %c\n",abc.queue[abc.front]);
        printf("\n F = %d",abc.front);
    }
    printf("\n");
}
