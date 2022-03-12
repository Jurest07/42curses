/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:37:10 by slight            #+#    #+#             */
/*   Updated: 2021/10/12 17:42:46 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len_s;
	char	*res;
	int		i;

	i = 0;
	len_s = ft_strlen(s);
	res = malloc(sizeof(char) * len_s + 1);
	if (res == NULL)
		return (NULL);
	while (i < len_s)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
