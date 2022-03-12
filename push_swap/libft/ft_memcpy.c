/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:20:49 by slight            #+#    #+#             */
/*   Updated: 2021/10/13 16:07:59 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (dst);
}
