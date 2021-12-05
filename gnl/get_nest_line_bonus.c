/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nest_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:19:14 by slight            #+#    #+#             */
/*   Updated: 2021/11/08 13:21:32 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <string.h>

char	*check_ostatok(char *ostatok, char **p_n)
{
	char	*res;
	char	*free_ost;

	res = NULL;
	*p_n = ft_strchr(ostatok, '\n');
	if (*p_n)
	{
		**p_n = '\0';
		res = ft_strdup(ostatok);
		++(*p_n);
		ostatok = ft_memcpy(ostatok, *p_n, ft_strlen(*p_n));
	}
	else if (ostatok != NULL)
	{
		res = ft_strdup(ostatok);
		free(ostatok);
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
		*ostatok = ft_strdup(++(*p_n));
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
	res = check_ostatok(*ostatok, &p_n);
	while(p_n == NULL)
	{
		was_read = read(fd, buff, BUFFER_SIZE);
		if (was_read <= 0)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		res = gnl2(buff, &p_n, &res, &(*ostatok));
	}
	p_n = ft_strchr(res, '\0');
	*p_n = '\n';
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
	
	if (head == NULL)
		head = new_linked_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_linked_list(fd);
		tmp = tmp->next;
	}
	line = get_line(tmp->fd, &tmp->ostatok);
	return (line);
}

int	main(void)
{
	int	fd1;
	int	fd2;
	char *line;

	fd1 = open("test.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	fd2 = open("test2.txt", O_RDONLY);
	line = get_next_line(fd2);
	printf("%s", line);
	line = get_next_line(fd2);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
}
