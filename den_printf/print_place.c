/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <lis@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:32:29 by lis               #+#    #+#             */
/*   Updated: 2022/01/11 14:38:30 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "accessory.h"
#include "libft/libft.h"

static int	print_sign(int fd, t_place const *pl)
{
	if (ft_strchr("idxXp", pl->fmt))
	{
		if (!ft_strchr("xXp", pl->fmt) && pl->v.i < 0)
			return (write(fd, "-", 1));
		if (!ft_strchr("xXp", pl->fmt) && pl->flags & SIGN_BEFORE)
			return (write(fd, "+", 1));
		if (!ft_strchr("xX", pl->fmt) && pl->flags & SPACE_BEFORE)
			return (write(fd, " ", 1));
	}
	return (0);
}

static int	print_prfx(int fd, t_place const *pl)
{
	int	sum;
	int	i;

	sum = 0;
	if (
		(pl->fmt == 'p' && !addret(write(fd, "0x", 2), &sum))
		|| (pl->flags & SPECIAL_FORMAT && (
				(pl->fmt == 'x' && pl->v.u && !addret(write(fd, "0x", 2), &sum))
				|| (pl->fmt == 'X' && pl->v.u
					&& !addret(write(fd, "0X", 2), &sum))))
	)
		return (-1);
	if (ft_strchr("uidxX", pl->fmt))
	{
		i = 0;
		while (i < pl->prec - pl->rigwidth)
		{
			if (!addret(write(fd, "0", 1), &sum))
				return (-1);
			++i;
		}
	}
	return (sum);
}

static int	print_spaces(int fd, int count)
{
	int	sum;

	sum = 0;
	while (count--)
	{
		if (!addret(write(fd, " ", 1), &sum))
			return (-1);
	}
	return (sum);
}

static int	print_value(int fd, t_place const *pl)
{
	if (pl->fmt == 'c')
		return (write(fd, &pl->v.c, 1));
	if (pl->fmt == 's')
	{
		if (!pl->v.s && (pl->prec < 0 || pl->prec > 5))
			return (write(fd, "(null)", 6));
		if (!pl->v.s)
			return (print_spaces(fd, pl->prec));
		if (pl->prec < 0)
			return (write(fd, pl->v.s, ft_strlen(pl->v.s)));
		return (write(fd, pl->v.s, min_i(ft_strlen(pl->v.s), pl->prec)));
	}
	else
		return (print_integer(fd, pl));
}

int	print_place(int fd, t_place *pl, va_list args)
{
	int	sum;

	sum = 0;
	extract_value(pl, args);
	calculate_width_params(pl);
	if (
		!addret(print_filler(fd, pl, 0), &sum)
		|| !addret(print_sign(fd, pl), &sum)
		|| !addret(print_prfx(fd, pl), &sum)
		|| !addret(print_filler(fd, pl, 1), &sum)
		|| !addret(print_value(fd, pl), &sum)
		|| !addret(print_filler(fd, pl, 2), &sum)
	)
		return (-1);
	return (sum);
}
