#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////////
void create();
void insertatf();
void insertatl();
void insertatn();
void deletef();
void deletel();
void deleteall();
void deleten();
void print();
////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node *link;
};
///////////////////////////////////////////////////////////////
struct node *t, *p, *r, *q, *head = 0;
int val, choice, count = 0, i = 1, n;
/////////////////////////////////////////////////////////////////
int main()
{
    while (1)
    {
        printf("\n1 : Create node\n2 : Print node \n3 : insert at first\n4 : insert at nth node\n5 : Delete first node\n6 : Delete last node\n7 : Delete nth node\n8 : Delete all \n\tChoice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            print();
            break;
        case 3:
            insertatf();
            break;
        case 4:
            insertatn();
            break;
        case 5:
            deletef();
            break;
        case 6:
            deletel();
            break;
        case 7:
            deleten();
            break;
        case 8:
            deleteall();
            break;
        default:
            printf("\ninvalid choice\n");
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////////
void create()
{
    printf("\nEnter value : ");
    scanf("%d", &val);
    if (head == NULL)
    {
        p = malloc(sizeof(struct node));
        p->link = NULL;
        p->data = val;
        head = p;
    }
    else
    {
        q = malloc(sizeof(struct node));
        q->data = val;
        q->link = NULL;
        p->link = q;
        p = q;
    }
    count++;
}
//////////////////////////////////////////////////////////////////////
void print()
{
    if (head == NULL)
        printf("\nLINKED LIST IS EMPTY ");
    else
    {
        printf("\nValues are : \n");
        r = head;
        while (r != NULL)
        {
            printf("=====");
            r = r->link;
        }
        printf("\n");
        r = head;
        while (r != NULL)
        {
            printf("| %d |", r->data);
            r = r->link;
        }
        printf("\n");
        r = head;
        while (r != NULL)
        {
            printf("=====");
            r = r->link;
        }
    }
}
//////////////////////////////////////////////////////////////////
void insertatf()
{
    printf("\nEnter value : ");
    scanf("%d", &val);
    q = malloc(sizeof(struct node));
    q->data = val;
    q->link = head;
    head = q;
    count++;
}
////////////////////////////////////////////////////////////////
void insertatn()
{
    printf("\nEnter value : ");
    scanf("%d", &val);
    i = 1;
    if (count > 2)
    {
        q = malloc(sizeof(struct node));
        r = head;
        printf("INSERT VALUE FROM 1 TO %d NODE", count);
        scanf("%d", &n);
        q->data = val;
        while (i != n - 1)
        {
            r = r->link;
            i++;
        }
        q->link = r->link;
        r->link = q;
    }
    else
        printf("you have only 1 node\n\n");
}
/////////////////////////////////////////////////////////////////////
void deletef()
{
    r = head;
    q = r->link;
    free(r);
    head = q;
    count--;
}
///////////////////////////////////////////////////////////////////
void deletel()
{
    r = head;
    while (r->link != NULL)
    {
        q = r;
        r = r->link;
    }
    q->link = NULL;
    free(r);
    p = q;
    count--;
}
///////////////////////////////////////////////////////////////////////////
void deleten()
{
    i = 1;
    if (count > 2)
    {
        r = head;
        printf("INSERT VALUE FROM 1 TO %d NODE", count);
        scanf("%d", &n);
        while (i != n)
        {
            q = r;
            r = r->link;
            i++;
        }
        q->link = r->link;
        free(r);
        count--;
    }
    else
        printf("\n\nyou have only 1 node");
}
/////////////////////////////////////////////////////////////////////
void deleteall()
{
    p = head;
    while (p != NULL)
    {
        q = p;
        p = p->link;
        free(q);
    }
    head = NULL;
    count = 0;
}
///////////////////////////////////////////////////////////////////////
