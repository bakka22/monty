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
	stack_t *tmp = *stack;

	(void)line_number;

	if (!tmp)
	{
		err_code = 14;
		err();
	}
	if (tmp->n < 32 || tmp->n > 126)
	{
		err_code = 13;
		err();
	}
	putchar(tmp->n);
	putchar('\n');
}
