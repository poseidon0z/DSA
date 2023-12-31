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

    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->array = (int *)malloc(sizeof(int) * limit);
    q->rear = -1;

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
                bool flag = !inqueue(q, j);
                for (int i = 0; i < 4; i++)
                {
                    if (visited[i] == j)
                    {
                        flag = false;
                    }
                }
                if (flag == true)
                {
                    enqueue(q, j);
                }
            }
        }
        if (q->rear == -1)
        {
            break;
        }
        latest = dequeue(q);
        visited[k] = latest;
        k++;
        printf("%d ", latest);
    }
}
int main()
{
    printf("Input:\n");
    input();

    printf("\nOutput:\n");
    print();

    printf("\nBFS: ");
    bfs();
    return 0;
}