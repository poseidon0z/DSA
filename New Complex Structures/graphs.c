#include <stdio.h>
#include <stdbool.h>

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

bool inarr(int *arr, int value)
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

int graph[4][4];

void bfs(int starting)
{
    int visited[4];
    int position = 0;
    int last;

    printf("0 ");
    visited[position] = 0;
    position++;
    last = 0;

    while (1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (graph[last][i] == 1 && !inarr(visited, i))
            {
                enqueue(i);
                visited[position] = i;
                position++;
            }
        }
        if (rear == -1)
        {
            break;
        }
        last = dequeue();
        printf("%d ", last);
    }
}

void dfs(int starting)
{
    int visited[4];
    int position = 0;
    int last;

    printf("0 ");
    visited[position] = 0;
    position++;
    last = 0;

    while (1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (graph[last][i] == 1 && !inarr(visited, i))
            {
                push(i);
                visited[position] = i;
                position++;
            }
        }
        if (srear == -1)
        {
            break;
        }
        last = pop();
        printf("%d ", last);
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    bfs(0);
    printf("\n");
    dfs(0);
}