
#include <limits.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (int *)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

bool isPresent(struct Queue *queue, int value)
{
    for (int i = 0; i < sizeof(queue->array) / sizeof(int); i++)
    {
        if ((queue->array)[i] == value)
        {
            return true;
        }
    }
    return false;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

const int length = 4;
int array[4][4];
void input()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
}
void print()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void bfs()
{

    int visited[4];
    struct Queue *Q = createQueue(4);
    int k = 0;
    visited[k] = 0;
    k++;
    printf("0 ");
    int latest = 0;
    while (1)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[latest][j] == 1)
            {
                bool flag = !isPresent(Q, j);
                for (int i = 0; i < 4; i++)
                {
                    if (visited[i] == j)
                    {
                        flag = false;
                    }
                }
                if (flag == true)
                {
                    enqueue(Q, j);
                }
            }
        }
        if (isEmpty(Q))
        {
            break;
        }
        latest = dequeue(Q);
        visited[k] = latest;
        k++;
        printf("%d ", latest);
    }
}
int main()
{
    input();
    print();
    bfs();
    return 0;
}