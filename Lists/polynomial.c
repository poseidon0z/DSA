#include <stdio.h>
#include <malloc.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

struct list
{
    struct node *head;
};

void insert(struct list *li, int coeff, int pow)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->coeff = coeff;
    new->pow = pow;
    new->next = li->head;
    li->head = new;
}

void createpoly(struct list *li)
{
    int coeff;
    int pow;
    while (1)
    {
        scanf("%d", &coeff);
        if (coeff < 0)
        {
            break;
        }
        scanf("%d", &pow);
        insert(li, coeff, pow);
    }
}

void printpoly(struct list *li)
{
    struct node *temp = li->head;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coeff, temp->pow);
        temp = temp->next;
    }
    printf("\n");
}

struct list *addpoly(struct list *li1, struct list *li2)
{
    struct node *temp1 = li1->head;
    struct node *temp2 = li2->head;
    struct list *li = (struct list *)malloc(sizeof(struct list));
    li->head = NULL;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->pow > temp2->pow)
        {
            insert(li, temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        }
        else if (temp1->pow < temp2->pow)
        {
            insert(li, temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }
        else
        {
            insert(li, temp2->coeff + temp1->coeff, temp2->pow);
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
    }
    while (temp1 != NULL)
    {
        insert(li, temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        insert(li, temp2->coeff, temp2->pow);
        temp2 = temp2->next;
    }

    return li;
}

int main()
{
    struct list *poly1 = (struct list *)malloc(sizeof(struct list));
    struct list *poly2 = (struct list *)malloc(sizeof(struct list));

    poly1->head = NULL;
    poly2->head = NULL;

    createpoly(poly1);
    createpoly(poly2);

    printpoly(poly1);
    printpoly(poly2);

    struct list *ans = addpoly(poly1, poly2);
    printpoly(ans);
}