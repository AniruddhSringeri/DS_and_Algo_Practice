#include <stdio.h>
#define SIZE 10

void enqueue(int q[SIZE], int *r, int item)
{
    if(*r == SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    (*r)++;
    q[*r] = item;
}

int dequeue(int q[SIZE], int *f, int *r)
{
    if(*f>*r)
    {
        printf("Queue Underflow\n");
        return -9999;
    }
    int item;
    item = q[*f];
    (*f)++;
    return item;
}

void display(int q[SIZE], int f, int r)
{
    if(f>r)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue:  ");
    for(int i = f; i <= r; i++)
    {
        printf("%d, ", q[i]);
    }
    printf("\b\b \n");
}