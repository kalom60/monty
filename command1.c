#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **doubly, unsigned int cline)
{
    int n, j;

    if (!allin.arg)
    {
        dprintf(2, "L%u: ", cline);
        dprintf(2, "usage: push integer\n");
        free_allin();
        exit(EXIT_FAILURE);
    }

    for (j = 0; allin.arg[j] != '\0'; j++)
    {
        if (!isdigit(allin.arg[j]) && allin.arg[j] != '-')
        {
            dprintf(2, "L%u: ", cline);
            dprintf(2, "usage: push integer\n");
            free_allin();
            exit(EXIT_FAILURE);
        }
    }

    n = atoi(allin.arg);

    if (allin.lifo == 1)
        add_dnodeint(doubly, n);
    else
        add_dnodeint_end(doubly, n);
}