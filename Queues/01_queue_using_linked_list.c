#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* getnode(int item)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    if(newnode)
        return newnode;
    else
    {
        printf("Memory could not be allocated.\n");
        exit(0);
    }
}

struct node* enqueue(struct node* head, int item)
{
    struct node* ptr = head;
    struct node* newnode = getnode(item);
    if(ptr == NULL)
    {
        head = newnode;
        return head;
    }
    while(ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    return head;
}

struct node* dequeue(struct node* head)
{
    if(head == NULL)
    {
        printf("Queue Underflow\n");
        return head;
    }
    struct node* ptr = head;
    printf("The deleted element is %d\n", ptr->data);
    head = head->next;
    free(ptr);
    return head;
}

void display(struct node* head)
{
    if(head == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct node* ptr = head;
    printf("The contents of queue are:  ");
    while(ptr)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\b\b \n");
}

int main()
{
    struct node* head = NULL;
    int item, size, count = 0, ch;
    printf("Queue using linked list.\nEnter the size of queue:  ");
    scanf("%d", &size);
    do
    {
        printf("Enter\n1: Enqueue\n2: Dequeue\n3: Display queue\n9999: Exit\nYour choice:  ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: {
                printf("Enter the element to be enqueued:  ");
                scanf("%d", &item);
                if(count == size)
                {
                    printf("Queue Overflow\n");
                }
                count++;
                head = enqueue(head, item);
                break;
            }
            case 2: {
                head = dequeue(head);
                if(head != NULL)
                {
                    count--;
                } 
                break;
            }
            case 3: {
                display(head);
                break;
            }
            case 9999: {
                exit(0);
            }
            default: {
                printf("Invalid input.\n");
            }
        }
    } while(1);
    return 0;
}