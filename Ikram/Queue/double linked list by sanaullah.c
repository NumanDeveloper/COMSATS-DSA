#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* start=NULL;
struct node* p;
struct node* q;
struct node* r;
void insert_left();
void del_left();
void display();
void del_rig();
void insert_rig();
void insert_spec();
void del_spec();
int main()
{
	int val,choice=88;
	while(choice!=-1) 
	{
		printf("\nPlease select your choice\n1 To add left\n2 To delete left\n3 To add right\n4 To delete right\n5 To display\n");
		printf("6 to insert at specific\n7 to delete from specific\t");		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_left();
				break;
			case 2:
				del_left();
				break;
			case 3:
				insert_rig();
				break;
			case 4:
				del_rig();
				break;
			case 5:
				display();
				break;
			case 6:
				insert_spec();
				break;
			case 7:
				del_spec();
				break;
			default:
				printf("Invalid Selection...!!\n");	
		}
	}
}
void insert_spec()
{
	p=(struct node*)malloc(sizeof(struct node*));
	q=(struct node*)malloc(sizeof(struct node*));
	int pos,i;
	printf("Enter the position where you want to insert the value :");
	scanf("%d",&pos);
	printf("Enter value to insert at %d position : ",pos);
	scanf("%d",&p->data);
	q=start;
	for(i=0;i<=pos;i++)
	{
		if(i==pos-1)
		{
			p->next=q;
			p->prev=q->prev;
			q->prev=p;
			(p->prev)->next=p;
			display();
			return;
		}
		q=q->next;
	}
/*	q->next=p;
	p->prev=q;
	p->next=r;
	r->prev=p;*/
	
}
void insert_rig()
{
	p=(struct node*)malloc(sizeof(struct node*));
	q=(struct node*)malloc(sizeof(struct node*));
	printf("Insert at right side :");
	scanf("%d",&p->data);
	if(start==NULL)
	{
		p->next=NULL;
		p->prev=NULL;
		start=p;
	}
	else
	{
		p->next=NULL;
		q=start;
		while(q->next!=NULL)
		{
			p->prev=q;
			q=q->next;
		}
		q->next=p;
	}
}
void del_spec()
{
	p=(struct node*)malloc(sizeof(struct node*));
	q=(struct node*)malloc(sizeof(struct node*));
	r=(struct node*)malloc(sizeof(struct node*));
	int i,ch,pos;
	if(start==NULL)
	{
		printf("List is already empty..!\n");
		return;
	}
	else
	{
		printf("press 1 to del via value\npress 2 to del via node number :\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter value to delete :");
				scanf("%d",&p->data);
				q=start;
				while(q!=NULL)
				{
					if(p->data==q->data)
					{
						printf("%d has been removed from the list\n\n",p->data);
						(q->prev)->next=q->next;
						(q->next)->prev=q->prev;		
						free(q);
						display();
						return;
					}
					q=q->next;
				}
				break;
			case 2:
				printf("Enter node number to delete : ");
				scanf("%d",&pos);
				q=start;
				for(i=1;i<=pos+1;i++)
				{
					if(i==pos)
					{
						(q->prev)->next=q->next;
						(q->next)->prev=q->prev;
						printf("\n%d has been removed\n\n",q->data);		
						free(q);
						display();
						return;
					}
					q=q->next;
				}
				break;
		}
		
	}
}
void del_rig()
{
	p=(struct node*)malloc(sizeof(struct node*));
	q=(struct node*)malloc(sizeof(struct node*));
	q=start;
	if(start==NULL)
	{
		printf("List is empty...!!\n\n");
		return;
	}
	else
	{
		
		while(q->next!=NULL)
		{
			p=q;
			q=q->next;
		}
		p->next=NULL;
		printf("%d has been removed\n\n",q->data);
		free(q);
	}
}
void insert_left()
{
	p=(struct node*)malloc(sizeof(struct node*));
	printf("Enter value to insert :");
	scanf("%d",&p->data);
	if(start==NULL)
	{
		p->next=NULL;
		p->prev=NULL;
		start=p;
	}
	else
	{
		start->prev=p;
		p->next=start;
		start=p;
	}
}
void del_left()
{
	p=(struct node*)malloc(sizeof(struct node*));
	p=start;	
	if(start==NULL)
	{
		printf("List is empty...!!\n\n");
		return;
	}
	else
	{
		start=start->next;
		printf("%d has been removed\n\n",p->data);
		free(p);
	}
}
void display()
{
	printf("\nList is :\n");
	p=(struct node*)malloc(sizeof(struct node*));
	p=start;
	if(start==NULL)
	{
		printf("List is empty...!!\n\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n\n");
} 
