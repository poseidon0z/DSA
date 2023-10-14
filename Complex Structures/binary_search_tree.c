#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *left;
    int key;
    struct node *right;
};

struct node *insert(struct node *head, int value)
{
    if (head == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->key = value;
        return temp;
    }

    if (head->key < value)
    {
        head->right = insert(head->right, value);
    }
    else
    {
        head->left = insert(head->left, value);
    }

    return head;
}
void printinorder(struct node *head)
{
    if (head->left != NULL || head->right != NULL)
    {

        if (head->left != NULL)
        {
            printinorder(head->left);
        }
        printf("%d ", head->key);
        if (head->right != NULL)
        {
            printinorder(head->right);
        }
    }
    else
    {
        printf("%d ", head->key);
    }
}

int kthmin(struct node *head, int k)
{
    int i = 0;
    if (i == k)
    {
        printf("%d", head->key);
    }
    if (head->left != NULL || head->right != NULL)
    {

        if (head->left != NULL)
        {
            i += kthmin(head->left, k - i);
        }
        i += 1;
        if (head->right != NULL)
        {
            i += kthmin(head->right, k - i);
        }
    }
    else
    {
        i += 1;
    }
    return i;
}
struct node *delete(struct node *head, int value)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->key > value)
    {
        head->left = delete (head->left, value);
        return head;
    }
    else if (head->key < value)
    {
        head->right = delete (head->right, value);
        return head;
    }
    if (head->left == NULL)
    {
        return head->right;
    }
    else if (head->right == NULL)
    {
        return head->left;
    }
    struct node *parent = head;
    struct node *child = head->right;
    while (child->left != NULL)
    {
        parent = child;
        child = child->left;
    }
    head->key = child->key;
    if (head == parent)
    {
        parent->right = child->right;
    }
    else
    {
        parent->left = child->right;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    printf("Enter values: ");
    while (1)
    {
        int data;
        scanf("%d", &data);
        if (data < 0)
        {
            break;
        }
        head = insert(head, data);
    }
    printinorder(head);
    printf("Enter: ");
    int v;
    scanf("%d", &v);
    head = delete (head, v);
    printinorder(head);
    kthmin(head, 2);
    return 0;
}