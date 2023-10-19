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
