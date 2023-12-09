#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct node
{
    int vertex;
    struct node *next;
};

const int length = 4;
int rear = -1;
int array[4];
int srear = -1;
int sarray[4];

void enqueue(int value)
{
    if (rear == 3)
    {
        printf("Queue is full");
        return;
    }

    else
    {
        rear++;
        array[rear] = value;
    }
}

int dequeue()
{
    if (rear == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    int temp = array[0];
    for (int i = 0; i < rear; i++)
    {
        array[i] = array[i + 1];
    }
    rear--;
    return temp;
}

bool inarr(int arr[4], int value)
{
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

void push(int value)
{
    if (srear == 3)
    {
        printf("Stack is full");
        return;
    }

    else
    {
        srear++;
        sarray[srear] = value;
    }
}

int pop()
{
    if (srear == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    int temp = sarray[srear];
    srear--;
    return temp;
}

void printarr(int arr[4])
{
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

struct node *graph[4];

void makegraph()
{
    for (int i = 0; i < 4; i++)
    {
        graph[i] = NULL;
    }

    printf("Enter graph connections: ");
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
        new->next = graph[source];
        graph[source] = new;
    }
}

void bfs()
{
    int visited[4] = {0, 0, 0, 0};
    int position = 0;
    struct node *last;

    printf("0 ");
    visited[position] = 0;
    position++;
    if (graph[0] == NULL)
    {
        return;
    }
    last = graph[0];
    while (1)
    {
        while (last != NULL)
        {
            if (!inarr(visited, last->vertex))
            {
                enqueue(last->vertex);
                visited[position] = last->vertex;
                position++;
            }
            last = last->next;
            // printf("------");
            // printarr(array);
            // printarr(visited);
            // printf("------");
        }
        int val = dequeue();
        printf("%d ", val);
        // printf("\n");
        if (rear == -1)
        {
            break;
        }
        last = graph[val];
    }
}

void dfs()
{
    int visited[4] = {0, 0, 0, 0};
    int position = 0;
    struct node *last;

    printf("0 ");
    visited[position] = 0;
    position++;
    if (graph[0] == NULL)
    {
        return;
    }
    last = graph[0];
    while (1)
    {
        while (last != NULL)
        {
            if (!inarr(visited, last->vertex))
            {
                push(last->vertex);
                visited[position] = last->vertex;
                position++;
            }
            last = last->next;
        }
        int val = pop();
        printf("%d ", val);

        if (srear == -1)
        {
            break;
        }
        last = graph[val];
    }
}

void printgraph()
{
    for (int i = 0; i < 4; i++)
    {
        struct node *temp = graph[i];
        while (temp != NULL)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    makegraph();
    // printgraph();
    bfs();
    printf("\n");
    dfs();
}