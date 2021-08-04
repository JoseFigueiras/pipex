#include "pipex.h"

static void	exec_child(char **paths, char **cmd, int *fd);

int	main(int argc, char *argv[], char **envp)
{
	char	***commands;
	int		fd[2];
	pid_t	pid;

	if (argc < 5)
		print_and_exit("Not enough args", 1);
	commands = parse_commands(argc, argv);
	file_to_stdin(argv[1]);
	if (pipe(fd) == -1)
		exit(20);
	pid = fork();
	if (pid == 0)
		exec_child(get_paths(envp, argv, 2), commands[0], fd);
	waitpid(pid, NULL, 0);
	pid = fork();
	if (pid == 0)
		write_to_file(argv[4], fd, get_paths(envp, argv, 3), commands[1]);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	free_arr_arrs(commands);
	return (0);
}

static void	exec_child(char **paths, char **cmd, int *fd)
{
	int	i;

	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	i = 0;
	while (paths[i])
		execve(paths[i++], cmd, NULL);
}
