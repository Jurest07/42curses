/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:08:03 by lis               #+#    #+#             */
/*   Updated: 2021/10/06 11:17:58 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(char const *lhs, char const *rhs, size_t n)
{
	while ((*lhs || *rhs) && n)
	{
		if (*lhs != *rhs)
			return ((unsigned char)*lhs - (unsigned char)*rhs);
		++lhs;
		++rhs;
		--n;
	}
	return (0);
}
