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
	switch (err_code)
	{
		case 1:
		fprintf(stderr, "L%d: usage: push integer\n", line);
		break;
	}
	exit(EXIT_FAILURE);
}
