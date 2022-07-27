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
        while(q->next!=NULL){
        q=q->next;}
        p = (struct node*)malloc(sizeof(struct node));
        p->info=a;
        p->next=NULL;
        q->next=p;
    }


}

void sorting_in_ascending()
{
    int a;
        if(start==NULL)
    {
        printf("\nLinked list is empty\n");
    }

    else
    {
        p=start;
        while(p!=NULL)
        {
            q=p->next;
            while(q!=NULL)
            {
                if(p->info>q->info)
                {
                a=p->info;
                p->info=q->info;
                q->info=a;
                }
                q=q->next;
            }
            p=p->next;
        }
    }

}
void Display()
{
        struct node *h;
        h=start;
            if(start==NULL)
            {
                printf("\nlist is empty\n");
            }
            else{
                while(h!=NULL)
                {
                    printf("\t %d",h->info);
                    h=h->next;
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
        printf("\n1.Insert at End\n2.sorting in ascending order\n3.Display\n");
        scanf("%d",&c);
             switch(c)
        {
            case 1:
            {
                printf("Please enter any value\n");
                scanf("%d",&input);
                insert_at_End(input);
                break;
            }
            case 2:
            {
                sorting_in_ascending();
                break;
            }
            case 3:
            {
                Display();
                break;
            }

        }
    }

}
