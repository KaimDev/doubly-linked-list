#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct Node Node;

struct Node
{
    int32_t value;
    Node *prev;
    Node *next;
};

void FreeNodes(Node *head)
{
    Node *node = head;

    while (node != NULL)
    {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;
    Node *last = NULL;
    size_t count;

    printf("How many nodes do you want?\n> ");
    scanf("%lu", &count);

    Node *prev_node = NULL;
    for (size_t i = 0; i < count; ++i)
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->value = i + 1;
        new_node->prev = prev_node;
        new_node->next = NULL;

        if (prev_node != NULL)
        {
            prev_node->next = new_node;
        }
        else
        {
            head = new_node;
        }

        prev_node = new_node;
    }

    for (Node *node = head ; node != NULL ; node = node->next)
    {
        printf("Value: %d\n", node->value);
        last = node;
    }

    puts("\nList in reverse");

    for (Node *node = last ; node != NULL ; node = node->prev)
    {
        printf("Value: %d\n", node->value);
    }

    FreeNodes(head);

    return EXIT_SUCCESS;
}