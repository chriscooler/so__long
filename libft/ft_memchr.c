#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}
