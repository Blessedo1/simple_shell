#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point for UNIX command line interpreter
 *
 * Return: return 0
 */
int main(void)
{
	while (1)
	{
		printf("ragnarhack@DESKTOP$ \n");
		
		char *command;
		size_t size;

		ssize_t read = getline(&command, &size, stdin);
		if (read == -1)
		{
			printf("ERROR: NOT A COMMAND");
			return (1);
		}

		char *token;
		const char delimiter[] = " ";

		token = strtok(command, delimiter);

		pid_t val;
		char *const* argv[1];

		val = fork();
		if (val == -1)
		{
			return (-1);
		}
		if (val == 0)
		{
			execve(token, argv[0], NULL);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
