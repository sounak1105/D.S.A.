#include <stdio.h>

#define CAPACITY 10
typedef struct queue
{
        int arr[CAPACITY];
        int front;
        int rear;
} queue_t;

queue_t q = {
    .front = -1,
    .rear = -1,
};

void enqueue(int inp)
{
    if (CAPACITY-1 <= q.rear)
    {
        printf("QUEUE is full \n ");
        return;
    }
    if (-1 == q.front)
    {
        q.front = 0;
    }
    q.rear++;
    q.arr[q.rear] = inp;
    return;
}

int dequeue()
{
    if (-1 == q.front)
    {    
        printf("NO ELEMENT IN THE QUEUE \n");
        return -1;
    }
    int elem = q.arr[q.front];
    q.arr[q.front] = 0;
    if( q.front == q.rear)
    {
        q.front=-1;
        q.rear=-1;
    }
    else
    {
        q.front++;
    }
    return elem;
}
void display()
{
    if (-1 == q.front)
    {
        printf("NO ELEMENT TO PRINT \n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
    {
        printf(" %d , ",q.arr[i]);
    }
    printf("\n");
    return;
}
void main()
{
    enqueue(5);
    enqueue(10);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    display();
    dequeue();
    dequeue();
    display();
    enqueue(1);
    display();
}