/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:39:09 by lis               #+#    #+#             */
/*   Updated: 2021/10/19 18:00:54 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*dat;
	size_t	i;

	dat = malloc(n * size);
	if (!dat)
		return (NULL);
	i = 0;
	while (i < n * size)
	{
		*((unsigned char *)dat + i) = 0;
		++i;
	}
	return (dat);
}
