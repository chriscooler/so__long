#include "../header/so_long.h"

int	ft_get_all(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
