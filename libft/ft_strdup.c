#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len);
	str[len] = 0;
	return (str);
}
