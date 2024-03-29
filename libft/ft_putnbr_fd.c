#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	char		c;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = num * (-1);
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	write (fd, &c, 1);
}
