#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

const int limit = 4;

struct queue
{
    int rear;
    int *array;
};

void *enqueue(struct queue *q, int value)
{
    if (q->rear == 3)
    {
        printf("Queue is full!\n");
        return;
    }
    q->rear = q->rear + 1;
    *(q->array + q->rear) = value;
}

int dequeue(struct queue *q)
{
    if (q->rear == -1)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int val = *(q->array);
    for (int i = 0; i < limit - 1; i++)
    {
        *(q->array + i) = *(q->array + i + 1);
    }
    q->rear = q->rear - 1;
    return val;
}

void printqueue(struct queue *q)
{
    int *temp = q->array;
    if (q->rear == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    while (temp != q->array + q->rear)
    {
        printf("%d ", *(temp));
        temp++;
    }
    if (q->rear > 0)
    {
        printf("%d\n", *(q->array + q->rear));
    }
}

bool inqueue(struct queue *q, int value)
{
    int *temp = q->array;
    if (q->rear == -1)
    {
        printf("Queue is empty!\n");
        return false;
    }
    while (temp != q->array + q->rear)
    {
        if (*temp == value)
        {
            return true;
        }
        temp++;
    }
    if (q->rear > 0)
    {
        if (*temp == value)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->array = (int *)malloc(sizeof(int) * limit);
    q->rear = -1;
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printqueue(q);
    dequeue(q);
    printqueue(q);
    printf("%s\n", inqueue(q, 4) ? "true" : "false");
    printf("%s\n", inqueue(q, 8) ? "true" : "false");
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
}