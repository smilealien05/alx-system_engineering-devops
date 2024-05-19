#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * inf_while - Run an infinite loop
 *
 * Return: always 0.
 */

int inf_while(void)
{
	while(1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - create 5 zombie processes.
 * Return; always 0.
 */

int main(void)
{
	pid_t pid;
	char count = 0;
	while (count < 5)
	{
		pid = fork();
		if(pid > 0)
		{
			printf("Zombie process created, PID:%d\n", pid);
			sleep(1);
			count++;
		}
		else
			exit(0);
	}
	inf_while();
	return (EXIT_SUCCESS);
}
