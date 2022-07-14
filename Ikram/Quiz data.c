#include<stdio.h>
#include<string.h>
#define size 9
void push1(int x);
int pop1();
int t1=-1;
void display();
void push2(int x);
int pop2();
int t2=size;
int array[size];
int i=0;
int main()
{
    int x,y;
    for(;;)
    {
        printf("\n 1. insert in stack 1 \n 2. insert in stack 2 \n 3. delete from stack 1 \n 4. delete from stack 2\n 5. Display1 \n 6. Exit");
        printf("\n Enter the Choice : ");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            {
                printf("\n Enter the value : ");
                scanf("%d",&y);
                push1(y);
                break;
            }
        case 2:
            {
                printf("\n Enter the value : ");
                scanf("%d",&y);
                push2(y);
                break;
            }
        case 3:
            {
                pop1();
                break;
            }
        case 4:
            {
                pop2();
                break;
            }
        case 5:
            {
                display();
                break;
            }
        case 6:
            {
                exit(0);
                break;
            }
        }
    }
}
void push1(int x)
{
    if(t1==size-1 || t2==(t1+1))
    {
        printf("\n Stack Over Flow!!!!");
    }
    else
    {
        t1++;
        array[t1]=x;
    }
}
void push2(int x)
{
    if(t2==0 || t1==(t2-1))
    {
        printf("\n Stack Over Flow!!!!");
    }
    else
    {
        t2--;
        array[t2]=x;
    }
}
int pop1()
{
    int val;
    if(t1==-1)
    {
        printf("\n Stack Under FLow!!!!");
    }
    else
    {
        val=array[t1];
        t1--;
        printf("\n %d is poped from stack1",val);
    }
    return (val);
}
int pop2()
{
    int val;
    if(t2==size-1)
    {
        printf("\n Stack Under FLow!!!!");
    }
    else
    {
        val=array[t2];
        t2++;
        printf("\n %d is poped from stack2",val);
    }
    return (val);

}
void display()
{
    int j=0;
    for(j=0;j<=t1;j++)
    {
        printf("%d",array[j]);
    }
    printf("\n");
    for(j=size;j>=t2;j--)
    {
        printf("%d",array[j]);
    }
}
