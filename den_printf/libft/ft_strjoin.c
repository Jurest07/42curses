/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:56:32 by lis               #+#    #+#             */
/*   Updated: 2021/10/19 18:04:55 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	len = s1len + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	ft_strlcpy(res + s1len, s2, len + 1 - s1len);
	return (res);
}
