/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:38:03 by lis               #+#    #+#             */
/*   Updated: 2021/10/18 21:36:21 by akodos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char const *s)
{
	int		len;
	char	*dup;

	len = 0;
	while (s[len])
		++len;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	len = 0;
	while (s[len])
	{
		dup[len] = s[len];
		++len;
	}
	dup[len] = '\0';
	return (dup);
}
