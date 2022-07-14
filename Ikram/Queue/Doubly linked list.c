#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
   struct node *next;
    struct node *prev;
};

struct node *start ;
struct node *p;
struct node *q;
struct node *t;
struct node *temp;


void insert_at_Start(int a)
{
    int s;
    if(start==NULL)
    {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info = a;
        p->next = NULL;
        p->prev = NULL;
        start=p;

    }
    else
    {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info=a;
        p->next=start;
        p->prev = NULL;
        (p->next)->prev=p;
        start=p;
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
        p->prev = NULL;
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
        p->prev=q;
        (p->prev)->next = p;
        q->next=p;
    }


}


void Insertion_at_position(int po,int v)
{
    /*if(po==0||po==1)
    {
        printf("\n not possible\n");
    }
      if(po==2)
    {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info=v;
        p->next=start;
        start=p;
    }
    else*/
    {
           /* if((start==NULL)||(po==1))
        {
        //p =  (struct node*)malloc(sizeof(struct node));
       // p->info = v;
       // p->next = NULL;
       // start=p;
       insert_at_Start(v);


        }*/

        {
        int i=0;
        q=start;

        while((i<po)&&(q!=NULL))
        {
           if(i==po-1)
            {
                 p =  (struct node*)malloc(sizeof(struct node));
                p->info=v;
                p->next=q;
                p->prev=q->prev;
                //q->prev=p;
                (p->next)->prev=p;
                if(po!=1)
                {
                   (p->prev)->next=p;
                }
                else{
                   start=p;
                }

                break;
            }
        /*p =  (struct node*)malloc(sizeof(struct node));
        p->info=a;
        p->next=start;
        p->prev = NULL;
        (p->next)->prev=p;*/

           // else{

            //}
            q=q->next;
            i++;
        }
        if(q==NULL)
        {
            insert_at_End(v);
        }

        }
}



}
void Delete_at_Start()
{
    if(start==NULL)
    {
        printf("\nLinked list is Empty\n");
    }
    else{

        q=start;
        start=q->next;
        if(start!=NULL)
        {
            start->prev=NULL;
        }

        free(q);


    }

}
void Delete_at_End()
{
    q=start;
    //p=start;
    if(start==NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        if(q->next == NULL)
		{
			start = NULL;
			free(q);
		}




        else
        {
         while(q->next!=NULL)
        {
            q=q->next;

        }
        /*if(q->prev == NULL)
        {

           start == NULL;

        }*/

            (q->prev)->next = NULL;

             printf("\n%d\n",(q->prev)->info);

        free(q);
        }


    }

}
void delete_at_specific(int po)
{
    p=start;
    q=start;

    if(start == NULL)
	{
		printf("\nempty!");
	}
	else
    {
            if(po==1)
            {
                    if(po==1&&q->next!=NULL)
                {

                    start=q->next;
                    free(q);

                }
                else
                {
                    start = NULL;
                    free(q);
                }
            }






            else
                {
                int i=0;
                q=q->next;
                while((i<po)&&(q!=NULL))
                {
                    if(i==po-2)
                    {
                    p->next=q->next;
                    (q->next)->prev=p;
                    free(q);
                    break;
                    }

                q=q->next;
                p=p->next;
                i++;
                    }
                }

    }




}
/*void local()
{   start->next = NULL;
    printf("\n%d\n",*(start->next));
}*/


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
        while(p!=NULL)
        {
            q=p->next;
            while(q!=NULL)
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
void Delete_Duplicate()
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
                if(p->info==q->info)
                {
                temp=q;
                q=q->next;
                free(temp);
                p->next=q;
                q->prev=p;

                }
                else{
                   q=q->next;
                }

            }
            p=p->next;
        }
    }

}




void Display()
{
    struct node *h;
   // struct node *i;
    h=start;
    //h=h->next;
    //i=start;

    if(start == NULL)
    {
        printf("\nlist is empty\n");
    }
    else{
    while(h != NULL)
    {
    printf("\t %d",h->info);
    h=h->next;
    }


    }

}
int main()
{
    int c;
    int input;


    for(;;)
    {
            printf("\n1. Insert at start\n2. insert at specific position\n3. Insert at end\n4. Delete at start\n5.Delete at End\n6.delete at specific position\n7. Display\n8.Reverse\n9.Delete Duplicate\n10.Exit\n");
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
    case 7:
        {
            Display();
            break;
        }
        case 2:
        {
             int p=0,v=0;
            printf("\nEnter position to add value\n");
            scanf("%d",&p);
            printf("\nEnter value to add in node\n");
            scanf("%d",&v);
            Insertion_at_position(p,v);
            break;
        }
    case 3:
        {
            printf("Please enter any value\n");
            scanf("%d",&input);
            insert_at_End(input);
            break;
        }
    case 4:
        {
            Delete_at_Start();
            break;
        }
    case 5:
        {
            Delete_at_End();
            break;
        }
    case 6:
        {
            int posi;
            printf("\nEnter position to remove value\n");
            scanf("%d",&posi);
            delete_at_specific(posi);
            break;
        }
    case 8:
        {
            Reverse();
            break;
        }
    case 9:
        {
            Delete_Duplicate();
            break;
        }
    case 10:
        {
            exit(0);
            break;
        }

    }

    }

}
