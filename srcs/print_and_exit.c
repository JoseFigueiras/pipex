#include "pipex.h"

void	print_and_exit(char *str, int error_code)
{
	ft_putstr_fd(str, 1);
	exit(error_code);
}
