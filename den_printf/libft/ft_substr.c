/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:55:58 by lis               #+#    #+#             */
/*   Updated: 2021/10/19 18:04:26 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*nvx_create_empty_string(void)
{
	char	*ss;

	ss = malloc(sizeof(char) * 1);
	if (ss)
		*ss = '\0';
	return (ss);
}

char	*ft_substr(char const *s, unsigned int beg, size_t len)
{
	char	*ss;
	int		i;
	int		l;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < beg + 1)
		return (nvx_create_empty_string());
	l = 0;
	while (l < (int)len && s[(int)beg + l])
		++l;
	ss = malloc(sizeof(char) * (l + 1));
	if (!ss)
		return (NULL);
	i = 0;
	while (i < l)
	{
		ss[i] = s[(int)beg + i];
		++i;
	}
	ss[i] = '\0';
	return (ss);
}
