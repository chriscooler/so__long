#include "../header/so_long.h"

void	free_line(char *line)
{
	free (line);
	line = NULL;
}
