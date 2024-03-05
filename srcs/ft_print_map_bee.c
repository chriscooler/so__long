#include "../header/so_long.h"

void	ft_print_map_bee(t_window *win, t_check_map var)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->player.img, var.y * 50, var.x * 50);
	win->ps.x = var.x * 50;
	win->ps.y = var.y * 50;
}
