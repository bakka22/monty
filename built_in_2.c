#include "monty.h"
/**
*add - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum = 0;

	(void)line_number;
	tmp = *stack;
	if (!tmp || !(tmp->next))
	{
		err_code = 7;
		err();
	}
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	tmp->next->prev = NULL;
	(*stack) = tmp->next;
	free(tmp);
}
/**
*nop - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	err_code = 0;
}
/**
*sub - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum = 0;

	(void)line_number;
	tmp = *stack;
	if (!tmp || !(tmp->next))
	{
		err_code = 8;
		err();
	}
	sum = tmp->next->n - tmp->n;
	tmp->next->n = sum;
	tmp->next->prev = NULL;
	(*stack) = tmp->next;
	free(tmp);

}
/**
*div2 - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void div2(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum = 0;

	(void)line_number;
	tmp = *stack;
	if (!tmp || !(tmp->next))
	{
		err_code = 9;
		err();
	}
	if (tmp->n == 0)
	{
		err_code = 11;
		err();
	}
	sum = tmp->next->n / tmp->n;
	tmp->next->n = sum;
	tmp->next->prev = NULL;
	(*stack) = tmp->next;
	free(tmp);

}
/**
*mul - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum = 0;

	(void)line_number;
	tmp = *stack;
	if (!tmp || !(tmp->next))
	{
		err_code = 10;
		err();
	}
	sum = tmp->n * tmp->next->n;
	tmp->next->n = sum;
	tmp->next->prev = NULL;
	(*stack) = tmp->next;
	free(tmp);

}
