#include "monty.h"
/**
*mode - change mode (stack, queue)
*@stack : ...
*@line_number : ...
*Return: nothing
*/
void mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	strcpy(mode_, command);
}
/**
*queue_push - change mode (stack, queue)
*Return: nothing
*/

void queue_push(void)
{
	stack_t *tmp, *new;

	tmp = top;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		err_code = 3;
		err();
	}
	new->n = atoi(arg);
	if (top == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		top = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
}

