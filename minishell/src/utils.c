/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:14:27 by slight            #+#    #+#             */
/*   Updated: 2022/08/10 13:04:28 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

bool	ft_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (true);
		str++;
	}
	return (false);
}

bool	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (false);
		s1++;
		s2++;
	}
	if ((*s1 == '\0' && *s2 != '\0') || (*s1 != '\0' && *s2 == '\0'))
		return (false);
	return (true);
}

void	skip_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}
