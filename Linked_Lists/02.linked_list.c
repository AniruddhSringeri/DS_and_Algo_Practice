//this program makes each newly created node's next(link) to point to the next node and it obviously has to involve recursion.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node* getnode(int data, struct node* nextNode)
{
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->next = nextNode;
    return Node;
}

struct node* constructList()
{
    struct node* head = getnode(1, getnode(2, getnode(3, NULL)));
    return head;
}

void printList(struct node* head)
{
    struct node* ptr = head;
    printf("The linked list is:  ");
    while(ptr)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\b\b \n");
}

int main()
{
    struct node* head = constructList();
    printList(head);
    return 0;
}
