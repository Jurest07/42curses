/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:13:57 by lis               #+#    #+#             */
/*   Updated: 2021/10/04 19:23:02 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	nvx_memcpy_straight(void *dst, void const *src, size_t n)
{
	while (n--)
	{
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}
}

static void	nvx_memcpy_reverse(void *dst, void const *src, size_t n)
{
	src = (char *)src + n - 1;
	dst = (char *)dst + n - 1;
	while (n--)
	{
		*(char *)dst = *(char *)src;
		dst = (char *)dst - 1;
		src = (char *)src - 1;
	}
}

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	if (src < dst && dst < src + n)
		nvx_memcpy_reverse(dst, src, n);
	else if (dst != src)
		nvx_memcpy_straight(dst, src, n);
	return (dst);
}
