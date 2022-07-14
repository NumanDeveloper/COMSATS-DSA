#include<stdio.h>
#include<string.h>
#define max 5
char queue[max];
void insert(char ch);
char delet();
void display();
int f=-1;
int r=-1;
int main()
{
    char ch,a[max];
    char arr[max];
    int i=0,c=0;
    for(;;)
    {
        printf("\n 1.  Insert \n 2. Delet \n 3. Display \n 4. Exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case  1:
            {
                fflush(stdin);
                printf("\n Enter The char in queue : ");
                //scanf("%c",&ch);
                gets(arr);
                fflush(stdin);
                for(i=0;i<strlen(arr);i++)
                {
                    ch=arr[i];
                    insert(ch);
                }

                break;
            }
        case 2:
            {
                delet();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                Exit();
            }
        }
    }
}
void insert(char ch)
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
char delet()
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
        //printf("\nrear is at %c\n",queue[r]);
       // printf("\nfront is at %c\n",queue[f]);
    }
    else
    {
        for(i=f;i<=r;i++)
        {
            printf("%c",queue[i]);
        }
       // printf("\nrear is at %c\n",queue[r]);
       // printf("\nfront is at %c\n",queue[f]);
    }
    printf("\n");
}
void Exit()
{
    exit(0);
}
//Displaying the queue elements
/*End of else*/
