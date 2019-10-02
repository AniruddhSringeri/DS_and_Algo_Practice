//Uses recursion to input the linked list elements and store them in nodes with the links pointing to the following node recursively, thus creating a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

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

void printList(struct node* head)
{
    struct node* ptr = head;
    printf("The linked list is: ");
    while(ptr)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\b\b \n");
}

int main()
{
    int n, ch;
    printf("Program to implement a singly linked list.\n");
    do{
        printf("Enter 1 to proceed and anything else to exit:  ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: {
                do{
                    printf("Enter the no. of elements to be in the linked list(>=1):  ");
                    scanf("%d", &n);
                } while(n<1);
                struct node* head = getList(n);
                printList(head);
                break;
                }
                
            default: exit(0);
            

        }
    } while(1);
    return 0;

}