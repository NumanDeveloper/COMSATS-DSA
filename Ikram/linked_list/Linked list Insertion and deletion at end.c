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
void insert(int a)
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
void Display()
{
    struct node *h;
    h=start;
    while(h!=NULL)
    {
    printf("\t%d",h->info);
    h=h->next;
    }
}
int Delete()
{
int value;
    if(start==NULL)
    {
    printf("List is Empty");
    }
    else
    {
    q=start;
    p=start->next;
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    q->next=NULL;
    //start = start->next;
    value=p->info;
    free(p);
    return value;
    }

}

int main()
{
    int input;
    int i;
    int c;
    for(;;)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&c);
             switch(c)
    {
    case 1:
        {
    printf("Please enter any value\n");
    scanf("%d",&input);
    insert(input);
    break;
        }
    case 2:
        {
            Delete();
            break;
        }
    case 3:
        {
            Display();
            break;
        }
    case 4:
        {
            exit(0);
            break;
        }

    }
    }




}

