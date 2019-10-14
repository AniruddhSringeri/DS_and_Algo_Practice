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
    return newnode;
}

struct node* push(struct node* head, int item)
{
    struct node* newnode = getnode(item);
    newnode->next = head;
    head = newnode;
    return head;
}

struct node* pop(struct node* head)
{
    if(head == NULL)
    {
        printf("Stack Underflow:(\n");
        return head;
    }
    struct node* temp = head;
    printf("The popped element is %d.\n", temp->data);
    head = head->next;
    free(temp);
    return head;
}

void display(struct node* head)
{
    struct node* ptr = head;
    if(ptr == NULL)
    {
        printf("The stack is empty.\n");
        return;
    }
    printf("The stack(from top to bottom) is:   ");
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
    int item, ch, size, count = 0;
    printf("Stack program: \n");
    printf("Enter size of stack:  ");
    scanf("%d", &size);
    do
    {
        printf("Enter your choice:  \n1: Push\n2: Pop\n3: Display stack\n9999: Exit program\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: {
                printf("Enter item to be pushed:  ");
                scanf("%d", &item);
                count++;
                if(count>size)
                {
                    printf("Stack Overflow\n");
                    break;
                }
                head = push(head, item);
                break;
            }
            case 2: {
                head = pop(head);
                if(count!=0)
                {
                    count--;
                }
                break;
            }
            case 3: {
                display(head);
                break;
            }
            case 9999: exit(0);
            default: printf("Invalid input.\n");
        }
    } while(1);
    return 0;
}

