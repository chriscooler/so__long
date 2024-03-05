#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*last_occurrence;

	last_occurrence = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			last_occurrence = (char *)&str[i];
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (last_occurrence);
}
