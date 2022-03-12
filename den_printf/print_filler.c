/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 03:04:51 by lis               #+#    #+#             */
/*   Updated: 2022/01/11 01:56:50 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "accessory.h"
#include "libft/libft.h"

static t_bool	is_zero(t_place const *pl)
{
	return ((ft_strchr("uidxX", pl->fmt) && pl->flags & ZERO_PADDED)
		&& (!ft_strchr("xX", pl->fmt) || pl->prec < 0));
}

/*
 * stage = 0 - before sign and before number
 * stage = 1 - after sign and before number
 * stage = 2 - after sign and after number
 *
 * stage   0 1 2 0 1 2 0 1 2 0 1 2 
 * leftadj 0 0 0 0 0 0 1 1 1 1 1 1
 * zero    0 0 0 1 1 1 0 0 0 1 1 1 
 * result  S - - - 0 - - - S - - S
 */
int	print_filler(int fd, t_place const *pl, int stg)
{
	int		i;
	int		ret;
	int		sum;
	char	c;
	int		left_adj;

	left_adj = pl->flags & LEFT_ADJUSTED;
	if ((stg == 2 && left_adj) || (stg == 0 && !left_adj && !is_zero(pl)))
		c = ' ';
	else if (stg == 1 && !left_adj && is_zero(pl))
		c = '0';
	else
		return (0);
	i = 0;
	sum = 0;
	while (i < pl->minwidth - pl->sftwidth)
	{
		ret = write(fd, &c, 1);
		if (ret < 0)
			return (-1);
		sum += ret;
		++i;
	}
	return (sum);
}
