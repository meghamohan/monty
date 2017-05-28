#include "monty.h"

/**
 * printAll - function that prints all integers in the stack
 * @head: pointer to head node of the stack
 * @line_number: line number of the file
 * Return: nothing
 */
void printAll(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	stack_t *h;

	if (*head == NULL || head == NULL)
		return;
	h = *head;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}


/**
 * printFirst -  prints the value at the top of the stack,
 * followed by a new line.
 * @h: pointer to head node of the stack
 * @line_number: line number of the file
 * Return: nothing
 */
void printFirst(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		return;
	}
	else
		printf("%d\n", (*h)->n);
}


/**
 * popNode - remove item at the top of stack
 * @head: pointer to head node of the stack
 * @line_number: line number of the file
 * Return: nothing
 */
void popNode(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		return;
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}


/**
 * swapNode - swaps the top two elements of the stack.
 * @h: pointer to head node of the stack
 * @line_number: line number of the file
 * Return: nothing
 */
void swapNode(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	if (noOfNodes(h) < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		return;
	}

	tmp = *h;
	*h = tmp->next;
	tmp->next = (*h)->next;
	(*h)->next = tmp;
	tmp->prev = *h;
	(*h)->prev = NULL;
	(tmp->next)->prev = tmp;
}

/**
 * addFirst - adds the top two elements of the stack
 * @h: pointer to head node of the stack
 * @line_number: line number of the file
 * Return: nothing
 */
void addFirst(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;
	int sum;

	if (noOfNodes(h) < 2)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		return;
	}
	tmp = (*h)->next;
	sum = (*h)->n + tmp->n;
	tmp->n = sum;
	popNode(h, line_number);

}
