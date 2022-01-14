/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:57:40 by lis               #+#    #+#             */
/*   Updated: 2021/10/19 18:05:45 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static void	next_word(char const *s, char c, char const **b, char const **e)
{
	*b = s;
	while (**b && **b == c)
		++*b;
	*e = *b;
	while (**e && **e != c)
		++*e;
}

static char	**free_array(char **arr)
{
	char	**p;

	p = arr;
	while (*p)
		free(*p++);
	free(arr);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	char const	*b;
	char const	*e;
	int			count;

	count = 0;
	while (1)
	{
		next_word(s, c, &b, &e);
		if (b == e)
			return (count);
		s = e;
		++count;
	}
}

char	**ft_split(char const *s, char c)
{
	int			n;
	char		**words;
	char const	*b;
	char const	*e;
	char		**p;

	if (!s)
		return (NULL);
	n = count_words(s, c);
	words = malloc(sizeof(char *) * (n + 1));
	if (!words)
		return (NULL);
	words[n] = NULL;
	p = words;
	while (1)
	{
		next_word(s, c, &b, &e);
		if (b == e)
			return (words);
		*p = malloc(sizeof(char) * (e - b + 1));
		if (!*p)
			return (free_array(words));
		ft_strlcpy(*p++, b, e - b + 1);
		s = e;
	}
}
