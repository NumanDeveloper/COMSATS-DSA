#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *next;
};

struct node *start = NULL;

void insertion(int value)
{
	struct node *p = (struct node *) malloc(sizeof(struct node));
	
	if(start == NULL)
	{
		p->next =  NULL;
		p->info = value;
		start = p;	
	}
	
	else
	{
		p->next = start;
		p->info = value;
		start = p;
	}
}

void odd_even()
{
	struct node *oddStart=NULL, *evenStart=NULL, *oddEnd=NULL, *evenEnd=NULL, *current=start;
	
	while(current != NULL)
	{
		if(current->info % 2 == 0)
		{
			if(evenStart == NULL)
			{
				evenStart = current;
				evenEnd = current;
			}
			
			else
			{
				evenEnd->next = current;
				evenEnd = current;
			}
		}
		
		else
		{
			if(oddStart == NULL)
			{
				oddStart = current;
				oddEnd = current;
			}
			
			else
			{
				oddEnd->next =current;
				oddEnd = current;
			}
		}
	
		current = current->next;
	}
	
	start = oddStart;
	oddEnd->next = evenStart;
	evenEnd->next = NULL;
}

void display()
{
	struct node *n=start;
	
	while(n!=NULL)
	{
		printf("\nValue : %d", n->info);
		n= n->next;
	}
}

int main()
{
	insertion(4);
	insertion(3);
	insertion(2);
	insertion(1);

	
	printf("List before sorting : ");
	display();
	
	odd_even();
	
	printf("\n\nAfter odd_even sorting: ");
	display();
	
	return 0;
}
