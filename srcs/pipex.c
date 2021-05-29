#include "pipex.h"

static int	run_command(char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	int		id;

	id = fork();
	if (id == 0)
		run_command(argv, envp);
	else
		printf("Hi, I'm the parent process\n");
	wait(NULL);
	printf("Hello from both processes\n");
	return (0);
}

static int	run_command(char **argv, char **envp)
{
	char	**split;
	int		argv_index;

	split = ft_split(argv[argv_index], ' ');
	execve(split[0], split, envp);
	return (1);
}
