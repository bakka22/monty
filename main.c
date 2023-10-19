#include "monty.h"
stack_t *top = NULL;
int line = 0;
char *buf = NULL, *command = NULL, *arg = NULL;
int err_code = 0;
FILE *strm = NULL;
instruction_t ls[] = {
{"push", &push},
{"pall", &pall},
{"pint", &pint},
{"pop", &pop},
{"swap", &swap},
{"add", &add},
{"nop", &nop},
{"sub", &sub},
{"div", &div2},
{"mul", &mul},
{"mod", &mod},
{NULL, NULL}
};
/**void mall_ch()
{
	command = malloc(sizeof(char));
	if (command == NULL)
	{
		err_code = 3;
		err();
	}
	free(command);
	command = NULL;
}**/
void filter(void)
{
	int i = 0, cp = 1, j = 0, x;

	x = strlen(buf);
	command = malloc(sizeof(char) * x + 1);
	if (command == NULL)
	{
		err_code = 3;
		err();
	}
	command[x] = '\0';
	while(buf[i])
	{
		if ((buf[i] == ' ' || buf[i] == '\n') && cp)
		{
			i++;
			command[x - i] = '\0';
			continue;
		}
		cp = 0;
		command[j] = buf[i];
		i++;
		j++;
	}
}
int main(int arc, char **arv)
{
	char err1[] = "USAGE: monty file\n";
	char err2[] = "Error: Can't open file ";
	size_t n = 0;
	ssize_t y = 0;

	if (arc != 2)
	{
		write(STDERR_FILENO, err1, strlen(err1));
		exit(EXIT_FAILURE);
	}
	strm = fopen(arv[1], "r");
	if (strm == NULL)
	{
		write(STDERR_FILENO, err2, strlen(err2));
		write(STDERR_FILENO, arv[1], strlen(arv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	y = getline(&buf, &n, strm);
	if (buf == NULL)
	{
		err_code = 3;
		err();
	}
	while (y != -1)
	{
		line++;
		filter();
		strtok(command, "\t \n");
		arg = strtok(NULL, "\t \n");
		built_ins();
		free(command);
		command = NULL;
		free(buf);
		buf = NULL;
		arg = NULL;
		y = getline(&buf, &n, strm);
		if (buf == NULL)
		{
			err_code = 3;
			err();
		}
	}
	free_stack();
	free(buf);
	buf = NULL;
	fclose(strm);
	return (0);
}

void built_ins()
{
	int ck = 0, ck2 = 1;
	int i = 0;
	void (*fn_ptr)(stack_t **stack, unsigned int line_number) = NULL;
	while ((ls[i]).opcode != NULL)
	{
		if (strcmp(command, (ls[i]).opcode) == 0)
		{
			fn_ptr = (ls[i]).f;
			(fn_ptr)(&top, line);
			ck = 1;
			break;
		}
		i++;
	}
	for (i = 0; command[i]; i++)
	{
		if (command[i] == ' ' || command[i] == '\t' || command[i] == '\n')
			continue;
		else
		{
			ck2 = 0;
			break;
		}
	}
	if (!ck && !ck2)
	{
		err_code = 2;
		err();
	}
}
