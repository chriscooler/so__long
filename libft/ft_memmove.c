#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest;
	char			*source;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		while (n--)
			dest[n] = source[n];
	}
	else
	{
		while (i < n)
		{
			dest[i] = source [i];
			i++;
		}
	}
	return (dst);
}
