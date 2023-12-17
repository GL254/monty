#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: actual arguments
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	char *err = "USAGE: monty file", *err_msg = "Error: Can't open file ";
	instruction_t func[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"add", _add}, {"sub", _sub},
		      {"mul", _mul}, {"div", _div}, {"rotr", rotr},
		      {"swap", _swap}};
	FILE *file = NULL;
	size_t len_err = strlen(err_msg), len_argv = 0, size = 0;

	if (argc != 2)
	{
		write(STDERR_FILENO, err, strlen(err));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(argv[1], "r");
		len_argv = strlen(argv[1]);
		if (file == NULL)
			open_error(argv[1], err_msg, len_err, len_argv);
		size = sizeof(func) / sizeof(func[0]);
		control(file, func, size);
	}
	return (0);
}
