#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*memory;

	i = 0;
	memory = (unsigned char *)s;
	while (i < n)
	{
		memory[i] = 0;
		i++;
	}
}
