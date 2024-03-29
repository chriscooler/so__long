/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:11:19 by chchao            #+#    #+#             */
/*   Updated: 2021/09/24 12:44:22 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	ft_check_name(char *file, char const *ext)
{
	int	size_file;
	int	size_ext;

	size_file = ft_strlen(file);
	size_ext = ft_strlen(ext);
	if (size_file < size_ext)
		return (0);
	while (size_ext >= 0)
	{
		if (ext[size_ext] != file[size_file])
			return (0);
		size_ext--;
		size_file--;
	}
	return (1);
}

static	int	ft_check_walls(char **map, int line)
{
	t_check_map	var;

	var = (t_check_map){0};
	var.y = -1;
	while (map[++var.y])
	{
		var.x = -1;
		while (map[var.y][++var.x])
		{
			if (map[0][var.x] != '1' || map[line][var.x] != '1' || (map[var.y]
				[0] != '1' || map[var.y][ft_strlen(map[var.y]) - 1] != '1'))
				return (0);
			else if (map[var.y][var.x] == 'E')
				var.exit++;
			else if (map[var.y][var.x] == 'C')
				var.coltive++;
			else if (map[var.y][var.x] == 'P')
				var.player++;
			else if (map[var.y][var.x] != '1' && map[var.y][var.x] != '0')
				return (0);
		}
	}
	if (var.exit < 1 || var.player != 1 || var.coltive < 1)
		return (0);
	return (1);
}

static int	ft_print_next_line(t_window *win, char *file, int nbr_line)
{
	int		i;
	int		fd;
	char	*line;
	int		size_line;

	i = 0;
	fd = open(file, O_RDONLY);
	win->map = ft_calloc(sizeof(char *), nbr_line + 1);
	size_line = -1;
	while (get_next_line(fd, &line) > 0)
	{
		win->map[i] = ft_strdup(line);
		if (size_line == -1)
			size_line = (int)ft_strlen(win->map[i]);
		free (line);
		if ((int)ft_strlen(win->map[i]) != size_line)
			return (0);
		i++;
	}
	win->map[i++] = ft_strdup(line);
	free_line(line);
	close (fd);
	return (1);
}

static	int	count_line(int fd)
{
	char	*line;
	int		nbr_line;

	nbr_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nbr_line++;
		free (line);
	}
	nbr_line++;
	free_line(line);
	return (nbr_line);
}

int	ft_parsing(t_window *win, char *file)
{
	int			fd;
	int			nbr_line;

	fd = open(file, O_RDONLY);
	if (!ft_check_name(file, ".ber") || fd == -1)
	{
		printf("\e[0;33mError: Your maps is not found or is not format\n");
		exit (1);
	}
	nbr_line = count_line(fd);
	close(fd);
	if (nbr_line < 3)
	{
		printf("\e[0;34mError: Oops! Map Less than 3 lines or Empty\n");
		exit (1);
	}
	if (!ft_print_next_line(win, file, nbr_line)
		|| !ft_check_walls(win->map, nbr_line - 1))
	{
		printf("\e[0;33mError: Oops! Something wrong in your map\n");
		exit (1);
	}
	return (1);
}
