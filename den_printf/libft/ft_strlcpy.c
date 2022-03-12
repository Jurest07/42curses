/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:08:51 by lis               #+#    #+#             */
/*   Updated: 2021/10/22 12:14:16 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, char const *src, size_t n)
{
	size_t	i;
	int		end;

	i = 0;
	end = 0;
	while (src[i] != '\0')
	{
		if (i + 1 < n)
			dst[i] = src[i];
		else if (!end)
		{
			if (n)
				dst[i] = '\0';
			end = 1;
		}
		++i;
	}
	if (!end && n)
		dst[i] = '\0';
	return (i);
}
