#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*void pushNode(stack_t **h, unsigned int line_number);*/
void printAll(stack_t **h, unsigned int line_number);
void printFirst(stack_t **h, unsigned int line_number);
void popNode(stack_t **h, unsigned int line_number);
void swapNode(stack_t **h, unsigned int line_number);
void addFirst(stack_t **h, unsigned int line_number);
void nopNode(stack_t **h, unsigned int line_number);
void subNode(stack_t **h, unsigned int line_number);
void mulNode(stack_t **h, unsigned int line_number);
void divNode(stack_t **h, unsigned int line_number);
void modNode(stack_t **h, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);

int pushNode(stack_t **head, int n);
int noOfNodes(stack_t **h);
int checkIfPush(char *tokens, stack_t **stck, int line_number);
int checkIfOpcode(char *tokens, stack_t **stck, int line_number);
void freeStack(stack_t **stack);
void errorCheck(int argc, char **argv);
#endif
