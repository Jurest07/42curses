/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:07:33 by slight            #+#    #+#             */
/*   Updated: 2021/10/13 17:36:45 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		len_s;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	res = malloc(sizeof(char) * len_s + 1);
	if (res == NULL)
		return (NULL);
	while (i < len_s)
	{
		res[i] = f(i, s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
