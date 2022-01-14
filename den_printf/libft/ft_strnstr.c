/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:38:23 by lis               #+#    #+#             */
/*   Updated: 2021/10/19 18:10:58 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

static int	nvx_startswith(char const *s, char const *ss)
{
	while (*s && *ss && *s == *ss)
	{
		++s;
		++ss;
	}
	return (!*ss);
}

char	*ft_strnstr(char const *s, char const *ss, size_t n)
{
	size_t	sslen;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	sslen = ft_strlen(ss);
	if (slen < n)
		n = slen;
	if (n < sslen)
		return (NULL);
	i = 0;
	while (i <= n - sslen)
	{
		if (nvx_startswith(s + i, ss))
			return ((char *)s + i);
		++i;
	}
	return (NULL);
}
