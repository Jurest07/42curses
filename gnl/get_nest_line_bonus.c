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

#define BUFFER_SIZE 100
#include <stdio.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include <string.h>

char	*check_ost(char *ost, char **line)
{
	char	*p_n;
	
	p_n = NULL;
	if (ost)
	{
		if ((p_n = ft_strchr(ost, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++p_n);
		}
		else
		{
			*line = ft_strdup(ost);
			free(ost);	
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

char	*get_line(int fd, char **ost)
{
	char		*line;
	t_string	t;
	char		buff[BUFFER_SIZE + 1];

	t.p_n = check_ost(*ost, &line);
	while (!t.p_n && (t.was_read = read(fd, buff, BUFFER_SIZE)))// нет проверки на валидность was_read
	{
		buff[t.was_read] = '\0';
		if ((t.p_n = ft_strchr(buff, '\n')))
		{
			*(t.p_n) = '\0';
			*ost = ft_strdup(++(t.p_n));
		}
		t.tmp = line;
		line = ft_strjoin(line, buff);
		free(line);
	}
	if (t.p_n)
		line = ft_strjoin(line, "\n");
	return (line);
}

GNL		*new_linked_list(int fd)
{
	GNL	*new;
	new = (GNL *)malloc(sizeof(GNL));
	new->fd = fd;
	new->ost = NULL;
	new->next = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static GNL	*head;
	GNL			*tmp;
	char		*line;
	
	if (head == NULL)
		head = new_linked_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_linked_list(fd);
		tmp = tmp->next;
	}
	line = get_line(tmp->fd, &tmp->ost);
	return (line);
}

int	main(void)
{
	int	fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}
