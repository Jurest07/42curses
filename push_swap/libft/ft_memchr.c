/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:35:48 by slight            #+#    #+#             */
/*   Updated: 2021/10/26 12:52:00 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*d;

	d = (char *)s;
	while (c > 256)
		c = c - 256;
	while (n > 0)
	{
		if (*d == c)
			return (d);
		++d;
		--n;
	}
	return (NULL);
}
