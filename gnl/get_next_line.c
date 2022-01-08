/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:47:31 by slight            #+#    #+#             */
/*   Updated: 2021/12/07 15:21:34 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <string.h>

char	*check_ostatok(char **ostatok, char **p_n)
{
	char	*res;

	res = NULL;
	*p_n = ft_strchr(*ostatok, '\n');
	if (*p_n)
	{
		**p_n = '\0';
		res = ft_strdup(*ostatok);
		++(*p_n);
		*ostatok = ft_memcpy(*ostatok, *p_n, ft_strlen(*p_n));
	}
	else if (*ostatok != NULL)
	{
		res = ft_strdup(*ostatok);
		free(*ostatok);
		*ostatok = NULL;
	}
	else
	{
		res = malloc(sizeof(char));
		*res = '\0';
	}
	return (res);
}

char	*gnl2(char *buff, char **p_n, char **res, char **ostatok)
{
	char	*tmp;

	*p_n = ft_strchr(buff, '\n');
	if (*p_n)
	{
		**p_n = '\0';
		tmp = *res;
		*res = ft_strjoin(*res, buff);
		free(tmp);
		if (BUFFER_SIZE != 1)
		{
			++(*p_n);
			*ostatok = ft_strdup(*p_n);
		}
	}
	else
	{
		tmp = *res;
		*res = ft_strjoin(*res, buff);
		free(tmp);
	}
	return (*res);
}

int	check_fd(int was_read, char **res, char **buff)
{
	if (was_read <= 0)
		{
			if (ft_strlen(*res) == 0)
			{
				free(*res);
				*res = NULL;
			}
			free(*buff);
			return (0);
		}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*ostatok = NULL;
	char		*res;
	char		*buff;
	char		*p_n;
	int			was_read;

	p_n = NULL;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = check_ostatok(&ostatok, &p_n);
	while (p_n == NULL)
	{
		was_read = read(fd, buff, BUFFER_SIZE);
		if (!check_fd(was_read, &res, &buff))
			return (res);
		buff[was_read] = '\0';
		res = gnl2(buff, &p_n, &res, &ostatok);
	}
	free(buff);
	res[ft_strlen(res)] = '\n';
	return (res);
}
