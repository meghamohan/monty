#include "monty.h"
#include <string.h>

/**
 * checkIfPush - check if the opcode if push
 * @tokens: string containing the argument to be pushed
 * @stck: pointer to stack
 * @line_number: line number of push opcode in the file
 * Return: 1 if success , 0 if not
 */
int checkIfPush(char *tokens, stack_t **stck, int line_number)
{
	int i;

	if (!tokens)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
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
	if (pushNode(stck, atoi(tokens)))
	{
		return (1);
	}
	return (0);
}

/**
 * checkIfOpcode - checks if the command is an opcode
 * @stck: stack pointer
 * @line_number: line number of command in the file
 * @tokens: command to check
 * Return: 1 if success, 0 if not
 */
int checkIfOpcode(char *tokens, stack_t **stck, int line_number)
{
	int i = 0;

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
		{"pchar", pchar},
		{NULL, NULL}
	};
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


/**
 * errorCheck - checks for erge cases while passing montyfile
 * @argc: number of arguemnts
 * @argv: files
 * Return: nothing
 */
void errorCheck(int argc, char **argv)
{
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
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: files
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *source;
	size_t len = 0;
	char *line = NULL, *tokens = NULL;
	int line_number = 0, flag;
	stack_t *stck;

	stck = NULL;
	errorCheck(argc, argv);
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
		while (tokens && !flag)
		{
			if (!tokens || !(strncmp(tokens, "#", 1)))
				continue;
			if (!strcmp(tokens, "push"))
			{
				tokens = strtok(NULL, " \t\n");
				if (checkIfPush(tokens, &stck, line_number))
					flag = 1;
			}
			else if (checkIfOpcode(tokens, &stck, line_number))
				flag = 1;
			else
			{
				printf("L%d: unknown instruction %s\n", line_number, tokens);
				exit(EXIT_FAILURE);
			}
			tokens = strtok(NULL, " \t\n");
		}
	}
	free(line); freeStack(&stck); fclose(source); return (0);
}
