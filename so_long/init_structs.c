/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:06:55 by slight            #+#    #+#             */
/*   Updated: 2022/03/12 20:06:56 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_strchr(const char *s, int c)
{
	while (c > 256)
		c = c - 256;
	while (*s)
	{
		if (*s == c)
			return (TRUE);
		s++;
	}
	if (*s == c)
		return (TRUE);
	return (FALSE);
}

void	init_gamestatus(t_gamestatus *status)
{
	status->map = NULL;
	status->width = 0;
	status->height = 0;
	status->iter = 0;
	status->count_c = 0;
	status->count_p = 0;
	status->count_e = 0;
	status->count_chars = 0;
	status->count_press = 0;
}

void	init_iters(t_iters *iters)
{
	iters->i = 0;
	iters->j = 0;
	iters->k = 0;
	iters->l = 0;
}
