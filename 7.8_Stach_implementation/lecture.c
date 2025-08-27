// STACK REALIZATION:

#include <stdio.h>
#include <stdlib.h>

typedef struct tag_node // STACK NODE
{
    int data;
    struct tag_node *next;
} NODE;

NODE *push(NODE *top, int data) // FUNCTION ADD NODE TO STACK
{
    NODE *ptr = malloc(sizeof(NODE));
    ptr->data = data;
    ptr->next = top;

    return ptr;
}

NODE *pop(NODE *top) // FUNCTION DELETE ALL NODES FRON STACK
{
    if (top == NULL)
        return top;

    printf("DELETED: %d\n", top->data);
    NODE *ptr_next = top->next;
    free(top);

    return ptr_next;
}

void show(const NODE *top) // FUNCTION SHOW ALL STACK NODES
{
    const NODE *current = top;
    while (current != NULL)
    {
        printf("NODE DATA: %d\n", current->data);
        current = current->next;
    }
}

int main(void)
{
    NODE *top = NULL; // pointer at the first NODE in stack
    
    for (int i = 1; i < 6; ++i) // Add nodes to stack
        top = push(top, i);

    show(top); // Show nodes

    while (top) // Clear stack
        top = pop(top);

    return 0;
}
