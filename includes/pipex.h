#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/wait.h>

void	print_and_exit(char *str, int error_code);
char	***parse_commands(int argc, char **argv);
void	write_to_file(char *file_name, int *fd, char **paths, char **cmd);
char	**get_paths(char **envp, char **argv, int cmd_index);
void	file_to_stdin(char *file);

void	free_arr_arrs(char ***arrs);
void	add_letter(char c, char **buffer, bool start);
void	freearrays(char **array);
char	*str_join_free(char **beg, char **end);

#endif
