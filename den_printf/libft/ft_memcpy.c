/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:57:56 by lis               #+#    #+#             */
/*   Updated: 2021/10/19 17:55:50 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	void	*p;

	if (!dst && !src)
		return (NULL);
	p = dst;
	while (n--)
	{
		*(char *)p = *(char *)src;
		p = (char *)p + 1;
		src = (char *)src + 1;
	}
	return (dst);
}
