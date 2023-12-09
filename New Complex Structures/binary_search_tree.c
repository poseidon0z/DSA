#include <stdio.h>
#include <malloc.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *head, int value)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->value = value;
        return head;
    }
    if (value < head->value)
    {
        head->left = insert(head->left, value);
    }
    else
    {
        head->right = insert(head->right, value);
    }
    return head;
}

void printtree(struct node *head)
{
    if (head->left != NULL && head->right != NULL)
    {
        printtree(head->left);
        printf("%d ", head->value);
        printtree(head->right);
    }
    else if (head->left != NULL)
    {
        printtree(head->left);

        printf("%d ", head->value);
    }
    else if (head->right != NULL)
    {
        printf("%d ", head->value);
        printtree(head->right);
    }
    else
    {
        printf("%d ", head->value);
    }
}

struct node *del(struct node *head, int value)
{
    if (head == NULL)
    {
        return head;
    }
    else if (head->value > value)
    {
        head->left = del(head->left, value);
        return head;
    }
    else if (head->value < value)
    {
        head->right = del(head->right, value);
        return head;
    }

    if (head->left == NULL && head->right == NULL)
    {
        head = NULL;
        return head;
    }
    else if (head->left != NULL && head->right == NULL)
    {
        head = head->left;
        return head;
    }
    else if (head->left == NULL && head->right != NULL)
    {
        head = head->right;
        return head;
    }
    else
    {
        struct node *temp = head;
        struct node *succ = temp->right;
        while (succ->left != NULL)
        {
            temp = succ;
            succ = succ->left;
        }

        if (temp == head)
        {
            temp->right = succ->right;
        }
        else
        {
            temp->left = succ->right;
        }
        head->value = succ->value;

        return head;
    }
}

int main()
{
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree = NULL;
    int val;
    while (1)
    {
        scanf("%d", &val);
        if (val < 0)
        {
            break;
        }
        tree = insert(tree, val);
    }
    printtree(tree);
    printf("\n");
    while (1)
    {
        scanf("%d", &val);
        if (val < 0)
        {
            break;
        }
        tree = del(tree, val);
        printtree(tree);
        printf("\n");
    }
}