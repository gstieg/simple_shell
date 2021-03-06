#include "shell.h"
/**
*main - program that creates a prompt, recieves input and calls
*forking function when needed.
*Return: Always zero
*/
int main(void)
{
	char *buf = NULL;
	char *e = "exit\n";
	char *env = "env\n";
	size_t l = 0;
	ssize_t c = 0;
	int i = 0;

	while (1)
	{
		i = isatty(STDIN_FILENO);
		if (i == 1)
			write(STDOUT_FILENO, "$ ", 2);
		c = getline(&buf, &l, stdin);
		if (c == -1)
		{
			if (i == 1)
				write(STDOUT_FILENO, "\n", 1);
			free(buf);
			exit(0);
		}
		if (_strcmp(buf, e) == 0)
		{
			free(buf);
			exit(0);
		}
		if (_strcmp(buf, env) == 0)
			printenv();
		else if (c > 1)
		{
			buf[c - 1] = '\0';
			_forkIt(buf);
		}
	}
	return (0);
}
