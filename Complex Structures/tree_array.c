#include <stdio.h>
int tree[15];

void takeInputPreorder(int root)
{
    if (root < sizeof(tree) / sizeof(int))
    {
        scanf("%d", &tree[root]);
        takeInputPreorder(root * 2 + 1);
        takeInputPreorder(root * 2 + 2);
    }
}
void takeInputInorder(int root)
{
    if (root < sizeof(tree) / sizeof(int))
    {
        takeInputInorder(root * 2 + 1);
        scanf("%d", &tree[root]);
        takeInputInorder(root * 2 + 2);
    }
}

void postOrder(int root)
{
    if (root < sizeof(tree) / sizeof(int))
    {
        postOrder(root * 2 + 1);
        postOrder(root * 2 + 2);
        printf("%d ", tree[root]);
    }
}

int getIndex(int root, int k)
{
    if (root < sizeof(tree) / sizeof(int))
    {
        int temp;
        temp = getIndex(root * 2 + 1, k);
        if (temp != -1)
        {
            return temp;
        }

        temp = getIndex(root * 2 + 2, k);

        if (temp != -1)
        {
            return temp;
        }
        printf("%d ", tree[root]);
        if (tree[root] == k)
        {
            printf("Found at %d", root);
            return root;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    printf("Give values in Inorder: ");
    takeInputInorder(0);

    printf("\n%d", getIndex(0, 12));
}
