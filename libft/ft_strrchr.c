/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:51:24 by slight            #+#    #+#             */
/*   Updated: 2021/10/26 14:31:22 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	while (c > 256)
		c = c - 256;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	s = s + len - 1;
	while (len > 0)
	{
		if (*s == c)
			return ((char *)s);
		--s;
		--len;
	}
	return (NULL);
}
