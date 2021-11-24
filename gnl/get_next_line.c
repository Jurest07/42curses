/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:47:31 by slight            #+#    #+#             */
/*   Updated: 2021/11/08 13:39:48 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 100
#include <stdio.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*dst;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		dst[i] = s[i];
		++i;
		--n;
	}
	return (dst);
}

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
			ft_memcpy(ost, ++p_n, ft_strlen(p_n) + 1);
		}
		else
		{
			*line = ft_strdup(ost);
			free(ost);
		}
	}
	else
	{
		*line = (char *)malloc(sizeof(char));
		line[0] = '\0';
	}
	return (p_n);
}

void	clounada1(char **ost, int fd, t_string *t, char **buff)
{
	if (!(*t).p_n)
		(*t).was_read = read(fd, *buff, BUFFER_SIZE);
	if ((*t).was_read < 0)
		return ;
	while (!(*t).p_n && (*t).was_read)// нет проверки на валидность fd
	{
		*buff[(*t).was_read] = '\0';
		(*t).p_n = ft_strchr(*buff, '\n');
		if ((*t).p_n)
		{
			(*t).p_n = '\0';
			ost = ft_strdup(++((*t).p_n));
		}
		(*t).tmp = (*t).line;
		(*t).line = ft_strjoin((*t).line, *buff);
		free((*t).tmp);
		if (!(*t).p_n)
			(*t).was_read = read(fd, *buff, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*ost;
	t_string	t;
	char		buff[BUFFER_SIZE + 1];

	t.p_n = check_ost(ost, &(t.line));
	clounada1(&ost, fd, &t, &buff)
	if (t.p_n)
		t.line = ft_strjoin(t.line, "\n");
	return (t.line);
}

int	main(void)
{
	int	fd;
	char *line;

//	fd = open("test.txt", O_RDONLY);
	fd = 1;
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}
