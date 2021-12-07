/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:06:00 by slight            #+#    #+#             */
/*   Updated: 2021/12/07 16:23:01 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <string.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("41_with_nl", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	fd2 = open("42_with_nl", O_RDONLY);
	line = get_next_line(fd2);
	printf("%s", line);
	fd3 = open("43_no_nl", O_RDONLY);
	line = get_next_line(fd3);
	printf("%s", line);
	line = get_next_line(fd2);
	printf("%s", line);
	return (0);
}
