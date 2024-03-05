#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (i + j < n && haystack[i + j] == needle[j])
			{
				j++;
				if (needle[j] == 0)
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
