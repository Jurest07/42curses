/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:02:29 by slight            #+#    #+#             */
/*   Updated: 2022/03/12 20:05:52 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	check_need_chars(char *str, t_gamestatus *status)
{
	t_iters	iters;

	init_iters(&iters);
	while (str[iters.i])
	{
		if (str[iters.i] == 'C' || str[iters.i] == 'c')
			++status->count_c;
		if (str[iters.i] == 'P' || str[iters.i] == 'p')
			++status->count_p;
		if (str[iters.i] == 'E' || str[iters.i] == 'e')
			++status->count_e;
		++iters.i;
	}
	if (status->count_c == 0)
		die("На карте нет предматов для сбора! Повторите попытку.", 0);
	if (status->count_p == 0)
		die("На карте нет игрока! Повторите попытку.", 0);
	if (status->count_e == 0)
		die("На карте нет выхода! Повторите попытку.", 0);
	if (status->count_p != 1)
		die("Невозможно определить положение игрока! Повторите попытку.", 0);
}

void	isvalidchars(char *str, t_gamestatus *status)
{
	t_iters	iters;

	init_iters(&iters);
	while (str[iters.i] != '\0')
		if (!ft_strchr(VALIDCHARS, str[(iters.i++)]))
			die("Недопустимые символы в карте! Повторите попытку.", 0);
	while (str[iters.j] != '\n')
		if (str[(iters.j)++] != '1')
			die("Карта не окружена стеной! Повторите потупку.", 0);
	while (iters.k < ft_strlen(str))
	{
		while (str[iters.k] != '\n' && str[iters.k] != '\0')
			++iters.k;
		if (str[iters.k] == '\0' && str[iters.k - 1] == '1')
			break ;
		if (str[iters.k - 1] != '1' || str[iters.k + 1] != '1')
			die("Карта не окружена стеной! Повторите потупку.", 0);
		++iters.k;
	}
	while (str[--iters.k] != '\n')
		if (str[iters.k] != '1')
			die("Карта не окружена стеной! Повторите потупку.", 0);
	check_need_chars(str, status);
}

int	isrectangle(int x, int y, char *str)
{
	t_iters	iters;

	init_iters(&iters);
	while (iters.j < y)
	{
		while (str[iters.k + iters.l] != '\n' && str[iters.k + iters.l])
			++(iters.k);
		if (iters.k != x)
			return (FALSE);
		iters.l = iters.l + x + 1;
		iters.k = 0;
		++(iters.j);
	}
	return (TRUE);
}

void	create_map(int fd, t_gamestatus *status)
{
	char	*str;
	int		was_read;

	str = (char *)malloc(sizeof(*str) * (status->count_press + 1));
	was_read = read(fd, str, status->count_chars);
	str[status->count_chars] = '\0';
	isvalidchars(str, status);
	while (str[status->height] != '\n')
		++(status->height);
	while (str[status->iter])
		if (str[status->iter++] == '\n')
			++(status->width);
	if (str[status->iter - 1] != '\n')
		++(status->width);
	if (!isrectangle(status->height, status->width, str))
		die("Карта не является прямоугольником! Повторите попытку.", 0);
	fill_map(str, status);
	free(str);
}

void	parse_map(char *map, t_gamestatus *status)
{
	int		fd;
	char	buff[1024];
	int		was_read;

	fd = open(map, O_RDONLY);
	was_read = read(fd, buff, 1024);
	if (was_read < 0)
		die("Невозможно прочитать файл! Повторите попытку.", 0);
	while (was_read == 1024)
	{
		status->count_chars += was_read;
		was_read = read(fd, buff, 1024);
	}
	status->count_chars += was_read;
	close(fd);
	fd = open(map, O_RDONLY);
	create_map(fd, status);
}
