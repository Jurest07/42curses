/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:32:24 by slight            #+#    #+#             */
/*   Updated: 2021/10/26 15:38:20 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*res;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	res = (void *)malloc(size * num);
	if (res)
		ft_bzero (res, num * size);
	if (res == NULL)
		return (NULL);
	return (res);
}
