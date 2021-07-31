#include "pipex.h"

char	*str_join_free(char **beg, char **end)
{
	char	*tmp;

	tmp = ft_strjoin(*beg, *end);
	free(*beg);
	free(*end);
	return (tmp);
}
