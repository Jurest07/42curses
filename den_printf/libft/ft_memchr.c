/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:27:25 by lis               #+#    #+#             */
/*   Updated: 2021/10/04 19:23:28 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void const *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == *(unsigned char *)&c)
			return ((void *)s);
		s = (unsigned char *)s + 1;
	}
	return (NULL);
}
