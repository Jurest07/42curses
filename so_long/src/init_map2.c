/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:06:06 by slight            #+#    #+#             */
/*   Updated: 2022/03/26 17:55:35 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	fill_map(char *str, t_gamestatus *status)
{
	t_iters	iters;

	init_iters(&iters);
	status->map = malloc(sizeof(char *) * status->width);
	if (status->map == NULL)
		die("Unable to allocate memory for the map! Retry.", 0, status->emptyp);
	while (iters.i < status->width)
	{
		status->map[iters.i] = malloc(sizeof(char) * (status->height + 1));
		if (status->map[iters.i] == NULL)
			die("Unable to allocate memory for the map! Retry.",
				0, status->emptyp);
		++iters.i;
	}
	while (str[iters.j])
	{
		while (str[iters.j] != '\n' && str[iters.j])
			status->map[iters.k][iters.l++] = str[iters.j++];
		status->map[iters.k++][iters.l] = '\0';
		iters.l = 0;
		if (str[iters.j] != '\0')
			++iters.j;
	}
}
