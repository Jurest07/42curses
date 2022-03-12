/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:49:23 by slight            #+#    #+#             */
/*   Updated: 2021/10/26 18:27:36 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	check_all_little(const char *big, const char *little, size_t len)
{
	if (len < ft_strlen(little))
		return (0);
	while (*little)
	{
		if (*big != *little)
			return (0);
		++little;
		++big;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	len_little;

	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (len > 0 && *big)
	{
		if (check_all_little(big, little, len))
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}
