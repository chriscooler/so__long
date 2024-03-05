#include "../header/so_long.h"

void	ft_print_map_exit(t_window *win, t_check_map var)
{
	if (ft_get_all(win->map))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->grass.img, var.y * 50, var.x * 50);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->open.img, var.y * 50, var.x * 50);
	}
	else
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->grass.img, var.y * 50, var.x * 50);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->close.img, var.y * 50, var.x * 50);
	}
}
