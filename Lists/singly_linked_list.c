#include <stdio.h>
#include <malloc.h>

// Structure for each node of the list
struct node
{
    char value;
    struct node *next;
};

// Structure to represent a list
struct sl_list
{
    struct node *head;
    struct node *tail;
};

// Add an element to the end of a list
void append(struct sl_list *li, char value)
{
    // Create new node, with required values
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->value = value;
    new->next = NULL;

    // Empty list case
    if (li->head == NULL)
    {
        li->head = new;
        li->tail = new;
    }
    else // Existing list case
    {
        li->tail->next = new;
        li->tail = new;
    }
}

// Insert an element to a particular index of the list
void insert(struct sl_list *li, char value, int index)
{
    // Create new node with required value
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->value = value;

    // Empty list case
    if (li->head == NULL)
    {
        if (index == 0)
        {
            new->next == NULL;
            li->head = new;
            li->tail = new;
        }
        else
        {
            printf("Invalid index!\n");
        }
    }

    // Insert at head case
    else if (index == 0)
    {
        new->next = li->head;
        li->head = new;
    }
    else
    {
        struct node *it = li->head;
        for (int i = 0; i < index - 1 && it->next != NULL; i++)
        {
            it = it->next;
        }
        if (it->next == NULL)
        {
            // Insert at tail case
            if (it == li->tail)
            {
                li->tail->next = new;
                li->tail = new;
                new->next = NULL;
            }
            else
            {
                printf("Invalid index!\n");
            }
        }

        // Insert in middle case
        else
        {
            new->next = it->next;
            it->next = new;
        }
    }
}

// Delete element at particular index of list
char delete(struct sl_list *li, int index)
{
    // Iterator to go through the list
    struct node *it = li->head;

    // Empty list case
    if (it == NULL)
    {
        printf("Empty list!\n");
        return NULL;
    }

    // Delete head case
    if (index == 0)
    {
        li->head = it->next;
        char val = it->value;
        free(it);
        return val;
    }
    for (int i = 0; i < index - 1 && it != NULL; i++)
    {
        it = it->next;
    }
    if (it == NULL)
    {
        printf("Index out of bounds!\n");
        return NULL;
    }

    // other cases
    struct node *to_del = it->next;
    char val = to_del->value;
    it->next = it->next->next;

    // Extra condition for tail
    if (to_del->next == NULL)
    {
        li->tail = it;
    }

    free(to_del);
    return val;
}

// Print all the elements of a list
void print(struct sl_list *li)
{
    struct node *it = li->head;
    if (it != NULL)
    {
        printf("[%c", it->value);
        it = it->next;
        while (it != NULL)
        {
            printf(" ,%c", it->value);
            it = it->next;
        }
        printf("]\n");
    }
    else
    {
        printf("[]\n");
    }
}

int main()
{
    struct sl_list *li = (struct sl_list *)malloc(sizeof(struct sl_list));
    print(li);
    delete (li, 0);
    append(li, 'a');
    insert(li, '\"', 0);
    append(li, 'd');
    print(li);
    delete (li, 0);
    print(li);
    insert(li, 'i', 2);
    print(li);
}