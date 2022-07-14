#include<stdio.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *right;
    struct node *left;
};
struct node *start;
struct node *p;
struct node *q;
struct node *t;

void insert_at_Start(int a)
{
    int s;
    if(start==NULL)
    {
        p =  (struct node*)malloc(sizeof(struct node));
        p->info = a;
        p->right = NULL;
        p->left = NULL;
        start=p;
        t=p;

    }
    else
    {
         q=start;

    while((q->left!=NULL) && (q->right!=NULL))
           //while(q->left!=NULL)
    {
        if(q->info>a)
        {

            q=q->left;
           // p=p->left;
        }
        else
        {

            q=q->right;
            //p=p->right;
        }

    }
                if(q->info>a)
                {
                    p =  (struct node*)malloc(sizeof(struct node));
                    p->info=a;
                    p->right = NULL;
                    p->left = NULL;
                    q->left=p;
                }
                else
                {
                    p =  (struct node*)malloc(sizeof(struct node));
                    p->info=a;
                    p->right = NULL;
                    p->left = NULL;
                    q->right=p;

                }
    }

}


/*void Display()
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
    while(h->right != NULL)
    {
    printf("\t %d",h->info);
    h=h->right;
    }

        while(h->left != NULL)
    {
    printf("\t %d",h->info);
    h=h->left;
    }

    }

}*/
void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
        printf("%d ", r->info);
        inOrder(r->right);
    }
}

void preOrder(struct node* r)
{
    if(r!=NULL){
        printf("%d ", r->info);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->info);

    }
}
int main()
{

    int c;
    int input;


    for(;;)
    {
            printf("\n1. Insertion\n5.Exit\n");
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
    /*case 2:
        {
            Display();
            break;
        }*/
    case 5:
        {
            exit(0);
            break;
        }
    case 6:
        {
            printf(" Inorderd Traversal: ");
            inOrder(start);
            printf("\n");
            break;
            }
    case 3:
        {
            printf("Preorder Traversal: ");
            preOrder(start);
            printf("\n");
            break;
        }
    case 4:
        {
         printf("Postorder Traversal: ");
            postOrder(start);
            printf("\n");
            break;
        }






    }
    }
}
