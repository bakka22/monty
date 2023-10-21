#include "monty.h"
/**
*mod - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum = 0;

	(void)line_number;
	tmp = *stack;
	if (!tmp || !(tmp->next))
	{
		err_code = 12;
		err();
	}
	if (tmp->n == 0)
	{
		err_code = 11;
		err();
	}
	sum = tmp->next->n % tmp->n;
	tmp->next->n = sum;
	tmp->next->prev = NULL;
	(*stack) = tmp->next;
	free(tmp);

}
/**
*pchar - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (!(stack) || !(*stack))
	{
		err_code = 14;
		err();
	}
	tmp = *stack;
	if (tmp->n < 0 || tmp->n > 127)
	{
		err_code = 13;
		err();
	}
	printf("%c\n", tmp->n);
}
/**
*pstr - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while(tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
*rotl - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	(void)line_number;

	tmp = tmp2 = (*stack);
	if (!tmp || !(tmp->next))
		return;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	(*stack) = tmp2->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	tmp2->next = NULL;
	(*stack)->prev = NULL;
}
/**
*rotl - monty command
*@stack: stack to work on
*@line_number: number of current line
*Retrun: nothing
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	(void)line_number;
	tmp = tmp2 = (*stack);
	if (!tmp || !(tmp->next))
		return;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp2->prev = tmp;
	(*stack) = tmp;
}
