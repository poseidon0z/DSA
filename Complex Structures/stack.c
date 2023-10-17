#include <stdio.h>

const int limit = 4;

struct stack
{
    int top;
    int *array;
};

void push(struct stack *s, int value)
{
    if (s->top == 4)
    {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    *(s->array + s->top) = value;
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    int value = *(s->array + s->top);
    s->top--;
    return value;
}

void printstack(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    int *temp = s->array;
    while (s->array + s->top != temp)
    {
        printf("%d ", *temp);
        temp++;
    }
    if (s->top > 0)
    {
        printf("%d\n", *(s->array + s->top));
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->array = (int *)malloc(sizeof(int) * limit);
    s->top = -1;
    pop(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 2);
    printstack(s);
    printf("%d\n", pop(s));
    printstack(s);
}