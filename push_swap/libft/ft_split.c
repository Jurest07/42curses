/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:59:40 by slight            #+#    #+#             */
/*   Updated: 2022/03/05 00:12:42 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char const	*skip_sep(char const *s, char c)
{
	while (*s == c && *s)
		++s;
	return (s);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	f;

	f = 0;
	i = 0;
	s = skip_sep(s, c);
	while (*s)
	{
		f = 1;
		if (*s == c)
		{
			s = skip_sep(s, c);
			++i;
			f = 2;
			if (*s == '\0')
				break ;
		}
		else
			++s;
	}
	if (f == 1)
		++i;
	return (i);
}

int	fill_word(char ***res, char const *s, char c, int cword)
{
	int	len_word;
	int	i;

	i = 0;
	len_word = 0;
	while (*s != c && *s)
	{		
		++len_word;
		++s;
	}
	(*res)[cword] = (char *)malloc(sizeof(char) * (len_word + 1));
	if ((*res)[cword] == NULL)
		return (0);
	s = s - len_word;
	while (i < len_word)
	{
		(*res)[cword][i] = s[i];
		++i;
	}
	(*res)[cword][i] = '\0';
	return (len_word);
}

char	**free_res(char **res, int count)
{
	while (count >= 0)
	{
		free(res[count]);
		--count;
	}
	free(res);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count_word;
	int		count_skip;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	count_word = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (res == NULL)
		return (NULL);
	while (i < count_word)
	{
		s = skip_sep(s, c);
		count_skip = fill_word(&res, s, c, i);
		if (count_skip == 0)
			return (free_res(res, i - 1));
		s = s + count_skip;
		++i;
	}	
	res[i] = NULL;
	return (res);
}
