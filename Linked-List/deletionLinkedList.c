#include <stdio.h>
#include <stdlib.h> // for using malloc() function

/* Linked List Creation and Traversal */

struct Node
{
    int data;          //for storing data of a single node
    struct Node *next; //pointer to the next node
};

//traversal function
void linkedListTraversal(struct Node *ptr) //*ptr bcz our node is a pointer
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; //now, ptr will point to the next node
    }
}

// Case 1: Deleting first element of the linked list
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

// Case 2: Deleting element at index of the linked list
struct Node *deleteAtIndex(struct Node *head, int index)
{
    // we are taking two pointers here
    struct Node *p = head;       //p is for pointing to next node
    struct Node *q = head->next; //q is for deleting

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    // once we reach at desired index ...
    p->next = q->next;
    // deleting q ie., desired element
    free(q);

    return head;
}

// Case 3: Deleting last element of the linked list
struct Node *deleteAtEnd(struct Node *head)
{
    // we are taking two pointers here
    struct Node *p = head;       //p is for pointing to next node
    struct Node *q = head->next; //q is for deleting

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    // once we reach at desired index ...
    p->next = NULL;
    // deleting q ie., desired element
    free(q);

    return head;
}

// Case 4: Deleting element at a given value of the linked list
struct Node *deleteAtGivenValue(struct Node *head, int value)
{
    // we are taking two pointers here
    struct Node *p = head;       //p is for pointing to next node
    struct Node *q = head->next; //q is for deleting

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    // once we reach at desired value ...
    if (q->data == value)
    {
        p->next = q->next;
        // deleting q ie., desired element
        free(q);
    }

    return head;
}
int main()
{
    system("CLS");

    //we will make pointers to the first, second and so on to access the elements of the list
    struct Node *head;   //this is first node
    struct Node *second; //this is second node
    struct Node *third;  //this is third node

    // allocate memory to the nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // link first / head and second node
    head->data = 7;
    head->next = second; //second has address of second node

    // link second and third node
    second->data = 11;
    second->next = third; //third has address of third node

    // terminate the list at the third node
    third->data = 66;
    third->next = NULL;

    //calling traveral function
    printf("Linked List before traversal:\n");
    linkedListTraversal(head);

    // head = deleteFirst(head); // deleting first element of the linked list

    // head = deleteAtIndex(head, 2);// deleting element at a desired index of the linked list

    // head = deleteAtEnd(head);// deleting element at the end of the linked list

    head = deleteAtGivenValue(head, 11); // deleting element at a given value of the linked list
    printf("Linked List after traversal:\n");
    linkedListTraversal(head);

    return 0;
}