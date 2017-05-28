#include "monty.h"


/**
 * subNode - subtracts the top element of the stack
 *  from the second top element of the stack.
 * @h: pointer to stack
 * @line_number: line number of file
 * Return: void
 */
void subNode(stack_t **h, unsigned int line_number)
{
	int a, b, result;

	if (noOfNodes(h) < 2 || h == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*h)->n;
	b = (*h)->next->n;
	result = b - a;
	popNode(h, line_number);
	(*h)->n = result;
}

/**
 * mulNode - multiplies the second top element of the stack
 * with the top element of the stack
 * @h: pointer to stack
 * @line_number: line number of push opcode in the file
 * Return: nothing
 */
void mulNode(stack_t **h, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (noOfNodes(h) < 2 || h == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*h)->n;
	b = (*h)->next->n;

	result = a * b;
	popNode(h, line_number);
	(*h)->n = result;
}

/**
 * divNode - divides the second top element of the stack
 * by the top element of the stack
 * with the top element of the stack
 * @h: pointer to stack
 * @line_number: line number of push opcode in the file
 * Return: nothing
 */
void divNode(stack_t **h, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (noOfNodes(h) < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*h)->n;
	b = (*h)->next->n;
	if (!b)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = a / b;
	popNode(h, line_number);
	(*h)->n = result;
}

/**
 * modNode - computes the rest of the division of the second
 *  top element of the stack by the top element of the stack.
 * by the top element of the stack
 * with the top element of the stack
 * @h: pointer to stack
 * @line_number: line number of push opcode in the file
 * Return: nothing
 */
void modNode(stack_t **h, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (noOfNodes(h) < 2)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*h)->n;
	b = (*h)->next->n;

	result = a % b;
	popNode(h, line_number);
	(*h)->n = result;
}
