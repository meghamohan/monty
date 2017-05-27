#include "monty.h"

void printAll(stack_t **head, unsigned int __attribute__((unused))line_number)
{
        stack_t *h;

	printf("reached pall\n");
	if (*head == NULL)
		printf("head is null\n");
        h = *head;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}

}

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

void nopNode(stack_t **h, __attribute__((unused)) unsigned int line_number)
{
	(void)h;
}
