#include "monty.h"
stack_t *top = NULL;
int line = 0;
char o_code[] = {1, 2};
char *buf = NULL, *command = NULL, *arg = NULL;
instruction_t pu = {&(o_code[0]), &push},
pa = {&(o_code[1]), &pall};
int err_code = 0;
FILE *strm = NULL;
char *built[] = {"push", "pall"};
instruction_t *ls[] = {&pu, &pa};
void filter(void)
{
	int i = 0, cp = 1, j = 0, x;

	x = strlen(buf);
	command = malloc(sizeof(char) * x + 1);
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
	while (getline(&buf, &n, strm) != -1)
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
	}
	free_stack();
	free(buf);
	buf = NULL;
	fclose(strm);
	return (0);
}

void built_ins()
{
	int b_code[] = {1, 2};
	int i = 0, j = 0;
	void (*fn_ptr)(stack_t **stack, unsigned int line_number);
	while (built[i])
	{
		if (strcmp(command, built[i]) == 0)
		{
			while(ls[j])
			{
				if (*((ls[j])->opcode) == (char)(b_code[i]))
				{
					fn_ptr = (ls[j])->f;
					(fn_ptr)(&top, line);
					break;
				}
				j++;
			}
			break;
		}
		i++;
	}
}
