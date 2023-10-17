#include <stdio.h>
#include <malloc.h>
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
struct graph
{
    struct node *heads[4];
};

struct node
{
    int vertex;
    struct node *next;
};

struct graph *makegraph()
{
    struct graph *mygraph = (struct graph *)malloc(sizeof(struct graph));

    for (int i = 0; i < 4; i++)
    {
        mygraph->heads[i] = NULL;
    }

    printf("Enter graph: ");
    while (1)
    {
        int source, destination;
        scanf("%d", &source);

        if (source < 0)
        {
            break;
        }

        scanf("%d", &destination);

        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->vertex = destination;
        new->next = mygraph->heads[source];

        mygraph->heads[source] = new;
    }
    return mygraph;
}

void printgraph(struct graph *mygraph)
{
    for (int i = 0; i < 4; i++)
    {
        struct node *temp = mygraph->heads[i];
        printf("For vertex %d: ", i);
        while (temp != NULL)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("End\n");
    }
}

void bfs(struct graph *mygraph)
{
    int visited[4] = {0, 0, 0, 0};
    struct Queue *Q = createQueue(4);
    int k = 0;
    visited[k] = 0;
    k++;
    printf("0 ");
    int latest = 0;
    while (1)
    {
        struct node *temp = mygraph->heads[latest];
        while (temp != NULL)
        {
            bool flag = !isPresent(Q, temp->vertex);
            for (int i = 0; i < 4; i++)
            {
                if (visited[i] == temp->vertex)
                {
                    flag = false;
                }
            }
            if (flag == true)
            {
                enqueue(Q, temp->vertex);
            }
            temp = temp->next;
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
    struct graph *mygraph = makegraph();
    printgraph(mygraph);
    bfs(mygraph);
    return 0;
}