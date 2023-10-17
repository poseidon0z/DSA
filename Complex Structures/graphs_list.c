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
        struct node *temp = mygraph->heads[latest];
        while (temp != NULL)
        {
            bool flag = !inqueue(q, temp->vertex);
            for (int i = 0; i < 4; i++)
            {
                if (visited[i] == temp->vertex)
                {
                    flag = false;
                }
            }
            if (flag == true)
            {
                enqueue(q, temp->vertex);
            }
            temp = temp->next;
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
    struct graph *mygraph = makegraph();

    printf("\nPrinting graph: \n");
    printgraph(mygraph);

    printf("\nBFS: ");
    bfs(mygraph);
    return 0;
}