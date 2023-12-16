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
		printf("ragnarhack@DESKTOP$ ");
		
		char *command = NULL;
		size_t size = 0;

		ssize_t read = getline(&command, &size, stdin);
		if (read == -1)
		{
			perror("ERROR: NOT A COMMAND");
			free(command);
			return (1);
		}
		command[strcspn(command, "\n")] = '\0';

		char *token;
		const char delimiter[] = " \n";

		token = strtok(command, delimiter);
		if (token == NULL)
		{
			free(command);
			continue;
		}


		pid_t val;
		char *argv[] = {token, NULL};

		val = fork();
		if (val == -1)
		{
			free(command);
			return (-1);
		}
		if (val == 0)
		{
			execve(token, argv, NULL);
			perror("not found");
			free(command);
			exit (1);
		}
		else
		{
			wait(NULL);
		}
		free(command);
	}
	return (0);
}
