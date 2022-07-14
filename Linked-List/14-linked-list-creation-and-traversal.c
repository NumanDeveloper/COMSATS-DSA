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
    linkedListTraversal(head);

    return 0;
}