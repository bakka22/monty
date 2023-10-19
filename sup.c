#include "monty.h"
int is_num()
{
	int i = 0, is_n = 0;

	while (arg[i])
	{
		if (arg[i] >= 48 && arg[i] <= 57)
			is_n = 1;
		else
		{
			is_n = 0;
			break;
		}
		i++;
	}
	return (is_n);
}
void err()
{
	free_stack();
	fclose(strm);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case 2:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, command);
			break;
		case 3:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 4:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case 5:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case 6:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case 7:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case 8:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case 9:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case 10:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case 11:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case 12:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
	}
	free(command);
	command = NULL;
	free(buf);
	buf = NULL;
	exit(EXIT_FAILURE);
}
void free_stack()
{
	stack_t *tmp, *tmp2;
	tmp = tmp2 = top;
	while(tmp)
	{
		tmp = tmp->next;
		free(tmp2);
		tmp2 = tmp;
	}
}
