#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void free_stack(void);
void mode(stack_t **stack, unsigned int line_number);
void queue_push(void);
void rotr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div2(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void built_ins(void);
extern FILE *strm;
extern stack_t *top;
extern int line;
extern char mode_[6];
extern char *buf, *command, *arg;
extern instruction_t ls[];
extern int err_code;
extern char *built[];
void err(void);
int is_num(void);
#endif
