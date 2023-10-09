#include <stdio.h>
#include <malloc.h>
struct node
{
    int value;
    struct node *left;
    struct node *right;
};

void inorder(struct node *top, int depth)
{

    if (depth <= 1)
    {
        struct node *newL = (struct node *)malloc(sizeof(struct node));
        top->left = newL;
        inorder(newL, depth + 1);
        scanf("%d", &(top->value));
        struct node *newR = (struct node *)malloc(sizeof(struct node));
        top->right = newR;
        inorder(newR, depth + 1);
    }
    else
    {
        scanf("%d", &(top->value));
    }
}
void preorderPrint(struct node *top)
{
    if (top->left != NULL && top->right != NULL)
    {

        printf("%d ", top->value);
        preorderPrint(top->left);
        preorderPrint(top->right);
    }
    else
    {
        printf("%d ", top->value);
    }
}
int main()
{
    struct node *top;
    top = (struct node *)malloc(sizeof(struct node));
    printf("Enter values in Inorder: ");
    inorder(top, 0);
    preorderPrint(top);
}