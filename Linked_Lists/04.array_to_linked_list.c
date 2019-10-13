//This program takes the elements as input from user, stores in array and then converts it into a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* getnode(int data, struct node* nextnode)
{
    struct node* Node = (struct node*) malloc (sizeof(struct node));
    Node->data = data;
    Node->next = nextnode;
    return Node;
}

struct node* makelist(int arr[], int n)
{
    struct node* Node = NULL, *head = NULL;
    for(int i = n-1; i >= 0; i--)
    {
        Node = getnode(arr[i], Node);
    }
    head = Node;
    return head;
}

void printlist(struct node* head)
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
    int n;
    printf("Linked list program.\n");
    do
    {
        do {
            printf("To exit, enter -1.\nOtherwise, enter the number of elements to be in the linked list(>=1):\n");
            scanf("%d", &n);
        } while(n<-1 || n == 0);
        switch(n)
        {
            case -1: exit(0);
            default: {
                int* arr;
                arr = (int*)calloc(n, sizeof(int));
                printf("Enter the elements:  \n");
                for (int i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                struct node* head = makelist(arr, n);
                printlist(head);
            }
        }
    } while(1);
    return 0;
}



