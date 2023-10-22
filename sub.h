#ifndef SUB_H
#define SUB_H
stack_t *top = NULL;
int line = 0;
char *buf = NULL, *command = NULL, *arg = NULL;
int err_code = 0;
char mode_[6];
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
{"pchar", &pchar},
{"pstr", &pstr},
{"rotl", &rotl},
{"rotr", &rotr},
{"stack", &mode},
{"queue", &mode},
{NULL, NULL}
};
#endif
