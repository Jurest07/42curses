/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:33:32 by lis               #+#    #+#             */
/*   Updated: 2021/10/04 19:26:37 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(void const *lhs, void const *rhs, size_t n)
{
	while (n--)
	{
		if (*(char *)lhs != *(char *)rhs)
			return (*(unsigned char *)lhs - *(unsigned char *)rhs);
		lhs = (char *)lhs + 1;
		rhs = (char *)rhs + 1;
	}
	return (0);
}
