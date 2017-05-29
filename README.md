# 0x18. C - Stacks, Queues - LIFO, FIFO

This project aims at implementing an Interpreter for the scripting Language `Monty`, using C language. `Monty 0.98` is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Project Reqirements

- Allowed editors: vi, vim, emacs
- All files will be compiled on Ubuntu 14.04 LTS
- programs will be compiled with gcc 4.8.4 (C90) using the flags -Wall -Werror -Wextra and -pedantic
- README.md file, at the root of the folder of the project is mandatory
- code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

## How to compile

Monty interpreter will be compiled this way
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

## File Descriptions

- `monty.h` - This is the header file for the prject that contains all structs, functions and prototypes. 
- `main.c` - This is the entry point of the program where file is read, parsed and interpreted. The functions included are the following
	`main`: The entry point
	`checkIfPush`: check if the opcode if push
	`checkIfOpcode`: checks if the command is an opcode
	`errorCheck`: checks for edge cases while passing montyfile
- `opcodeFunction.c` - contains functions for executing opcode functions
	`printAll` - function for `pall` command that prints all integers in the stack
	`printFirst` -  function for `pint` opcode that prints the value at the top of the stack
	`popNode` - function for `pop` opcode that remove item at the top of stack
	`swapNode` - function for `swap` opcode that swaps the top two elements of the stack
	`addFirst` - function for `add` opcode that adds the top two elements of the stack
- `opcodeFunction2.c` - contains functions for executing opcode functions
	`subNode` - function for `sub` opcode that subtracts the top element of the stack
	`mulNode` - function for `mul` opcode that multiplies the second top element of the stack
	`divNode` - function for `diiv` opcode that divides the second top element of the stack
	`modNode` - function for `mod` opcode that computes the rest of the division of the second
- `opcodeFunction3.c` - contains functions for executing opcode functions
	`nopNode` - function for `nop` opcode that does nothing
	`pushNode` - function for `push` opcode that pushes an integer 
- `helperFunctions.c` - contains supproting functions for opcode functions
	`noOfNodes` - to count the number of nodes in stack
	`freeStack` - frees the stack
	
## Contributer

Megha Mohan: [github account](https://github.com/meghamohan), [twitter](https://twitter.com/meghamohan1989)
