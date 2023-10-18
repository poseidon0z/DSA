#include <stdio.h>
#include <malloc.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

struct node *createnode(int coeff, int power, struct node *poly)
{
    struct node *temp = poly;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->pow = power;
    temp->next = poly;
    return temp;
}

struct node *polyadd(struct node *poly1, struct node *poly2)
{
    struct node *answer = NULL;
    while (poly1 && poly2)
    {
        if (poly1->pow < poly2->pow)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));

            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
            temp->next = answer;
            answer = temp;
        }
        else if (poly1->pow > poly2->pow)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));

            temp->pow = poly2->pow;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
            temp->next = answer;
            answer = temp;
        }
        else
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
            temp->next = answer;
            answer = temp;
        }
    }
    while (poly1 || poly2)
    {
        if (poly1)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->pow = poly2->pow;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }
    return answer;
}

void printpoly(struct node *poly)
{
    while (1)
    {
        if (!poly)
        {
            break;
        }
        printf("%d x^%d ", poly->coeff, poly->pow);
        poly = poly->next;
    }
}

int main()
{
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *answer = NULL;

    poly1 = createnode(3, 5, poly1);
    poly1 = createnode(5, 4, poly1);
    poly1 = createnode(6, 3, poly1);
    poly1 = createnode(5, 2, poly1);
    poly1 = createnode(1, 1, poly1);
    poly2 = createnode(2, 4, poly2);
    poly2 = createnode(7, 3, poly2);
    poly2 = createnode(3, 1, poly2);
    printpoly(poly1);
    printf("\n\n");
    printpoly(poly2);
    printf("\n\n");
    answer = polyadd(poly1, poly2);
    printpoly(answer);
}