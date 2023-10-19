#include "monty.h"
int is_num()
{
	int i = 0, is_n = 0;

	while (arg[i])
	{
		if (arg[i] >= 48 && arg[i] <= 57)
		{
			is_n = 1;
			break;
		}
		else
		{
			is_n = 0;
		}
		i++;
	}
	return (is_n);
}
void err()
{
	free(command);
	command = NULL;
	free(buf);
	buf = NULL;
	free_stack();
	fclose(strm);
	switch (err_code)
	{
		case 1:
		fprintf(stderr, "L%d: usage: push integer\n", line);
		break;
	}
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
