#include<conio.h>
#include<stdio.h>
#include<process.h>
#define MAX 50

int deque_arr[MAX];
int left =-1;
int right = -1;

void insert_right(){
    int added_item;
    if ((left == 0 && right == MAX-1) || (left == right+1)){
        printf ("\nQueue Overflow\n");
        getch();
    return;
    }
    if (left == -1){
        left = 0;
        right = 0;
    }
    else if(right == MAX-1)
        right = 0;
    else
        right = right+1;
    printf("\n Input the element for adding in queue: ");
    scanf ("%d", &added_item);
    deque_arr[right] = added_item ;
}
void insert_left(){
    int added_item;
    if ((left == 0 && right == MAX-1) || (left == right+1)){
        printf ("\nQueue Overflow \n");
        getch();
        return;
    }
    if (left == -1){
        left = 0;
        right = 0;
    }
    else if(left== 0)
        left = MAX -1;
    else
        left = left-1;
    printf("\nInput the element for adding in queue:");
    scanf ("%d", &added_item);
    deque_arr[left] = added_item ;
}
void delete_left(){
    if (left == -1){
        printf("\nQueue Underflow\n");
        return;
    }
    printf ("\nElement deleted from queue is: %d\n",deque_arr[left]);
    if(left == right){
        left = -1;
        right=-1;
    }
    else if(left == MAX-1)
        left = 0;
    else
        left = left+1;
}
void delete_right(){
    if (left == -1){
        printf("\nQueue Underflow\n");
        return;
    }
    printf("\nElement deleted from queue is : %d\n",deque_arr[right]);
    if(left == right){
        left = -1;
        right=-1;
    }
    else if(right == 0)
        right=MAX-1;
    else
        right=right-1;
}
void display_queue(){
    int front_pos = left, rear_pos = right;
    if (left == -1){
        printf ("\nQueue is empty\n");
        return;
    }
    printf ("\nQueue elements :\n");
    if ( front_pos <= rear_pos ){
        while(front_pos <= rear_pos){
            printf ("%d ",deque_arr[front_pos]);
            front_pos++;
        }
    }
    else{
        while(front_pos <= MAX-1){
            printf("%d ",deque_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos){
            printf ("%d ",deque_arr[front_pos]);
            front_pos++;
        }
    }
    printf ("\n");
}
void input_que(){
    int choice;
    while(1){
        printf ("\n1.Insert at right\n");
        printf ("2.Insert at left\n");
        printf ("3.Delete from left\n");
        printf ("4.Delete from right\n");
        printf ("5.Display\n");
        printf ("6.Quit\n");
        printf ("\nEnter your choice : ");
        scanf ("%d",&choice);
        switch(choice){
            case 1:
                insert_right();
                break;
            case 2:
                insert_left();
            case 3:
                delete_left();
                getch();
                break;
            case 4:
                delete_right();
                getch();
                break;
            case 5:
                display_queue();
                getch();
                break;
            case 6:
                exit(0);
            default:
                printf("\nWrong choice\n");
                getch();
        }
    }
}
void output_que(){
    int choice;
    while(1){
        printf ("\n1.Insert at right\n");
        printf ("2.Insert at left\n");
        printf ("3.Delete from left\n");
        printf ("4.Display\n");
        printf ("5.Quit\n");
        printf ("\nEnter your choice:");
        scanf ("%d",&choice);
        switch(choice){
            case 1:
                insert_right();
                break;
            case 2:
                insert_left();
                break;
            case 3:
                delete_left();
                getch();
                break;
            case 4:
                display_queue();
                getch();
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong choice\n");
                getch();
        }
    }
}
void main(){
    int choice;
    printf ("\n1.Input restricted dequeue\n");
    printf ("2.Output restricted dequeue\n");
    printf ("Enter your choice:");
    scanf ("%d",&choice);
    switch(choice){
        case 1:
            input_que();
            break;
        case 2:
            output_que();
            break;
        default:
            printf("\nWrong choice\n");
    }
}
