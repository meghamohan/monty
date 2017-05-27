#include "monty.h"
#include <string.h>
#define BUFFER 1024

int push_node(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		return(0);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
	return(1);
}

int checkIfPush(char *tokens, stack_t **stck, int line_number)
{
	int i;
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (tokens[0] == '-' && i == 0)
			continue;
		if (isdigit(tokens[i]) == 0)
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	if (!stck)
		printf("head null from checkifPush\n");	
	if (push_node(stck, atoi(tokens)))
	{	
		return (1);
	}				
	return (0);
}


int checkIfOpcode(char *tokens, stack_t **stck, int line_number)
{
	instruction_t opcodes[] = {
		{"pall", printAll},
		{"pint", printFirst},
		{"pop", popNode},
		{"swap", swapNode},
		{"add", addFirst},
		{"nop", nopNode},
		{"sub", subNode},
		{"mul", mulNode},
		{"div", divNode},
		{"mod", modNode},
		{NULL, NULL}
	};
	int i = 0;
	while ((opcodes + i)->opcode)
	{
		if (!strcmp(tokens, (opcodes + i)->opcode))
		{
			(opcodes + i)->f(stck, line_number);
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	FILE *source;
	size_t len = 0;
	char *line = NULL, *tokens = NULL;
	int line_number = 0, flag;
	stack_t *stck;

	stck = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	source = fopen(argv[1], "r");
	if (!source)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while (getline(&line, &len, source) != -1)
	{
		flag = 0;
                line_number++;
		tokens = strtok(line, " \t\n");
		while(tokens && !flag) {
			if (!strcmp(tokens,"push"))
			{
				tokens = strtok(NULL, " \t\n");
				if (checkIfPush(tokens, &stck, line_number))
					flag = 1;
			}
			else
			{
				if (checkIfOpcode(tokens, &stck, line_number))
					flag = 1;

			}
			tokens = strtok(NULL, " \t\n");
		}
	}
	return (0);
}
