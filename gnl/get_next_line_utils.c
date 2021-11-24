#include <unistd.h>

size_t ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		len_s;
	char	*res;
	int		i;

	i = 0;
	len_s = ft_strlen(s);
	res = malloc(sizeof(char) * len_s + 1);
	if (res == NULL)
		return (NULL);
	while (i < len_s)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (res == NULL)
		return (NULL);
	while (i < len_s1)
	{
		res[i] = s1[i];
		++i;
	}
	while (i < len_s1 + len_s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	while (c > 256)
		c = c - 256;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
