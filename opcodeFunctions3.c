#include "monty.h"

/**
 * nopNode - function that does nothing
 * @h: pointer to head node of the stack
 * @line_number: line number of the file
 * Return: nothing
 */
void nopNode(stack_t **h, __attribute__((unused)) unsigned int line_number)
{
	(void)h;
}

/**
 * pushNode - push function
 * @head: stack location
 * @n: value to be pushed to stack
 * Return: 1 if success 0 if not
 */
int pushNode(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
	return (1);
}

/**
 * pchar - function to prints the char at the top of the stack,
 * followed by a new line
 * @head: pointer to head node of the stack
 * @line_number: line number of the file
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (*head)
	{
		if ((((*head)->n) < 0) || (((*head)->n) > 127))
		{
			printf("L%d: can't pchar, value out of range\n",
			       line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			putchar((*head)->n);
			putchar('\n');
		}
	}
	else
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

