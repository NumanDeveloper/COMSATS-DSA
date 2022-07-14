#include <stdio.h>
#include <stdlib.h> // for using malloc() function

/* Linked List Insertion */

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

// Case 1: Insertion at start of the linked list
struct Node *insertAtFirst(struct Node *head, int data)
{
    //creating a new node to insert at the start
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    //now next of new node will point to the previous head
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Case 2: Insertion at an index of the linked list
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    //creating a new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    //creating a pointer for traversing and going to the desired index
    struct Node *p = head;
    int i = 0;

    while (i != index - 1) //index-1: bcz we will stand our pointer p one less than the index at which insertion is required
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    p->next = ptr;
    ptr->next = p->next;

    return head;
}

// Case 3: Insertion at end of the linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    //creating a new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    //creating a pointer for traversing and going to the desired index
    struct Node *p = head;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++; //incrementing index
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

// Case 4: Insertion after a node in the linked list
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    //creating a new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    // firstly, we have to link the list. lastly, we have to break the link
    ptr->next = prevNode->next;
    prevNode->next = ptr;

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

    printf("Linked List before insertion:\n");
    //calling traveral function
    linkedListTraversal(head);

    //calling insertion fucntion
    // head = insertAtFirst(head, 60); //now this new node will be our new head

    //calling insetAtIndex function
    // insertAtIndex(head, 20, 2);

    //calling insertAtIndex function
    // insertAtEnd(head, 30);

    //calling insertAfterNode function
    head = insertAfterNode(head, second, 45);

    printf("\nLinked List after insertion:\n");
    //calling traveral function
    linkedListTraversal(head);

    return 0;
}