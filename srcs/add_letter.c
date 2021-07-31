#include "pipex.h"

void	add_letter(char c, char **buffer, bool start)
{
	char	*new;

	new = malloc(sizeof(char) * 2);
	if (!new)
		return ;
	new[0] = c;
	new[1] = '\0';
	if (*buffer == NULL)
		*buffer = new;
	else if (!start)
		*buffer = str_join_free(buffer, &new);
	else
		*buffer = str_join_free(&new, buffer);
}
