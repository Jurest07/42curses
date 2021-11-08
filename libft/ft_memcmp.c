/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:41:22 by slight            #+#    #+#             */
/*   Updated: 2021/10/26 18:08:34 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*c1 > *c2)
			return (*c1 - *c2);
		if (*c1 < *c2)
			return (*c1 - *c2);
		++c1;
		++c2;
		--n;
	}
	return (0);
}
