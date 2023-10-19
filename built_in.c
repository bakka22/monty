#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	if (arg == NULL || !(is_num()))
	{
		err_code = 1;
		err();
	}
	new = malloc(sizeof(stack_t));
        new->n = atoi(arg);
        if ((*stack) == NULL)
        {
                new->next = NULL;
                new->prev = NULL;
                (*stack) = new;
        }
        else
        {
                (*stack)->prev = new;
                new->next = (*stack);
                new->prev = NULL;
                (*stack) = new;
        }
}
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

        (void)line_number;
        if ((*stack) == NULL)
                return;
        tmp = (*stack);
        while (tmp)
        {
                printf("%d\n", tmp->n);
                tmp = tmp->next;
        }
}