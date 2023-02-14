#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define foreach(var, begin)            \
{                                      \
    Node *iterator = begin;            \
    while (iterator != NULL)           \
    {                                  \
        int32_t var = iterator->value; \
        iterator = iterator->next;
#define endforeach() }}

typedef struct Node Node;

struct Node
{
    int32_t value;
    Node    *preview;
    Node    *next;
};

void FreeNodes(Node **head)
{
    Node *node = *head;

    while (node == NULL)
    {
        Node *temp = node;
        node = node->next;
        free(temp);
    }

    *head = NULL;
}

int32_t main()
{
    Node *head = NULL;
    Node **index = &head;
    size_t count;
    int32_t number;

    printf("How many nodes do you want?\n> ");
    scanf("%lu", &count);

    for (size_t i = 0 ; i < count ; ++i)
    {
        printf("It: %lu\n", i);
        *index = malloc(sizeof(Node));

        Node *temp = &(**index);

        (**index).value = i + 1;

        if(i == 0)
        {
            (**index).preview = NULL;
        }
        else
        {
            *index = (**index).next;
            (**index).preview = temp;
        }
    }

    // foreach(number, head)
    // {
    //     printf("Value: %d", number);
    // }
    // endforeach()

    FreeNodes(&head);

    return EXIT_SUCCESS;
}