#include<stdio.h>
#include<malloc.h>
struct node{
	int info;
	node *next;
};
node *start = NULL;
void insertionAtStart(int value){
	node *p = (node*) malloc(sizeof(node));
	if(start == NULL){
		p->info = value;
		p->next = NULL;
		start = p;
	}
	else{
		p->info = value;
		p->next = start;
		start = p;
	}
}
void deletionAtStart(){
	if(start == NULL){
		printf("\nEmpty!");
	}
	else{
		node *q = (node*) malloc(sizeof(node));
		q = start;
		start = q->next;
		free(q);
	}
}
void display(){
	node *n;
	n = start;
	while(n != NULL){
		printf("\nValue : %d", n->info);
		n = n->next;
	}
	printf("\n\n");
}
void rev(){
	node *p=NULL, *q=start, *r=q->next;
	while(q != NULL){
		q->next = p;
		p = q;
		q = r;
		if(r != NULL)
			r = r->next;
	}
	start = p;
}
int main(){
	int a=1;
	scanf("%d",&a);
	for(;a!=0;){
        insertionAtStart(a);
        scanf("%d",&a);
	}
	display();
	//rev();
	//display();

	return 0;
}
