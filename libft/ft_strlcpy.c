/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:25:54 by slight            #+#    #+#             */
/*   Updated: 2021/10/13 16:09:49 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	int	len_src;
	int	i;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0 || sizeof(dst) == 0)
		return (len_src);
	while ((unsigned long) i < size - 1 && *src)
	{
		*dst = *src;
		++dst;
		++src;
		++i;
	}
	*dst = '\0';
	return (len_src);
}
