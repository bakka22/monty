#include "monty.h"
#include "sub.h"
/**
*sup - ...
*@arc : ...
*@arv : ...
*Return:nothing
*/
void sup(int arc, char **arv)
{
	char err1[] = "USAGE: monty file\n";
	char err2[] = "Error: Can't open file ";

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
}
/**
*filter - remove heading spaces from input
*Retrun: nothing
*/
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
	while (buf[i])
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
/**
*main - entery point
*@arc : arguments count
*@arv : arguments vector
*Return: 0 on success else otherwise
*/
int main(int arc, char **arv)
{
	size_t n = 0;
	ssize_t y = 0;

	strcpy(mode_, "stack");
	sup(arc, arv);
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
	/*free(mode_);*/
	buf = NULL;
	fclose(strm);
	return (0);
}
/**
*built_ins - manage built in functions
*Return: nothing
*/
void built_ins(void)
{
	int ck = 0, ck2 = 1;
	int i = 0;
	void (*fn_ptr)(stack_t **stack, unsigned int line_number) = NULL;

	if (command[0] == '#')
		return;
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
