#include "monty.h"

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

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	err_code = 0;
}
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
