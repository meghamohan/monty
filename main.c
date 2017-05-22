#include "monty.h"
#include <string.h>
#define BUFFER 1024

int num = 0;
int main(int argc, char **argv)
{
	FILE *source;
	size_t len = 0;
	char *line = NULL, *tokns = NULL;
	int line_number = 0;
	stack_t **stck;

//	buff = malloc(sizeof(char) * BUFFER);
	if (argc != 2)
	{
		printf("Error:File to be copied not given\n");
		exit(97);
	}
	if (argv[1] == NULL)
	{
		printf("Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	source = fopen(argv[1], "r");
	if (!source)
	{
		printf("Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	while ((len = getline(&line, &len, source)) != -1)
	{
		tokns = strtok(line, " \t\n");
		printf("-------------token = %s-----------\n",tokns);
		if (tokns == NULL)
		{
			printf("Error: malloc failed\n");
			break;
		}
		if (!strcmp(tokns,"push"))
		{
			tokns = strtok(NULL, " \t\n");
			printf("here token=%s\n",tokns);
			if (tokns)
				num = atoi(tokns);
			printf("num=%d\n",num);
		}
		else
		{
			instruction_t opcodes[] = {
				{"push", pushNode},
				{"pall", printAll},
				{"pint", printFirst},
				{"pop", popNode},
				{"swap", swapNode},
				{"add", addFirst},
				{"nop", nopNode},
				{NULL, NULL}
			};
			int i = 0;
			while ((opcodes + i)->opcode)
			{
				if (!strcmp(tokns, (opcodes + i)->opcode))
				{
					(opcodes + i)->f(stck, line_number);
				}
				i++;
			}

		}
		printf("----------tokens = %s, num = %d--------\n",tokns, num);
	}






}
