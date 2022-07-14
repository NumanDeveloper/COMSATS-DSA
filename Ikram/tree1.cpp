#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
#include<stdio.h>
#define M 5
struct node{
	int n;
	int keys[M-1]; 
	struct node *p[M];
}*root=NULL;

typedef struct node *NODE;
enum KeyStatus {Duplicate,SearchFailure,Success,InsertIt,LessKeys};
void insert(int key);
void display(NODE root,int);
void DelNode(int x);
void search(int x);
enum KeyStatus ins(NODE r, int x, int* y, NODE * u);
int searchPos(int x,int *key_arr, int n);
enum KeyStatus del(NODE r, int x);
int main(){
	int key;
	int choice;
	while(1){
	printf ("\n1.Insert\n");
	printf ("2.Delete\n");
	printf ("3.Search\n");
	printf ("4.Display\n");
	printf ("5.Quit\n");
	printf ("\nEnter your choice : ");
	scanf ("%d",&choice);
	switch(choice){
		case 1:
			printf ("\nEnter the key : ");
			scanf ("%d",&key);
			insert(key);
			break;
		case 2:
			printf ("\nEnter the key : ");
			scanf ("%d",&key);
			DelNode(key);
			break;
		case 3:
			printf ("\nEnter the key : ");
			scanf ("%d",&key);
			search(key);
			getch();
			break;
		case 4:
			printf ("\nBtree is :\n");
			display(root,0);
			getch();
			break;
		case 5:
			exit(1);
		default:
			printf ("\nWrong choice\n");
			getch();
			break;
		}
	}
}
void insert(int key){
	NODE newnode;
	int upKey;
	enum KeyStatus value;
	value = ins(root, key, &upKey, &newnode);
	if (value == Duplicate){
		printf("\nKey already available\n");
		getch();
	}
	if (value == InsertIt){
		NODE uproot = root;
		root=(NODE)malloc(sizeof(struct node));
		root->n = 1;
		root->keys[0] = upKey;
		root->p[0] = uproot;
		root->p[1] = newnode;
	}
}
enum KeyStatus ins(NODE ptr, int key, int *upKey,NODE *newnode){
	NODE newPtr,lastPtr;
	int pos, i, n,splitPos;
	int newKey, lastKey;
	enum KeyStatus value;
	if (ptr == NULL){
		*newnode = NULL;
		*upKey = key;
		return InsertIt;
	}
	n = ptr->n;
	pos = searchPos(key, ptr->keys, n);
	if (pos < n && key == ptr->keys[pos])
		return Duplicate;
	value = ins(ptr->p[pos], key, &newKey, &newPtr);
	if (value != InsertIt)
		return value;
	if (n < M - 1){
		pos = searchPos(newKey, ptr->keys, n);
		for (i=n; i>pos; i--){
			ptr->keys[i] = ptr->keys[i-1];
			ptr->p[i+1] = ptr->p[i];
		}
		ptr->keys[pos] = newKey;
		ptr->p[pos+1] = newPtr;
		++ptr->n;
		return Success;
	}
	if (pos == M - 1){
		lastKey = newKey;
		lastPtr = newPtr;
	}
	else{
		lastKey = ptr->keys[M-2];
		lastPtr = ptr->p[M-1];
		for (i=M-2; i>pos; i--){
			ptr->keys[i] = ptr->keys[i-1];
			ptr->p[i+1] = ptr->p[i];
		}
		ptr->keys[pos] = newKey;
		ptr->p[pos+1] = newPtr;
	}
	splitPos = (M - 1)/2;
	(*upKey) = ptr->keys[splitPos];
	(*newnode)=(NODE)malloc(sizeof(struct node));
	ptr->n = splitPos;
	(*newnode)->n = M-1-splitPos;
	for (i=0; i < (*newnode)->n; i++){
		(*newnode)->p[i] = ptr->p[i + splitPos + 1];
		if(i < (*newnode)->n - 1)
			(*newnode)->keys[i] = ptr->keys[i + splitPos + 1];
		else
			(*newnode)->keys[i] = lastKey;
	}
	(*newnode)->p[(*newnode)->n] = lastPtr;
	return InsertIt;
}

void display(NODE ptr, int blanks){
	if (ptr){
		int i;
		for(i=1;i<=blanks;i++)
			printf (" ");
		for (i=0; i < ptr->n; i++)
			printf ("%d ",ptr->keys[i]);
			printf ("\n");
		for (i=0; i <= ptr->n; i++)
			display(ptr->p[i], blanks+10);
	}
}
void search(int key){
	int pos, i, n;
	NODE ptr = root;
	printf ("\nSearch path:\n");
	while (ptr){
		n = ptr->n;
		for (i=0; i < ptr->n; i++)
			printf (" %d",ptr->keys[i]);
			printf ("\n");
			pos = searchPos(key, ptr->keys, n);
		if (pos < n && key == ptr->keys[pos]){
			printf ("\nKey %d found in position %d of last dispalyed node\n",key,i);
			return;
		}
		ptr = ptr->p[pos];
	}
	printf ("\nKey %d is not available\n",key);
}
int searchPos(int key, int *key_arr, int n){
	int pos=0;
	while (pos < n && key > key_arr[pos])
		pos++;
	return pos;
}
void DelNode(int key){
	NODE uproot;
	enum KeyStatus value;
	value = del(root,key);
	switch (value){
		case SearchFailure:
			printf("\nKey %d is not available\n",key);
			break;
		case LessKeys:
			uproot = root;
			root = root->p[0];
			free(uproot);
			break;
	}
}
enum KeyStatus del(NODE ptr, int key){
	int pos, i, pivot, n ,min;
	int *key_arr;
	enum KeyStatus value;
	NODE *p,lptr,rptr;
	if (ptr == NULL)
		return SearchFailure;
	n=ptr->n;
	key_arr = ptr->keys;
	p = ptr->p;
	min = (M - 1)/2;
	pos = searchPos(key, key_arr, n);
	if (p[0] == NULL){
		if (pos == n || key < key_arr[pos])
			return SearchFailure;
		for (i=pos+1; i < n; i++){
			key_arr[i-1] = key_arr[i];
			p[i] = p[i+1];
		}
		return --ptr->n >= (ptr==root ? 1 : min) ? Success : LessKeys;
	}
	if (pos < n && key == key_arr[pos]){
		struct node *qp = p[pos], *qp1;
		int nkey;
		while(1){
			nkey = qp->n;
			qp1 = qp->p[nkey];
			if (qp1 == NULL)
				break;
			qp = qp1;
		}
		key_arr[pos] = qp->keys[nkey-1];
		qp->keys[nkey - 1] = key;
	}
	value = del(p[pos], key);
	if (value != LessKeys)
		return value;
	if (pos > 0 && p[pos-1]->n > min){
		pivot = pos - 1;
		lptr = p[pivot];
		rptr = p[pos];
		rptr->p[rptr->n + 1] = rptr->p[rptr->n];
		for (i=rptr->n; i>0; i--){
			rptr->keys[i] = rptr->keys[i-1];
			rptr->p[i] = rptr->p[i-1];
		}
		rptr->n++;
		rptr->keys[0] = key_arr[pivot];
		rptr->p[0] = lptr->p[lptr->n];
		key_arr[pivot] = lptr->keys[--lptr->n];
		return Success;
	}
	if (pos<n && p[pos+1]->n > min){
		pivot = pos;
		lptr = p[pivot];
		rptr = p[pivot+1];
		
		lptr->keys[lptr->n] = key_arr[pivot];
		lptr->p[lptr->n + 1] = rptr->p[0];
		key_arr[pivot] = rptr->keys[0];
		lptr->n++;
		rptr->n--;
		for (i=0; i < rptr->n; i++){
			rptr->keys[i] = rptr->keys[i+1];
			rptr->p[i] = rptr->p[i+1];
		}
		rptr->p[rptr->n] = rptr->p[rptr->n + 1];
		return Success;
	}
	if(pos == n)
		pivot = pos-1;
	else
		pivot = pos;
		lptr = p[pivot];
		rptr = p[pivot+1];
		lptr->keys[lptr->n] = key_arr[pivot];
		lptr->p[lptr->n + 1] = rptr->p[0];
		for (i=0; i < rptr->n; i++){
			lptr->keys[lptr->n + 1 + i] = rptr->keys[i];
			lptr->p[lptr->n + 2 + i] = rptr->p[i+1];
		}
		lptr->n = lptr->n + rptr->n +1;
		free(rptr); 
		for (i=pos+1; i < n; i++){
			key_arr[i-1] = key_arr[i];
			p[i] = p[i+1];
		}
		return --ptr->n >= (ptr == root ? 1 : min) ? Success : LessKeys;
}
