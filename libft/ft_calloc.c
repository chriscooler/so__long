#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	int		mem;

	mem = count * size;
	str = malloc (mem);
	if (!(str))
		return (NULL);
	ft_bzero(str, mem);
	return (str);
}
