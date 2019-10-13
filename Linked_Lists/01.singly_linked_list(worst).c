//The naive method would be to construct individual linked list nodes first, and later rearrange their pointers to build the list.
//This solution implements a linked list of 3 nodes. It obviously would get tedious for larger number of nodes, not to mention how clumsy of a method it is.

#include <stdio.h>
#include <stdlib.h>

struct node                  //structure to store a linked list node.
{
    int data;                //number to be stored.
    struct node* next;       //pointer to the next node.
};

//function that returns a new linked list node from heap memory. i.e, it creates a new node.
struct node* getnode(int data)
{
    //allocate memory from heap to a new node, and set its data.
    struct node* Node = (struct node*)malloc(sizeof(struct node)); //malloc() returns a pointer of type void, which can be cast into any type. malloc() takes as argument the number of bytes to be allocated. That can be given in the form of sizeof(some_datatype). Note that that is why, in this code, we write sizeof(struct node) and not sizeof(struct node* ), because we need a datatype, not a pointer of that datatype.
    // ptr = (cast_type*) malloc(n * sizeof(datatype));
    // int* ptr = (int*) malloc(5 * sizeof(int))
    Node->data = data;

    //Set the next pointer of the new node to point to NULL
    Node->next = NULL;
    return Node;
}

struct node* constructList()
{
    //construct 3 linked list nodes
    struct node* first = getnode(1);
    struct node* second = getnode(2);
    struct node* third = getnode(3);
    struct node* fourth = getnode(4);

    //rearrange the pointers to build linked list
    struct node* head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    return head;
}

void printList(struct node* head)
{
    struct node* ptr = head;
    while(ptr)   //this means that the while loop gets executed as long as ptr!=NULL
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node* head = constructList();
    printf("The linked list is as follows:  ");
    printList(head);
    return 0;
}