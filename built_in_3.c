#include "monty.h"
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
