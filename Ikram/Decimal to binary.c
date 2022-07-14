#include<stdio.h>
#define max 50
void push(int a);
int stack[max];
    int top=-1;


int main(){

     int b,counter=0;
    int value,poped=0;
    printf("Enter any value\n");
    scanf("%d",&value);
    int a;
    for(a=0;a<max;a++)
   {
       b=value%2;
    value=value/2;
    push(b);
    counter++;
    if(value==0)
        break;
   }
   for(a=0;a<c;a++)
   {
       poped=pop();
       printf("%d",poped);
   }

}
void push(int a)
{
    if(top==max-1)
    {

        printf("Stack overflow");

    }
    else
    {
        top++;
    }
    stack[top]=a;
}

int pop()
{
    int value;
    if(top==-1)
    {
        printf("\nUnderflow\n");
    }
    else{
       value=stack[top];
       top--;
    }
    return value;
}
