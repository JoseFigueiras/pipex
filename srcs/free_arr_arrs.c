#include "pipex.h"

void	ft_free_arr_arrs(char ***arrs)
{
	int	i;

	i = -1;
	while (arrs[++i])
		freearrays(arrs[i]);
	free(arrs);
	arrs = NULL;
}
