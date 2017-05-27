#include "monty.h"

void subNode(stack_t **h, unsigned int line_number)
{
	int a, b, result;

	if (noOfNodes(h) < 2 || h == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
	 	return;
	}

	a = (*h)->n;
	b = (*h)->next->n;

	result = a - b;
	popNode(h, line_number);
	(*h)->n = result;
}

void mulNode(stack_t **h, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (noOfNodes(h) < 2 || h == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		printf("error in mul\n");
		return;
	}

	a = (*h)->n;
	b = (*h)->next->n;

	result = a * b;
	popNode(h, line_number);
	(*h)->n = result;
}

void divNode(stack_t **h, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (noOfNodes(h) < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		return;
	}

	a = (*h)->n;
	b = (*h)->next->n;

	result = a / b;
	popNode(h, line_number);
	(*h)->n = result;
}

void modNode(stack_t **h, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (noOfNodes(h) < 2)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		return;
	}

	a = (*h)->n;
	b = (*h)->next->n;

	result = a % b;
	popNode(h, line_number);
	(*h)->n = result;
}
