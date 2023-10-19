#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int ck = 1, i = 0;

	(void)line_number;
	while (built[i])
	{
		if (strcmp(built[i], arg) == 0)
		{
			ck = 0;
			break;
		}
		i++;
	}
	if ((arg == NULL || !(is_num())) && ck)
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