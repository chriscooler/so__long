#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned long	size;
	int				fsize;
	int				i;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(&s[start]);
	if (size >= len)
		fsize = len;
	else
		fsize = size;
	str = (char *)malloc(sizeof(char) * fsize + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < fsize)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[fsize] = 0;
	return (str);
}
