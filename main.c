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

int main(int argc, char **argv)
{
	FILE *source;
	size_t len = 0;
	char *line = NULL, *tokens = NULL;
	int line_number = 0, num = 0, flag;
	stack_t *stck;

	stck = NULL;
//	buff = malloc(sizeof(char) * BUFFER);
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
	
	// len = getline(&line, &len, source)
	while (getline(&line, &len, source) != -1)
	{
		flag = 0;
                line_number++;
		tokens = strtok(line, " \t\n");
		while(tokens && !flag) {
		    	//printf("-------------token = %s-----------\n",tokens);
			if (!strcmp(tokens,"push"))
			{
				tokens = strtok(NULL, " \t\n");
				// printf("here token=%s\n",tokens);
				int status = 0;
				if (tokens)
				{
					num = atoi(tokens);
					status = push_node(&stck, num);
					flag = 1;
				}	
	//			printf("num=%d\t status = %d\n",num, status);
			}
			else
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
						(opcodes + i)->f(&stck, line_number);
						flag = 1;
					}
					i++;
				}

			}
			// Read next token.
			tokens = strtok(NULL, " \t\n");
			//	printf("----------tokens = %s, num = %d--------lineNum = %d\n",tokens, num, line_number);
		}
	}

}
