/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nest_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:19:14 by slight            #+#    #+#             */
/*   Updated: 2021/12/07 17:05:00 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

char	*check_ostatok(char ***ostatok, char **p_n)
{
	char	*res;

	res = NULL;
	*p_n = ft_strchr(**ostatok, '\n');
	if (*p_n)
	{
		**p_n = '\0';
		res = ft_strdup(**ostatok);
		++(*p_n);
		**ostatok = ft_memcpy(**ostatok, *p_n, ft_strlen(*p_n));
	}
	else if (**ostatok != NULL)
	{
		res = ft_strdup(**ostatok);
		free(**ostatok);
		**ostatok = NULL;
	}
	else
	{
		res = malloc(sizeof(char));
		*res = '\0';
	}
	return (res);
}

char	*gnl2(char *buff, char **p_n, char **res, char ***ostatok)
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
			**ostatok = ft_strdup(*p_n);
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

char	*get_line(int fd, char **ostatok)
{
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
		if (was_read <= 0)
		{
			if (ft_strlen(res) == 0)
			{
				free(res);
				res = NULL;
			}
			free(buff);
			return (res);
		}
		buff[was_read] = '\0';
		res = gnl2(buff, &p_n, &res, &ostatok);
	}
	free(buff);
	res[ft_strlen(res)] = '\n';
	return (res);
}

t_gnl	*new_linked_list(int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->ostatok = NULL;
	new->next = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	char			*line;

	if (fd <= -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (head == NULL)
		head = new_linked_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_linked_list(fd);
		printf("%s\n", "here");
		tmp = tmp->next;
	}
	line = get_line(tmp->fd, &tmp->ostatok);
	printf("line : %s\n", line);
	printf("ostatok : %s\n", tmp->ostatok);
	if (line == NULL)
		if (tmp->ostatok == NULL)
				free(tmp);
	return (line);
}
