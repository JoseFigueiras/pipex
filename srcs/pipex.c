#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	//if (argc < 5)
	//{
	//	printf("Need more args bro\n");
	//	return (0);
	//}
	
	int		id;
	int		argv_index;
	char	**split;

	id = fork();
	if (id == 0)
		run_command(argv, envp);
	else
		printf("Hi, I'm the parent process\n");
	wait(NULL);
	printf("Hello from both processes\n");
	return (0);
}


	split = ft_split(argv[argv_index], ' ');
	execve(split[0], split, envp);
