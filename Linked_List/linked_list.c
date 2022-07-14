#include <stdio.h>
#include <conio.h>
#include <malloc.h>
// This is the implementation of linked list
struct node
{
    int data;
    struct node *next;
};
struct node *ptr, *temp, *p;
int value, i, pos, count;
struct node *head = NULL; // empty list
void insert_at_start();
void insert_at_end();
void insert_at_index();
void delete_at_index();
void print_list();

void insert_at_start()
{
    printf("Enter value: ");
    scanf("%d", &value);
    // firstly, create node to insert
    temp = (struct node *)malloc(sizeof(struct node)); // malloc returns void pointer, so we type-cast it to struct node
    (*temp).data = value;
    // link temp to node next of head
    (*temp).next = head;
    // (*temp).next = NULL;
    // if(head != NULL) (*temp).next = NULL;
    // link head to temp
    head = temp;
    count++;
}
void insert_at_end()
{
    printf("Enter value: ");
    scanf("%d", &value);
    // firstly, create node to insert
    temp = (struct node *)malloc(sizeof(struct node)); // malloc returns void pointer, so we type-cast it to struct node
    temp->data = value;
    if (head->next == NULL)
    {
        head->next = temp;
        temp->next = NULL;
        count++;
        return;
    }
    ptr = head; // pointer to reach at last node of list
    while (ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    // place temp next to last node
    p->next = temp;
    // now temp is the last node
    temp->next = NULL;
    count++;
}
void insert_at_position()
{
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);
    // firstly, create node to insert
    temp = (struct node *)malloc(sizeof(struct node)); // malloc returns void pointer, so we type-cast it to struct node
    temp->data = value;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = head; // head node
        head = temp;
        count++;
        return;
    }
    // ptr for traversing
    ptr = head;
    // index-1, bcz we want to reach 1 node behind
    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    count++;
}
void print_list()
{
    temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d\t", (*temp).data);
        temp = (*temp).next;
    }
    printf("\nYour list has %d nodes!\n", count);
}

void delete_at_index(int index)
{
    // make a pointer to reach desired index
    struct node *ptr = head;
    for (int i = 0; i < index - 1; i++)
        ptr = ptr->next;
    // store the node in temp which we want to delete
    struct node *temp = ptr->next;
    ptr->next = temp->next;
}

int main()
{
    // insert_at_start();
    // insert_at_start(7);
    // insert_at_start(3);
    insert_at_position();
    print_list();
    insert_at_position();
    print_list();
    insert_at_position();
    // insert_at_end(2);
    // insert_at_end(7);
    // print_list();
    // delete_at_index(2);
    print_list();

    return 0;
}
