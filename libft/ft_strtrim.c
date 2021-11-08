/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:24:37 by slight            #+#    #+#             */
/*   Updated: 2021/10/26 17:00:46 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char const	*check_begin(char const *s1, char const *set)
{
	int	f;
	int	i;

	f = 0;
	while (f == 0 && *s1)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == *s1)
			{
				f = 0;
				break ;
			}
			else
				f = 1;
			++i;
		}
		if (f == 0)
			++s1;
	}
	return (s1);
}

char const	*check_end(char const *s1, char const *set)
{
	int	f;
	int	i;

	f = 0;
	while (f == 0)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == *s1)
			{
				f = 0;
				break ;
			}
			else
				f = 1;
			++i;
		}
		if (f == 0)
			--s1;
	}
	return (s1);
}

char	*check_lols(char const *s1, int *f)
{
	char	*res;

	if (*s1 == '\0')
	{
		*f = 1;
		res = malloc(sizeof(char));
		*res = '\0';
		return (res);
	}
	return (NULL);
}

char	*if_set_null(char const *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1[i])
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	const char	*last;
	int			i;
	int			f;

	i = 0;
	f = 0;
	if (s1 == NULL)
		return (NULL);
	if (*set == '\0')
		return (if_set_null(s1));
	last = s1 + ft_strlen(s1) - 1;
	s1 = check_begin(s1, set);
	res = check_lols(s1, &f);
	if (f == 1)
		return (res);
	last = check_end(last, set);
	res = malloc(sizeof(char) * (int)(last - s1 + 2));
	if (res == NULL)
		return (NULL);
	while (s1 != last + 1)
		res[i++] = *s1++;
	res[i] = '\0';
	return (res);
}
