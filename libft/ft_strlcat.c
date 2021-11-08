/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:37:51 by slight            #+#    #+#             */
/*   Updated: 2021/10/26 16:53:56 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	out;

	i = 0;
	i = ft_strlen(dst);
	out = i;
	if (out > size || (dst[0] == '\0' && size == 0))
		return (size + ft_strlen(src));
	while (i < size - 1 && src[i - out])
	{
		dst[i] = src[i - out];
		++i;
	}
	dst[i] = '\0';
	return (out + ft_strlen(src));
}
