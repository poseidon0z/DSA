#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct node
{
    struct node *right;
    struct node *left;
    int data;
};
struct stack
{
    struct node *top;
    // struct node* head;
};
void push(struct stack *s, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if (s->top == NULL)
    {
        temp->left = NULL;
    }
    else
    {
        temp->left = s->top;
    }
    temp->right = NULL;
    s->top = temp;
}
int pop(struct stack *s)
{
    int temp;
    if (s->top == NULL)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        temp = s->top->data;
        struct node *head2;
        head2 = s->top;
        s->top = s->top->left;
        free(head2);
        return temp;
    }
}
bool instack(struct stack *s, int value)
{
    struct node *temp = s->top;
    if (s->top == NULL)
        return false;
    else
    {
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return true;
            }
            else
            {
                temp = temp->left;
            }
        }
        return false;
    }
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
void Dfs()
{

    int visited[4];

    struct stack *q = (struct stack *)malloc(sizeof(struct stack));

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
                bool flag = !instack(q, j);
                for (int i = 0; i < 4; i++)
                {
                    if (visited[i] == j)
                    {
                        flag = false;
                    }
                }
                if (flag == true)
                {
                    push(q, j);
                }
            }
        }
        if (q->top == NULL)
        {
            break;
        }
        latest = pop(q);
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

    printf("\nDFS: ");
    Dfs();
    return 0;
}
