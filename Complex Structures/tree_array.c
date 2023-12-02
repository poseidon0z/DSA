#include <stdio.h>
int tree[15];

void takeInputPreorder(int root)
{
    if (root <= sizeof(tree) / sizeof(int))
    {
        scanf("%d", &tree[root]);
        takeInputPreorder(root * 2 + 1);
        takeInputPreorder(root * 2 + 2);
    }
}
void takeInputInorder(int root)
{
    if (root <= sizeof(tree) / sizeof(int))
    {
        takeInputInorder(root * 2 + 1);
        scanf("%d", &tree[root]);
        takeInputInorder(root * 2 + 2);
    }
}

void postOrder(int root)
{
    if (root <= sizeof(tree) / sizeof(int))
    {
        postOrder(root * 2 + 1);
        postOrder(root * 2 + 2);
        printf("%d ", tree[root]);
    }
}
int main()
{
    printf("Give values in Inorder: ");
    takeInputInorder(0);

    postOrder(0);
}
