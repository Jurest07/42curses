/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:29:03 by slight            #+#    #+#             */
/*   Updated: 2021/12/07 15:32:34 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
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
	res = malloc(sizeof(char) * len_s + 2);
	if (res == NULL)
		return (NULL);
	while (i < len_s)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	res[i + 1] = '\0';
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
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 2));
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
	res[i + 1] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*dst;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		dst[i] = s[i];
		++i;
		--n;
	}
	dst[i] = '\0';
	return (dst);
}
