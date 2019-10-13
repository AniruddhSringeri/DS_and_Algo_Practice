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

void insertfront(struct node** headref, int item)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = *headref;
    *headref = newnode;
}

void insertend(struct node** headref, int item)
{
    if(*headref == NULL) 
    {
        printf("No list yet.\n");
        return;
    }
    else
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->next = NULL;
        struct node* currentnode = *headref;
        while(currentnode->next)
        {
            currentnode = currentnode->next;
        }
        currentnode->next = newnode;
    }
}

int deletefront(struct node** head)
{
    if(*head == NULL)
    {
        printf("List is empty.\n");
        return -9999;
    }
    struct node* temp = *head;
    int first = temp->data;
    (*head) = (*head)->next;
    free(temp);
    return first;
}

void printlist(struct node* head)
{
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
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
    int ch0, ch1, n, item;
    struct node* head = NULL;
    printf("Linked list program with deletion from front.\n");
    do 
    {
        printf("To continue, enter 1. To exit, enter 2.\n");
        scanf("%d", &ch0);
        switch(ch0)
        {
            case 1: {
                printf("Enter\n1: Create new linked list\n2: Insert at front\n3: Insert at end\n4: Deletion from front\n5: Display list\n6: Exit\n");
                scanf("%d", &ch1);
                switch(ch1)
                {
                    case 1: {
                        printf("Enter no. of elements to be in linked list:  ");
                        scanf("%d", &n);
                        int* arr;
                        arr = (int*)calloc(n, sizeof(int));
                        printf("Enter elements:  ");
                        for(int i = 0; i < n; i++)
                        {
                            scanf("%d", &arr[i]);
                        }
                        head = makelist(arr, n);
                        break;
                    }
                    case 2: {
                        printf("Enter element to be inserted:   ");
                        scanf("%d", &item);
                        insertfront(&head, item);
                        if(head == NULL) printf("No linked list to insert to!!!\n");
                        else printf("Element %d inserted at front of linked list.\n", item);
                        break;
                    }
                    case 3: {
                        printf("Enter element to be inserted at end:   ");
                        scanf("%d", &item);
                        insertend(&head, item);
                        break;
                    }
                    case 4: {
                        int temp = deletefront(&head);
                        if(temp!=-9999)
                        {
                            printf("The deleted element is %d\n", temp);
                        }
                        break;
                    }
                    case 5: {
                        printlist(head);
                        break;
                    }
                    case 6: exit(0);
                    default: printf("Invalid input.\n");
                }
                break;
            }
            case 2: exit(0);
            default: printf("Invalid input.\n");
        }

    } while(1);
    return 0;
}

