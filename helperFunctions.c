#include "monty.h"

/**
 * noOfNodes - to count the number of nodes in stack
 * @h: stack
 * Return: count
 */
int noOfNodes(stack_t **h)
{
	stack_t *temp;
	int n; /* counter for number of elements */

	temp = *h;
	n = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}

	return (n);
}

/**
 * freeStack - frees the stack
 * @stack: stack to be freed
 * Return: void
 */
void freeStack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
