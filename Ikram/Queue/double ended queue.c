#include<stdio.h>
#include<string.h>
#define max 5
char queue[max];
void insert_rear(char ch);
void insert_front(char ch);
char delet_front();
char delet_rear();
void Exit();
void display();
int f=-1;
int r=-1;
int main()
{
    char ch,a[max];
    int i=0,c=0;
    for(;;)
    {
        printf("\n 1.  Insert from rear \n 2. insert from front \n 3. Delete from front \n 4. delete from rear \n 5. Display \n 6. Exit   ");
        printf("\n Enter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case  1:
            {
                fflush(stdin);
                printf("\n Enter The char in queue : ");
                scanf("%c",&ch);
                insert_rear(ch);
                break;
            }
        case 2:
            {
                fflush(stdin);
                printf("\n Enter The char in queue : ");
                scanf("%c",&ch);
                insert_front(ch);
                break;
            }
        case 3:
            {
                delet_front();
                break;
            }
        case 4:
            {
                delet_rear();
                break;
            }
        case 5:
            {
                display();
                break;
            }
        case 6:
            {
                Exit();
            }
        }
    }
}
void insert_rear(char ch)
{
    if((f==0 && r==max-1)||(f==r+1))
    {
        printf("\n Over Flow !!!!!!!!");
    }
    else
    {
        if(r==-1&&f==-1)
        {
            f=0;
            r=0;
        }
        else if(r==max-1&&f!=0)
        {
            r=0;
        }
        else
        {
            r++;
        }
    }
    queue[r]=ch;
}
void insert_front(char ch)
{
    if((f==0 && r==max-1)||(f==r+1))
    {
        printf("\n Over Flow !!!!!!!!");
    }
    else
    {
        if(r==-1&&f==-1)
        {
            f=0;
            r=0;
        }
        else if(f==0&&r!=max-1)
        {
            f=max-1;
        }
        else
        {
            f--;
        }
    }
    queue[f]=ch;

}
char delet_front()
{
    char ch;
    ch=queue[f];
    if(r==-1&&f==-1)
    {
        printf("\n Under flow!!!!!");
    }
    if(r==f)
    {
        r=-1;
        f=-1;
    }
    else if(f==max-1)
    {
        f=0;
    }
    else
    {
        f++;
    }
    return (ch);
}
char delet_rear()
{
    char ch;
    ch=queue[r];
    if(r==-1&&f==-1)
    {
        printf("\n Under flow!!!!!");
    }
    if(r==f)
    {
        r=-1;
        f=-1;
    }
    else if(r==0)
    {
        r=max-1;
    }
    else
    {
        r--;
    }
    return (ch);
}
void display()
{
    int i,j;
    if(f==-1&&r==-1)
    {
        printf("Queue is empty\n");
    }
    if(f>r)
    {
        for(i=0;i<=r;i++)
            printf("%c",queue[i]);
        for(j=f;j<=max-1;j++)
            printf("%c",queue[j]);
        printf("\nrear is at %c\n",queue[r]);
        printf("\n R = %d",r);
        printf("\nfront is at %c\n",queue[f]);
        printf("\n F = %d",f);
    }
    else
    {
        for(i=f;i<=r;i++)
        {
            printf("%c",queue[i]);
        }
        printf("\nrear is at %c\n",queue[r]);
              printf("\n R = %d",r);
        printf("\nfront is at %c\n",queue[f]);
        printf("\n F = %d",f);
    }
    printf("\n");
}
void Exit()
{
    exit(0);
}
