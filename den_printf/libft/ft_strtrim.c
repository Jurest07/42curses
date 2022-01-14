/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:57:14 by lis               #+#    #+#             */
/*   Updated: 2021/10/19 18:05:14 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char const	*b;
	char const	*e;
	char		*ss;

	if (!s || !set)
		return (NULL);
	b = s;
	e = s + ft_strlen(s);
	while (*b && ft_strchr(set, *b))
		++b;
	while (e != b && ft_strchr(set, e[-1]))
		--e;
	ss = malloc(sizeof(char) * (e - b + 1));
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, b, e - b + 1);
	return (ss);
}
