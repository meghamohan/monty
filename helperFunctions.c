#include "monty.h"

int noOfNodes(stack_t **h)
{
/*	int count;

	count = 0;
	if (h == NULL)
		return (0);
	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);*/

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
