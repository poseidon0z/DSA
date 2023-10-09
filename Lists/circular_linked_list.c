#include <stdio.h>
struct node
{
    int data;
    struct node *next;
} *head, *tail, *temp, *temp2;

int main()
{
    // Creating circular linked list
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter first data: ");
    scanf("%d", &(temp->data));
    temp->next = temp;
    head = temp;
    tail = temp;

    // Adding further elements
    for (int i = 0; i < 5; i++)
    {
        temp2 = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &(temp2->data));
        temp->next = temp2;
        temp2->next = head;
        temp = temp2;
        tail = temp2;
    }

    // Adding element to beginning
    temp2 = (struct node *)malloc(sizeof(struct node));
    temp2->next = head;
    printf("Enter value to add to beginning: ");
    scanf("%d", &(temp2->data));
    head = temp2;
    tail->next = head;

    // Adding element to middle
    printf("Enter the position");
    int pos;
    scanf("%d", &pos);

    temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    temp2 = (struct node *)malloc(sizeof(struct node));
    temp2->next = temp->next;
    temp->next = temp2;
    printf("Enter teh value to add to this postion: ");
    scanf("%d", &(temp2->data));

    // Adding element to end
    temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to add to end: ");
    scanf("%d", &(temp2->data));
    tail->next = temp2;
    tail = temp2;
    tail->next = head;
    // deleting first element
    tail->next = head->next;
    temp = head;
    head = head->next;
    free(temp);
    // Deleting elements from the middle
    printf("Enter the element's position to be deleted");
    scanf("%d", &pos);
    temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);

    // deleting last element
    temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    tail = temp;
    temp2 = temp->next;
    temp->next = head;
    free(temp2);
    temp = head;
    while (temp != tail)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("%d", tail->data);
}
