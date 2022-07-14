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
struct node *a;
struct node *j;
struct node *k;
struct node *even;
struct node *odd;

//struct start = NULL;

void insert_at_Start(int a)
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
        p =  (struct node*)malloc(sizeof(struct node));
        p->info=a;
        p->next=start;
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
void Sorting_positioned_node()
{

  a=start;


        if((a->info)%2==0)
        {
          j=a;
           printf("\n%d",a->info);
          //k=a->next;

           while(a!=NULL)
            {
                if((a->info)%2!=0)
                {
                    odd=a;
                    break;
                }
                a=a->next;
            }

        }
                k=odd;


            //j->next = odd;
            //k->next = NULL;


               // a=odd;
               a=start;
                 printf("\n odd->info    %d",a->info);
                a=a->next;
            while(a!=NULL)
            {
                if((a->info)%2==0)
                {

                        j->next=a;
                     (j->next)->info=a->info;
                     printf("\n even->info    %d",a->info);
                   /* k->next = a;
                    (k->next)->info=a->info;
                     printf("\n odd->info    %d",a->info);*/
                }
                a=a->next;
            }
            j->next=odd;
            (j->next)->info=odd->info;
               /* else{


                }
                a=a->next;
            }
           j->next=odd;
           (j->next)->info=odd->info;*/



               /* a=start;
               // a=a->next;
            while(a!=NULL)
            {
              if((a->info)%2!=0)
                {

                   // j->next = a;

                }
                else{
                     printf("\n even %d",a->info);
                }
                a=a->next;
            }*/

           // j->next=odd;

}
       /* else{

            k=a;
           // j=a->next;
            while(a!=NULL)
            {
                if((a->info)%2==0)
                {
                    even=a;
                    break;
                }
                a=a->next;
            }
        }

          // printf("\n%d",a->info);


        else
        {


        }*/
        /*j=start;
        while(j!=NULL)
        {
            printf("\n%d",j->info);
            j=j->next;
        }*/
      //else{
       // k=a;
      //}


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


void Delete_at_End()
{
	//node *q = (node*) malloc(sizeof(node));
	q = start;

	//node *p = (node*) malloc(sizeof(node));
	p = start;

	if(start == NULL)
	{
		printf("\nempty!");
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
			q = q->next;

			while(q->next != NULL)
			{
				q = q->next;
				p = p->next;
			}

			p->next = NULL;
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


int Delete_at_Start()
{
int value;
    if(start==NULL)
    {
    printf("List is Empty");
    }
    else
    {
      struct node *q;
    q = start;
    start = start->next;
    value=q->info;
    free(q);
    return value;
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
void number()
{
    int i=0;

    if(start==NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        p=start;
        while(p!=NULL)
        {
            p=p->next;
            i++;
        }
        printf("\n %d nodes in linked list\n",i);
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

void sorting_in_descending()
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
                if(p->info<q->info)
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

void searching()
{
    int position,i=0;
    printf("\nEnter number to find position\n");
    scanf("%d",&position);

    if(start==NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
          p=start;
        while(p!=NULL)
        {
            if(p->info==position)
            {
                printf("\nNode at position %d\n",i+1);
            }
            i++;
            p=p->next;
        }
    }


}

void Insertion_after_position(int po,int v)
{
      if(po==0)
    {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info=v;
        p->next=start;
        start=p;
    }
    else
    {
            if(start==NULL)
        {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info = v;
        p->next = NULL;
        start=p;

        }
        else
        {
        int i=0;
        q=start;

        while((i<po)&&(q!=NULL))
        {
           if(i==po-1)
            {
                p =  (struct node*)malloc(sizeof(struct node));
                p->info=v;
                p->next=q->next;
                q->next=p;
            }
            q=q->next;
            i++;
        }

        }
    }



}
void Insertion_before_position(int po,int v)
{
    if(po==0||po==1)
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
    else
    {
            if(start==NULL)
        {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info = v;
        p->next = NULL;
        start=p;

        }
        else
        {
        int i=0;
        q=start;

        while((i<po)&&(q!=NULL))
        {
           if(i==po-3)
            {
                p =  (struct node*)malloc(sizeof(struct node));
                p->info=v;
                p->next=q->next;
                q->next=p;
            }
            q=q->next;
            i++;
        }

        }
    }



}

void Insertion_at_position(int po,int v)
{
      if(po==1)
    {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info=v;
        p->next=start;
        start=p;
    }
    else
    {
            if(start==NULL)
        {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info = v;
        p->next = NULL;
        start=p;

        }
        else
        {
        int i=0;
        q=start;

        while((i<po)&&(q!=NULL))
        {
           if(i==po-2)
            {
                p =  (struct node*)malloc(sizeof(struct node));
                p->info=v;
                p->next=q->next;
                q->next=p;
            }
            q=q->next;
            i++;
        }

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
        printf("\n1.Insert at start\n2.Delete at Start\n3.Insert at End\n4.Delete at End\n5.Display\n6.Find number of nodes\n7.sorting in ascending order\n8.sorting in descending order\n9.Find position of node by number\n10.Insert after specific position\n11.Insert before specific position\n12.Insert at specific position\n13.delete at specific position\n14.Exit\n15.Reverse\n");
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
    case 2:
        {
           Delete_at_Start();
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
            Delete_at_End();
            break;
        }
    case 5:
        {
            Display();
            break;
        }
    case 6:
        {
          number();
            break;
        }
    case 7:
        {
            sorting_in_ascending();
            break;
        }
    case 8:
        {
            sorting_in_descending();
            break;
        }
    case 9:
        {
            searching();
            break;
        }
    case 10:
        {
            int position=0,value=0;
            printf("\nEnter position to add value\n");
            scanf("%d",&position);
            printf("\nEnter value to add in node\n");
            scanf("%d",&value);
            Insertion_after_position(position,value);
            break;
        }

    case 12:
        {    int pos=0,val=0;
            printf("\nEnter position to add value\n");
            scanf("%d",&pos);
            printf("\nEnter value to add in node\n");
            scanf("%d",&val);
            Insertion_at_position(pos,val);
            break;
        }
    case 11:
        {
            int p=0,v=0;
            printf("\nEnter position to add value\n");
            scanf("%d",&p);
            printf("\nEnter value to add in node\n");
            scanf("%d",&v);
            Insertion_before_position(p,v);
            break;
        }
    case 14:
        {
            exit(0);
            break;
        }
    case 13:
        {
            int posi;
            printf("\nEnter position to remove value\n");
            scanf("%d",&posi);
            delete_at_specific(posi);
            break;
        }
    case 15:
        {
            Reverse();
            break;
        }

    case 20:
        {
            Sorting_positioned_node();
            break;
        }

    }
    }




}

