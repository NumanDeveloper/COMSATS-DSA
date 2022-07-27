


#include<stdio.h>
#include<malloc.h>

struct node
{
    int info;
   struct node *next;

};
struct node *start ;
struct node *p;
struct node *q;
struct node *t;
struct node *u;
struct node *temp;





void insert_at_Start(int a)
{
    int s;
    if(start==NULL)
    {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info = a;
        p->next = NULL;

        start=p;
         t=start;
        printf("\n%d \n",*(t));

    }
    else
    {   printf("\n%d \n",*(t));
        p =  (struct node*)malloc(sizeof(struct node));
        p->info=a;
        p->next=start;
        start=p;
        t->next=p;
        printf("\n%d \n",*(t->next));

        }

}
void insert_at_End(int a)
{

    int s;
    if(start==NULL)
    {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info = a;
        p->next = NULL;
        start=p;

    }
    else
    {
        q=start;
        /*if(q->next==NULL)
        {
        p = (struct node*)malloc(sizeof(struct node));
        p->info=a;
        p->next=q;
        q->next=p;
        }
        else*/{
          while(q->next!=start){
        q=q->next;}
        p = (struct node*)malloc(sizeof(struct node));
        p->info=a;
        p->next=start;
        q->next=p;
        }

    }


}


void Reverse()
{
    int a;
        if(start==NULL)
    {
        printf("\nLinked list is empty\n");
    }

    else
    {
        p=start;
        q=p->next;
        while(q!=start)
        {
                a=p->info;
                p->info=q->info;
                q->info=a;
                q=q->next;
        }

        //p=start;
        p=p->next;
        while(p!=start)
        {
            q=p->next;
            while(q!=start)
            {
                //if(p->info>q->info)
                //{
                a=p->info;
                p->info=q->info;
                q->info=a;
                //}
                q=q->next;
            }
            p=p->next;
        }
    }

}

void Display()
{
    struct node *h;
     struct node *i;
    h=start;
    i=start;
    if(start==NULL)
    {
        printf("\nlist is empty\n");
    }
    else{
            if(start->next==NULL)
            {
              printf("\t %d",h->info);
            }
            else
            {
                while(h->next!=i)
                {
                printf("\t %d",h->info);
                h=h->next;
                }
                printf("\t %d",h->info);
            }



    }

}

int main()
{
     int input;
    int i;
    int c;
    for(;;)
    {
        printf("\n1.Insert at start\n3.Insert at End\n5.Display\n6.Reverse\n7.Exit\n");
        scanf("%d",&c);
             switch(c)
    {
    case 1:
        {
    printf("Please enter any value\n");
    scanf("%d",&input);
   insert_at_Start(input);
    break;
        }
    case 3:
        {

             printf("Please enter any value\n");
            scanf("%d",&input);
            insert_at_End(input);
            break;
        }
    case 5:
        {
            Display();
            break;
        }
    case 6:
        {
            Reverse();
            break;
        }
    case 7:
        {
            exit(0);
        }

    }
    }

}
