#include "../header/so_long.h"

void	ft_print_map_flower(t_window *win, t_check_map var)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->grass.img, var.y * 50, var.x * 50);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->flower.img, var.y * 50, var.x * 50);
}
