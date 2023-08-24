#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    // defining variables we'll be using in general for a list
    struct node *head, *tail, *temp2, *temp;

    // Creating a new list;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the first value: ");
    scanf("%d", &(temp->data));
    temp->next = NULL;
    head = temp;
    tail = temp;

    // Adding further elements in loop
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        temp2 = (struct node *)malloc(sizeof(struct node));

        temp->next = temp2;
        printf("Enter the next value: ");
        scanf("%d", &(temp2->data));
        temp2->next = NULL;

        temp = temp2;
    }
    tail = temp;

    // Adding an element in the beginning
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter new value to add in beginning: ");
    scanf("%d", &(temp->data));
    temp->next = head;

    head = temp;

    // Adding an element in the middle
    int var;
    printf("Enter index to add new node: ");
    scanf("%d", &var);

    temp2 = (struct node *)malloc(sizeof(struct node));

    temp = head;
    for (int i = 0; i < var - 1; i++) // Going from position 0 (head) to position 2, so that new node can be added after it
    {
        temp = temp->next;
    }

    temp2->next = temp->next;
    temp->next = temp2;
    printf("Enter new value to add in middle: ");
    scanf("%d", &(temp2->data));

    // Adding new element to end
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter new value to add to end: ");
    scanf("%d", &(temp->data));
    temp->next = NULL;
    tail->next = temp;

    tail = temp;

    // Printing our final list:
    temp = head;

    while (1)
    {
        printf("%d ", temp->data);
        if (temp == tail)
        {
            break;
        }
        temp = temp->next;
    }
}
