/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akodos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:23:52 by akodos            #+#    #+#             */
/*   Updated: 2021/10/22 12:13:18 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	len;
	int		end;

	len = 0;
	end = 0;
	while (dst[len] && len < size)
		++len;
	while (*src)
	{
		if (len + 1 < size)
			dst[len] = *src;
		else if (!end && len < size)
		{
			dst[len] = '\0';
			end = 1;
		}
		++src;
		++len;
	}
	if (!end && len < size)
		dst[len] = '\0';
	return (len);
}
