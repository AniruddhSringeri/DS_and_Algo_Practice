#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* getnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void printList(struct node* head)
{
    if(head == NULL) 
    {
        printf("The list is empty :(\n");
        return;
    }
    struct node* ptr = head;
    while(ptr)
    {
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("\b \b\b \n");
}

struct node* clone(struct node* head)
{
    struct node* newn = head;
    struct node* head2 = newn;
    struct node* temp = head;
    while(temp)
    {
        newn = getnode(temp->data);
        newn->next = temp->next;
        temp = temp->next;
        newn = newn->next;
    }
    return head2;
}

struct node* getList(int n)
{
    int data;
    printf("Enter element:  ");
    scanf("%d", &data);
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    if (n==1)
    {
        Node->next = NULL;
    }
    else 
    {
        Node->next = getList(n-1);
    }
    return Node;
}


int main()
{
    int n;
    printf("Enter number of elements to be in the linked list:  ");
    scanf("%d", &n);
    struct node* head = getList(n);
    struct node* cloned = clone(head);
    printf("The cloned list is:   ");
    printList(cloned);
    return 0;
}