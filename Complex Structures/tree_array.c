#include <stdio.h>
int tree[15];
// void root(int data)
// {
//     if(tree[0]!=0)
//     {
//         printf("not possible");
//     }
//     else
//     {
//         tree[0]=data;
//     }
// }
// void right(int root,int data)
// {
//     if(tree[root]!=0)
//     {
//         tree[root*2+2]=data;
//     }
//     else{
//         printf("Not possible");
//     }
// }
// void left(int root,int data)
// {
//     if(tree[root]!=0)
//     {
//         tree[root*2+1]=data;
//     }
//     else{
//         printf("Not possible");
//     }
// }

void takeInputPreorder(int root)
{
    if (root <= 6)
    {
        scanf("%d", &tree[root]);
        takeInputPreorder(root * 2 + 1);
        takeInputPreorder(root * 2 + 2);
    }
    else
    {
        scanf("%d", &tree[root]);
    }
}
void takeInputInorder(int root)
{
    if (root <= 2)
    {
        takeInputInorder(root * 2 + 1);
        scanf("%d", &tree[root]);
        takeInputInorder(root * 2 + 2);
    }
    else
    {
        scanf("%d", &tree[root]);
    }
}

void postOrder(int root)
{
    if (root <= 2)
    {
        postOrder(root * 2 + 1);
        postOrder(root * 2 + 2);
        printf("%d ", tree[root]);
    }
    else
    {
        printf("%d ", tree[root]);
    }
}
int main()
{
    int arr[15];

    printf("Give values in Inorder: ");
    takeInputInorder(0);

    postOrder(0);
}
