#include <stdio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head, *tail, *temp1, *temp2;
int main()
{
    temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter first data");
    scanf("%d", &(temp2->data));
    temp2->next = NULL;
    temp2->prev = NULL;
    head = temp2;
    tail = temp2;
    temp1 = head;
    for (int i = 0; i < 5; i++)
    {
        temp2 = (struct node *)malloc(sizeof(struct node));
        printf("Enter the element");
        scanf("%d", &(temp2->data));
        temp1->next = temp2;
        temp2->prev = temp1;
        temp1 = temp1->next;
        tail = temp2;
    }
    temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to add in the beginning of the list");
    scanf("%d", &(temp2->data));
    temp2->next = head;
    temp2->prev = NULL;
    head = temp2;

    temp2 = (struct node *)malloc(sizeof(struct node));
    int pos;
    printf("Enter the position ");
    scanf("%d", &pos);
    temp1 = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to add in the middle of the list");
    scanf("%d", &(temp2->data));
    temp2->next = temp1->next;
    temp2->prev = temp1;
    temp1->next = temp2;
    temp2->next->prev = temp2;

    temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to add in the end of the list");
    scanf("%d", &temp2->data);
    tail->next = temp2;
    temp2->prev = tail;
    temp2->next = NULL;
    tail = temp2;

    // deleting beginning node
    temp2 = head->next;
    temp2->prev = NULL;
    free(head);
    head = temp2;
    temp1 = head;
    // deleting in the middle
    printf("Enter the position of element you want to delete");
    scanf("%d", &pos);
    temp1 = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp1->next->next;
    temp1->next->prev = temp1;
    free(temp2);

    // deleting last element
    temp1 = tail->prev;
    temp1->next = NULL;
    free(tail);
    tail = temp1;
    temp1 = head;
    while (temp1 != tail)
    {
        printf("%d", temp1->data);
        temp1 = temp1->next;
    }
    printf("%d", tail->data);
}
