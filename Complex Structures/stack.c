#include <stdio.h>

int *push(int *stack, int *top, int val)
{
    if (top == &(stack[4]))
    {
        printf("Stack is full!\n");
    }
    else
    {
        top++;
        *top = val;
    }
    return top;
}

int *pop(int *stack, int *top)
{
    if (top == stack - 1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        *top = 0;
        top--;
    }
    return top;
}

void printstack(int *stack, int *top)
{
    int i = 0;
    while (&(stack[i]) != top + 1)
    {
        printf("%d ", stack[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    int stack[5];
    int *top = stack - 1;
    top = pop(stack, top);
    top = push(stack, top, 1);
    top = push(stack, top, 2);
    top = push(stack, top, 3);
    top = push(stack, top, 4);
    top = push(stack, top, 5);
    top = push(stack, top, 2);
    printstack(stack, top);
    top = pop(stack, top);
    printstack(stack, top);
}